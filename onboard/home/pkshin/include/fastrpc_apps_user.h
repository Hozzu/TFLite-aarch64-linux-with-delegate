/*
 * Copyright (c) 2012-2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc
 */
#ifndef FASTRPC_ANDROID_USER_H
#define FASTRPC_ANDROID_USER_H

#include <assert.h>
#include <fcntl.h>
#include <asm/ioctl.h>
#include <errno.h>

/*
 * Enum defined for fastrpc User Properties
 * @fastrpc_properties: Object of enum
 * Enum values corresponds to array indices
 *
 */
 typedef enum {
	 FASTRPC_PROCESS_ATTRS = 0, //to spawn a User process as Critical
	 FASTRPC_DEBUG_TRACE = 1, // to enable logs on remote invocation
	 FASTRPC_DEBUG_TESTSIG = 2, // to get process test signature
	 FASTRPC_PERF_KERNEL = 3, //to enable rpc perf on fastrpc kernel
	 FASTRPC_PERF_ADSP = 4, //to enable rpc perf on DSP
	 FASTRPC_PERF_FREQ = 5, //to set performance frequency
	 FASTRPC_ENABLE_SYSTRACE = 6, //to enable tracing using Systrace
 }fastrpc_properties;

/*
 * API to check if kernel supports remote memory allocation
 * Returns 0 if NOT supported
 *
 */
int is_kernel_alloc_supported(int dev, int domain);

/*
 * API to allocate ION memory for internal purposes
 * Returns NULL if allocation fails
 *
 */
void* rpcmem_alloc_internal(int heapid, uint32 flags, int size);

/*
 * API to free internally allocated ION memory
 *
 */
void rpcmem_free_internal(void* po);

/*
 * API to get fd of internally allocated ION buffer
 * Returns valid fd on success and -1 on failure
 *
 */
int rpcmem_to_fd_internal(void *po);

// API to get domain from handle
int get_domain_from_handle(remote_handle64 local, int *domain);

/*
 * API to get User property values where value type corresponds to integer
 * @UserPropertyKey: [in] Value(enum type) that corresponds to array index of User property string
 * @defValue: [in] default value returned when user property is not set
 * On user property set, returns user value. Else, returns default value
 *
 */
int fastrpc_get_property_int(fastrpc_properties UserPropertyKey, int defValue);

/*
 * API to get User property values where value type corresponds to string
 * @UserPropertyKey: [in] Value(enum type) that corresponds to array index of User property string
 * @value: [out] Pointer to the User set string
 * @defValue: [in] default value returned when user property is not set
 * returns the length of the value which will never be
 * greater than PROPERTY_VALUE_MAX - 1 and will always be zero terminated.
 *
 */
int fastrpc_get_property_string(fastrpc_properties UserPropertyKey, char * value, char * defValue);

#endif //FASTRPC_ANDROID_USER_H
