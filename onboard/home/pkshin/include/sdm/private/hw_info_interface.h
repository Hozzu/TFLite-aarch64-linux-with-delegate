/*
* Copyright (c) 2014 - 2016, 2018, 2020 The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted
* provided that the following conditions are met:
*    * Redistributions of source code must retain the above copyright notice, this list of
*      conditions and the following disclaimer.
*    * Redistributions in binary form must reproduce the above copyright notice, this list of
*      conditions and the following disclaimer in the documentation and/or other materials provided
*      with the distribution.
*    * Neither the name of The Linux Foundation nor the names of its contributors may be used to
*      endorse or promote products derived from this software without specific prior written
*      permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __HW_INFO_INTERFACE_H__
#define __HW_INFO_INTERFACE_H__

#include <inttypes.h>
#include <core/core_interface.h>
#include <private/hw_info_types.h>

namespace sdm {

class HWInfoInterface {
 public:
  static DisplayError Create(HWInfoInterface **intf);
  static DisplayError Destroy(HWInfoInterface *intf);
  virtual DisplayError Init() = 0;
  virtual DisplayError GetHWResourceInfo(HWResourceInfo *hw_resource) = 0;
  virtual DisplayError GetFirstDisplayInterfaceType(HWDisplayInterfaceInfo *hw_disp_info) = 0;
  virtual DisplayError GetDisplaysStatus(HWDisplaysInfo *hw_displays_info) = 0;
  virtual DisplayError GetMaxDisplaysSupported(DisplayType type, int32_t *max_displays) = 0;
  virtual DisplayError GetPipesStatus(HWPipesStateInfo *hw_pipes_info, bool update) = 0;
  virtual DisplayError SetPipeHandoff(uint32_t pipe_id) = 0;

 protected:
  virtual ~HWInfoInterface() { }
};

}  // namespace sdm

#endif  // __HW_INFO_INTERFACE_H__

