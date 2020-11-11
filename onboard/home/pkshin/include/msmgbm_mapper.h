//**************************************************************************************************
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//**************************************************************************************************

#ifndef __MSMGBM_MAPPER_H__
#define __MSMGBM_MAPPER_H__

#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <memory>
#include <cstdio>
#include <string.h>
#include "gbm_priv.h"
#include "msmgbm.h"

namespace msm_gbm {

class msmgbm_mapper {
 public:
  msmgbm_mapper();
  ~msmgbm_mapper();
  bool init();

  //Structure definition to maintain hash table on a per process basis
  //to manage metadata.
  struct msmgbm_buffer {
      int ion_fd;
      int ion_metadata_fd;
      uint32_t width;
      uint32_t height;
      uint32_t format;
      int ref_count=0;
      void *cpuaddr = NULL;
      void *mt_cpuaddr = NULL;
      struct msmgbm_iova_info iova_info[GBM_CLIENT_TYPE_MAX];

      explicit msmgbm_buffer(int fd, int mtadta_fd, uint32_t wdth, uint32_t hght, uint32_t fmt,
                         void *cpu_addr, void *mt_cpu_addr, struct msmgbm_iova_info *iova_info):
          ion_fd(fd),
          ion_metadata_fd(mtadta_fd),
          width(wdth),
          height(hght),
          format(fmt),
          cpuaddr(cpu_addr),
          mt_cpuaddr(mt_cpu_addr) {
              memcpy(&this->iova_info, iova_info, sizeof(this->iova_info));
          }

      void IncRef() {++ref_count;}
      int  DecRef() {return --ref_count == 0;}
  };

  std::unordered_map<int, std::shared_ptr<msmgbm_buffer>>gbm_buf_map_;

  struct gem_handle_key {
	int device_fd;
	uint32_t handle;
	gem_handle_key(int device_fd, uint32_t handle) : device_fd(device_fd), handle(handle){}
  };

  struct HashFunc {
	std::size_t operator()(const gem_handle_key &key) const
	{
		using std::size_t;
		using std::hash;

		return ((hash<int>()(key.device_fd)
			^ (hash<uint32_t>()(key.handle) << 1)) >> 1);
	}
  };
  struct EqualKey {
	bool operator () (const gem_handle_key &key1, const gem_handle_key &key2) const
	{
		return key1.device_fd == key2.device_fd && key1.handle == key2.handle;
	}
  };

  std::unordered_map<gem_handle_key, int, HashFunc, EqualKey>gem_object_map_;
  void register_to_map(int ion_fd, struct gbm_buf_info * gbm_buf,
                                       struct msmgbm_private_info * gbo_private_info);
  int search_map(int ion_fd, struct gbm_buf_info * gbm_buf,
                                struct msmgbm_private_info * gbo_private_info);
  int update_map(int ion_fd, struct gbm_buf_info * gbm_buf,
                                struct msmgbm_private_info * gbo_private_info);
  void map_dump(void);
  void add_map_entry(int ion_fd);
  int  del_map_entry(int ion_fd);
  void  incr_handle_refcnt(int device_fd, uint32_t handle);
  int  decr_handle_refcnt(int device_fd, uint32_t handle);

};

}  // namespace msm_gbm

#endif  // __MSMGBM_MAPPER_H__
