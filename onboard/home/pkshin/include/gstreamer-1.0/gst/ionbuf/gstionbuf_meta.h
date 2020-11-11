/*
 * Copyright (c) 2016-2017, 2019, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
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
 * (IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __GSTIONBUF_META_H__
#define __GSTIONBUF_META_H__

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gst/gst.h>
#include <gst/video/gstvideometa.h>
#include <config.h>
G_BEGIN_DECLS

#ifndef GST_IONBUF_BAD_API
# ifdef BUILDING_GST_IONBUF_BAD
#  define GST_IONBUF_BAD_API GST_API_EXPORT         /* from config.h */
# else
#  define GST_IONBUF_BAD_API GST_API_IMPORT
# endif
#endif

struct _GstIonBufFdMeta {
  GstMeta meta;
  /** ion buffer file descriptor */
  /**MSM 8996: Update type of "fd" to correct "signed int" type to support the
   * new updates at msm-omx decoder.
  */
  int fd;
  /** Offset from ion buffer base address */
  unsigned int offset;
  /** Size of ion buffer */
  unsigned int size;
  /** ubwc flag **/
  gboolean ubwc;

#ifdef USE_GBM
  int meta_fd;
  unsigned int width;
  unsigned int height;
  unsigned int format;
#endif
};

typedef struct _GstIonBufFdMeta GstIonBufFdMeta;
GST_IONBUF_BAD_API
GType gst_ionBufFd_meta_api_get_type (void);
GST_IONBUF_BAD_API
const GstMetaInfo * gst_ionBufFd_meta_get_info (void);

#define ION_BUF_FD_META_API_TYPE (gst_ionBufFd_meta_api_get_type())
#define gst_buffer_get_ionfd_meta(b)		\
  ((GstIonBufFdMeta*)gst_buffer_get_meta((b),ION_BUF_FD_META_API_TYPE))
#define ION_BUF_FD_META_INFO (gst_ionBufFd_meta_get_info ())

#ifdef USE_GBM
GST_IONBUF_BAD_API
GstIonBufFdMeta *
gst_buffer_add_ionbuf_meta(GstBuffer * buffer, int fd, unsigned int offset, unsigned int size, gboolean ubwc, int meta_fd, unsigned int width, unsigned int height, unsigned int format);
#else
/**MSM 8996: Update type of "fd" to correct "signed int" type to support the
  * new updates at msm-omx decoder.
*/
GST_IONBUF_BAD_API
GstIonBufFdMeta * gst_buffer_add_ionbuf_meta (GstBuffer * buffer,
                                               int fd, unsigned int offset, unsigned int size, gboolean ubwc);
#endif


G_END_DECLS

#endif /* __GSTIONBUF_META_H__ */
