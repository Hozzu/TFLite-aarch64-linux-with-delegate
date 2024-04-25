/*
* Copyright (c) 2020, The Linux Foundation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*  * Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above
*    copyright notice, this list of conditions and the following
*    disclaimer in the documentation and/or other materials provided
*    with the distribution.
*  * Neither the name of The Linux Foundation nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
* ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
* IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __NOTIFIER_INTERFACE_H__
#define __NOTIFIER_INTERFACE_H__

#include <core/sdm_types.h>

namespace sdm {

/*! @brief Notifier interface.

  @details This class defines notifier interface. It contains methods which client shall use
  to notify compositor when external event happens.

  @sa CoreInterface::GetNotifierInterface
*/
class NotifierInterface {
 public:
  virtual ~NotifierInterface() { }

   /*! @brief Method to notify changes on pipes state

     @return \link DisplayError \endlink
   */
  virtual DisplayError PipesStateChanged(void) = 0;

   /*! @brief Method to notify changes on pipes availability

     @return \link DisplayError \endlink
   */
  virtual DisplayError PipesAvailabilityChanged(void) = 0;

   /*! @brief Method to notify a paticular type of pipe is requested to handoff

     @param[in] id Pipe id to be handed off
     @return \link DisplayError \endlink
   */
  virtual DisplayError PipeHandoffRequested(int32_t id) = 0;
};

}  // namespace sdm

#endif  // __NOTIFIER_INTERFACE_H__