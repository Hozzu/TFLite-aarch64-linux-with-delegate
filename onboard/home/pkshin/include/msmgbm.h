//**************************************************************************************************
// Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//**************************************************************************************************

#ifndef _MSM_GBM_H_
#define _MSM_GBM_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

//Enables debug log
#ifdef GBM_DEBUG
    #define  GBM_DBG_LOG fprintf
#else
    #define  GBM_DBG_LOG(...) {}
#endif

#define LOG_FATAL    (1)
#define LOG_ERR      (2)
#define LOG_WARN     (3)
#define LOG_INFO     (4)
#define LOG_DBG      (5)

extern int  g_debug_level;

#define LOG(level, ...) do {  \
                            if (level <= g_debug_level) { \
                                if(level==LOG_FATAL) \
                                  fprintf(stderr,"%s","GBM_FATAL::"); \
                                if(level==LOG_ERR) \
                                  fprintf(stderr,"%s", "GBM_ERR::"); \
                                if(level==LOG_WARN) \
                                  fprintf(stderr,"%s", "GBM_WARN::"); \
                                if(level==LOG_INFO) \
                                  fprintf(stderr,"%s", "GBM_INFO::"); \
                                if(level==LOG_DBG) \
                                  fprintf(stderr,"%s", "GBM_DBG::"); \
                                fprintf(stderr,"%s(%d)::",__func__,__LINE__); \
                                fprintf(stderr, __VA_ARGS__); \
                                fprintf(stderr, "\n"); \
                                fflush(stderr); \
                            } \
                        } while (0)




/*Currently three buffer mechanism is used for GPU rendering and Hardware Composition sync*/
#define NUM_BACK_BUFFERS 3
#define MAX_NUM_PLANES 3
#define QCMAGIC 0XDFDFECBA // need to compe up with something unique



/**
* State representation of the gbm buffer object
*
*/
#define GBM_BO_STATE_FREE                       (0x0) /* Unused/Free state of the Buffer Object */

#define GBM_BO_STATE_INUSE_BY_COMPOSITOR        (0x1) /* Buffer Object locked for composition */

#define GBM_BO_STATE_INUSE_BY_GPU               (0x2) /* Buffer Object locked for GPU rendering */

#define GBM_BO_STATE_NEW_FRONT_BUFFER           (0x3) /* Buffer Object currently available for
                                                   * grab by GPU or Compositor */


/**
* State representation of the gbm buffer object during
* gbm surface creation if enabled
*
*/

#ifndef ALLOCATE_SURFACE_BO_AT_CREATION

#define SURFACE_BOSLOT_STATE_FREE                    (0x0) /* Unused/Free state of the Buffer Object */

#define SURFACE_BOSLOT_STATE_INUSE_BY_COMPOSITOR     (0x1) /* BO locked for composition */

#define SURFACE_BOSLOT_STATE_HAS_NEW_FRONT_BUFFER    (0x2) /* BO currently available for
                                                        * grab by GPU or Compositor */
#endif


/**
 * msm gbm device object corresponding to the gbm device object instance
 *
 * The members in this structure should not be accessed directly.
 */

struct msmgbm_device {
   struct gbm_device base;
   uint32_t magic;
   int fd;  /* device fd */
   int iondev_fd;  /* ION device fd */
   struct gbm_callback_funcs funcs;
};

struct msmgbm_surface {
   struct gbm_surface base;
   uint32_t magic;
   struct msmgbm_device* device;
   struct msmgbm_bo *bo[NUM_BACK_BUFFERS];
#ifndef ALLOCATE_SURFACE_BO_AT_CREATION
   int bo_slot[NUM_BACK_BUFFERS];
#endif
};

/**
 * The allocated local msm buffer object for the corresponding gbm buffer object.
 *
 * The members in this structure should not be accessed directly.
 */
struct msmgbm_bo {
   struct gbm_bo base;
   uint32_t magic;
   struct msmgbm_device* device;
   uint32_t numplanes;
   size_t offset;
   uint32_t name;
   uint64_t gpuaddr;
   void* cpuaddr;
   void* mt_cpuaddr;
   size_t size;
   size_t mt_size;
   uint32_t current_state;
   uint32_t fbid;
   int ion_handle;
   int import_flg;
};


/**
 * Buffer Descriptor used for param passing between API's
 *
 */
struct gbm_bufdesc {
    uint32_t Width;
    uint32_t Height;
    uint32_t Format;
    uint32_t Usage;
};

struct gbm_buf_resource {
  struct gbm_buf_info *buffer_info;
  uint32_t magic;
};

struct msmgbm_iova_info {
   uint64_t iova;     /* gbm bo io virtual address */
   void* cb_data;     /* the private data of GBM client */
   uint32_t cb_size;  /* size of the above data */
};

/**
 * The gbm buffer data object related
 * information stored in hashmap
 */
struct msmgbm_private_info {
   void* cpuaddr;           /* gbm bo cpu address */
   void* mt_cpuaddr;        /* gbm bo meta data address */
   struct msmgbm_iova_info iova_info[GBM_CLIENT_TYPE_MAX]; /* io virtual address information */
};

/*
* Function prototypes of all supported API's by backend
*
*/

/** create the gbm bo
 *
 * \param handle to gbm device
 * \param width
 * \param height
 * \param format
 * \param usage flag
 * \return gbm bo handle
 *
 */
static struct gbm_bo *msmgbm_bo_create(struct gbm_device *gbm,uint32_t width,
                                   uint32_t height,uint32_t format, uint32_t usage);


/** Destroy the gbm bo
 *
 * \param bo The buffer object
 * \return None
 *
 */
static void msmgbm_bo_destroy(struct gbm_bo *bo);

/** To query gbm device pointer
 *
 * \param bo The buffer object
 * \return gbm device handle
 *
 */
static struct gbm_device* msmgbm_bo_get_device(struct gbm_bo *bo);

/** query gbm bo name
 *
 * \param gbm bo handle
 * \return id
 *
 */
int msmgbm_bo_get_name(struct gbm_bo* bo);

/** Returns the modifier of the buffer object
 *
 * \param bo The buffer object
 * \return Returns modifier to indicate tiling, compress of the buffer
 */
uint64_t msmgbm_bo_get_modifier(struct gbm_bo* bo);

/** Perform write operation onto the gbm bo
 *
 * \param bo The buffer object
 * \param user buffer handle
 * \param byte count
 * \return =0 for success
 *         >0 for fail
 *
 */
static int msmgbm_bo_write(struct gbm_bo *bo, const void *buf, size_t count);

/** create the gbm bo
 *
 * \param import gbm bo handle depending on type
 * \param gbm device
 * \param type
 * \param void pointer
 * \param usage flag
 * \return gbm bo handle
 *
 */
struct gbm_bo * msmgbm_bo_import(struct gbm_device *gbm,uint32_t type,
                                                void *buffer, uint32_t usage);

/** Import gbm bo handle from fd
 *
 * \param handle to msmgbm_device
 * \param fd via void *
 * \param usage flags
 * \return gbm bo handle
 *
 */
struct gbm_bo * msmgbm_bo_import_fd(struct msmgbm_device *msm_dev,
                                                void *buffer, uint32_t usage);

/** Import gbm bo handle from name element of the wl buffer resource
 *
 * \param msmgbm_device handle
 * \param wl buffer handle
 * \param usage flag
 * \return gbm bo handle
 *
 */
struct gbm_bo * msmgbm_bo_import_wl_buffer(struct msmgbm_device *msm_dev,
                                                        void *buffer, uint32_t usage);

/** create the gbm bo
 *
 * \param msmgbm_device handle
 * \param egl buffer handle
 * \param usage flag
 * \return gbm bo handle
 *
 */
struct gbm_bo * msmgbm_bo_import_egl_image(struct msmgbm_device *msm_dev,
                                                        void *buffer, uint32_t usage);

/** create requested gbm surface with the dimensions
 *
 * \param gbm device handle
 * \param width
 * \param height
 * \param format
 * \param usage flag
 * \return gbm surface
 *
 */
static struct gbm_surface *
        msmgbm_surface_create(struct gbm_device *gbm,uint32_t width,
                                     uint32_t height,uint32_t format, uint32_t flags);

/** destroy gbm surface
 *
 * \param handle to gbm surface
 * \return None
 *
 */
static void msmgbm_surface_destroy(struct gbm_surface *surf);
/** Verifies if surface is allocated by MSM GBM backend
  *
  * \Returns GBM_ERROR values
  *
  */
static inline
int  msmgbm_validate_surface(struct gbm_surface *surf);
/** update the state of the current bo associated with the surface to used by compositor
 *
 * \param surface handle
 * \return gbm bo handle
 *
 */
static struct gbm_bo * msmgbm_surface_lock_front_buffer(struct gbm_surface *surf);
/** update the state of the current bo associated with the surface to free
 *
 * \param surface handle
 * \return gbm bo handle
 *
 */
static void msmgbm_surface_release_buffer(struct gbm_surface *surf,
                                                            struct gbm_bo *bo);
/* Returns bo which can be used as front buffer on success
  * \Returns GBM_ERROR values
  *
  */
struct gbm_bo* msmgbm_surface_get_free_bo(struct gbm_surface *surf);
/** update the state machine of a bo to be used as the surface front buffer
  * \Returns GBM_ERROR values
  *
  */
int msmgbm_surface_set_front_bo(struct gbm_surface *surf, struct gbm_bo *gbo);

/** Returns the CPU address of metadata
  * if fails returns NULL
  */
void* msmgbm_cpu_map_metafd(int meta_ion_fd, unsigned int metadata_size);
/** Returns the cpu address of non secure bo
  * if mmap fails or buffer is secure, returns NULL
  */
void* msmgbm_cpu_map_ionfd(int ion_fd, unsigned int size, struct meta_data_t *meta_data);
/** Returns the CPU access address for the BO buffer
  * \Returns  CPU address on Success / Null on fail
  *
  */

void * msmgbm_bo_cpu_map(struct gbm_bo *gbo);
/* Unmap the BO buffer from CPU access
  * \Returns GBM_ERROR values
  *
  */
int msmgbm_bo_cpu_unmap(struct gbm_bo *gbo);
/*  Returns BO size on success
  * \Returns  size on Success/ GBM_ERROR Values on Failure
  *
  */
static inline
size_t msmgbm_bo_get_size(struct gbm_bo *bo);
/** create gbm device
 *
 * \param  display driver device fd
 * \return gbm device handle
 *
 */
static struct gbm_device * msmgbm_device_create(int fd);
/** destroy the gbm device handle
 *
 * \param gbm device handle
 * \return none
 *
 */
static void msmgbm_device_destroy(struct gbm_device *gbm);
/** To query gbm device fd
 *
 * \param bo The buffer object
 * \return fd
 *
 */
static int msmgbm_device_get_fd(struct gbm_bo *bo);
/** query device unique id
 *
 * \param handle to gbm device
 * \return ID
 *
 */
unsigned int msmgbm_device_get_magic(struct gbm_device *dev);
/** query drm device file name
 *
 * \return gbm bo handle
 *
 */
static inline
const char*  msmgbm_drm_device_get_name(void);
/** Authenticate the DRM magic ID
  *
  * \Returns 0 on success
  * \Returns -1 on failure
  *
  */
int  msmgbm_device_authenticate_magic(struct gbm_device *dev,
                                                            uint32_t magic);
/** Import a BO handle from a unique ID/name
  *
  * \Returns imported BO pointer on success
  * \Returns NULL on failure
  *
  */
struct gbm_bo* msmgbm_bo_import_from_name(struct gbm_device *dev,
                                                            unsigned int name);
/** Returns global name on success
  *
  * \Returns GBM_ERROR values on failure
  *
  */
int msmgbm_bo_get_name(struct gbm_bo* bo);

/** Verifies if device is allocated by MSM GBM backend
  *
  * \Returns GBM_ERROR values
  *
  */
static inline
int msmgbm_validate_device(struct gbm_device *dev);
/** Query metadata info depending on the operation/paramtype
  *
  * \Returns GBM_ERROR values
  *
  */
int msmgbm_get_metadata(struct gbm_bo *gbo, int paramType,void *param);
/** Set metadata info depending on the operation/paramtype
  *
  * \Returns GBM_ERROR values
  *
  */
int msmgbm_set_metadata(struct gbm_bo *gbo, int paramType,void *param);

/** Get RGB Data Address for a given gbm buffer object
  *
  * \Returns GBM_ERROR values
  *
  */
int msmgbm_get_rgb_data_address(struct gbm_bo *gbo, void **rgb_data);

/** File read for debug level configuration */
void config_dbg_lvl(void);

/** dump bo info to a file
  *
  * \Returns GBM_ERROR values
  */
int msmgbm_bo_dump(struct gbm_bo * gbo);

/** Get yuv plane info
  *
  * \Returns GBM_ERROR values
  */
int msmgbm_yuv_plane_info(struct gbm_bo *gbo,generic_buf_layout_t *buf_lyt);

/** Get buffer layout info
  *
  * \Returns GBM_ERROR values
  */
int msmgbm_get_buf_lyout(struct gbm_bo *gbo, generic_buf_layout_t *buf_lyt);

/** Get default init hdr color meta data info
  *
  * \Returns GBM_ERROR values
  */
void msmsgbm_default_init_hdr_color_info_mdata(ColorMetaData * color_mdata);

/** log hdr color meta data info
  *
  * \Returns GBM_ERROR values
  */
void msmgbm_log_hdr_color_info_mdata(ColorMetaData * color_mdata);

/**
  * C wrapper function to create a cpp object of msmgbm mapper class
  * @input param: None
  * @return   0 : success
  *           1 : failure
  */
bool msmgbm_mapper_instnce(void);

/**
  * C wrapper function to delete msmsgbm mapper object
  * @input param: None
  * @return     : None
  *
  */
void msmgbm_mapper_deinstnce(void);

/**
  * C wrapper function to register to the hash map a gbm_buf_info indexed by an ion_fd
  * @input param: ion_fd , gbm_buf_info object handle
  * @return     : none
  *
  */
void register_to_hashmap(int fd, struct gbm_buf_info * gbm_buf,
                                       struct msmgbm_private_info * gbo_private_info);

/**
  * C wrapper function to search hash map using ion_fd and retrieve the gbm_buf_info
  * @input param: ion_fd , gbm_buf_info object handle
  * @return     : GBM error status
  *
  */
int search_hashmap(int fd, struct gbm_buf_info *buf_info,
                                struct msmgbm_private_info * gbo_private_info);

/**
  * C wrapper function to update hash map using ion_fd and retrieve the gbm_buf_info
  * @input param: ion_fd , gbm_buf_info object handle
  * @return     : GBM error status
  *
  */
int update_hashmap(int fd, struct gbm_buf_info *buf_info,
                                struct msmgbm_private_info * gbo_private_info);

/**
  * C wrapper function to dump hash map
  * @input param: void
  * @return     : none
  *
  */
void dump_hashmap(void);

/**
  * C wrapper function to decrement the reference count for the valid map entry
  * @input param: ion_fd
  * @return     : 1 for delete map entry /0 for decremented ref count
  *
  */
int decr_refcnt(int fd);

/**
  * C wrapper function to increment the reference count for the valid map entry
  * @input param: ion_fd
  * @return     : none
  *
  */
void incr_refcnt(int fd);

/**
  * C wrapper function to increment the reference count for the valid gem_handle
  * @input param: device fd
  * @input param: gem handle
  * @return     : none
  *
  */
void incr_handle_refcnt(int device_fd, uint32_t handle);

/**
  * C wrapper function to decrement the reference count for the valid map gem_handle
  * @input param: device fd
  * @input param: gem handle
  * @return     : 1 for delete key from map /0 for decremented ref count
  *
  */
int decr_handle_refcnt(int device_fd, uint32_t handle);


/**
  * C wrapper Function to get  aligned width and height depending on the underlying GPU/Video platform
  * @return    aligned_w
  *            aligned_h
  */
void qry_aligned_wdth_hght(struct gbm_bufdesc *descriptor, unsigned int *alignedw, unsigned int *alignedh);

/**
  * C wrapper Function to query size based on format from the platform wrapper
  * @return    size
  *
  */
unsigned int qry_size(struct gbm_bufdesc *desc, unsigned int alignedw, unsigned int alignedh);

/**
  * C wrapper Function to check whether the format is UBWC or not.
  * @params    gbm format
  * @return    boolean 0 (non UBWC format)
  *                    1 (UBWC format)
  */
bool is_valid_ubwc_format(int format);

/**
  * Function to return bytes per pixel for a given uncompressed RGB format
  * @params    uncompressed RGB gbm format
  * @return    bytes per pixel
  *
  */
uint32_t get_bpp_for_uncmprsd_rgb_format(int format);

/**
  * Function to return bytes needed to represent UBWC RGB Metabuffer
  * @params    RGB gbm format
  * @return    size of UBWC RGB meta buffer
  *
  */
uint32_t get_rgb_ubwc_metabuffer_size(int width, int height, int bpp);

/**
  * C wrapper Function to check whether the format is uncompressed RGB format or not.
  * @params    gbm format
  * @return    boolean 0 (compressed RGB format)
  *                    1 (uncompressed RGB format)
  */
bool is_valid_uncmprsd_rgb_format(int format);

/**
  * C wrapper Function to delete platform wrapper object
  * @return  : None
  *
  */
void platform_wrap_deinstnce(void);

/**
  * C wrapper Function to create a cpp object of platform wrapper class
  * @return   0 : success
  *           1 : failure
  */
bool platform_wrap_instnce(void);

/**
  * Function to check whether the format is UBWC or not from the platform wrapper
  * @params    gbm format
  * @params    int prod_usage
  * @params    int cons_usage
  * @return    boolean 0 (non UBWC format)
  *                    1 (UBWC format)
  */
bool is_ubwc_enabled(int format, int prod_usage, int cons_usage);

#ifdef __cplusplus
}
#endif

#endif //_MSM_GBM_H_

