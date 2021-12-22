/* ===========================================================================
 * Copyright (c) 2016-2020 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
=========================================================================== */

#ifndef _TEST_UTIL_H
#define _TEST_UTIL_H

#include "test_util_common.h"
#include "test_util_debug.h"

#include <list>

#define TESTUTIL_ALIGN(x, y) (((x) + ((y)-1)) & ~((y)-1))
#define TESTUTIL_ALIGN_TO_LOWER(x, y) ((x) & ~((y)-1))

struct test_util_ctxt_t;
typedef struct test_util_ctxt_t test_util_ctxt_t;

struct test_util_window_t;
typedef struct test_util_window_t test_util_window_t;

/// @brief information to do software deinterlace
typedef struct
{
    test_util_window_t *qcarcam_window;
    test_util_window_t *display_window;
    int source_buf_idx;
    qcarcam_field_t field_type;
} test_util_sw_di_t;

///////////////////////////////////////////////////////////////////////////////
/// test_util_init
///
/// @brief Initialize context that is to be used to display content on the screen.
///
/// @param ctxt   Pointer to context to be initialized
/// @param params Parameters to init ctxt
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_init(test_util_ctxt_t **ctxt, test_util_ctxt_params_t *params);

///////////////////////////////////////////////////////////////////////////////
/// test_util_deinit
///
/// @brief Destroy context and free memory.
///
/// @param ctxt   Pointer to context to be destroyed
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_deinit(test_util_ctxt_t *ctxt);

///////////////////////////////////////////////////////////////////////////////
/// test_util_init_window
///
/// @brief Initialize new window
///
/// @param ctxt             Pointer to test_util context
/// @param pp_window        Pointer to new window to be initialized
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_init_window(test_util_ctxt_t *ctxt, test_util_window_t **pp_window);

///////////////////////////////////////////////////////////////////////////////
/// test_util_deinit_window
///
/// @brief Destroy window
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_deinit_window(test_util_ctxt_t *ctxt, test_util_window_t *p_window);

///////////////////////////////////////////////////////////////////////////////
/// test_util_set_window_param
///
/// @brief Send window parameters to display
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param window_params    Pointer to structure with window properties
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_set_window_param(test_util_ctxt_t *ctxt, test_util_window_t *p_window, test_util_window_param_t *window_params);

///////////////////////////////////////////////////////////////////////////////
/// test_util_init_window_buffers
///
/// @brief Initialize buffers for display
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param buffers          Pointer to qcarcam buffers
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_init_window_buffers(test_util_ctxt_t *ctxt, test_util_window_t *p_window, qcarcam_buffers_t *buffers);

///////////////////////////////////////////////////////////////////////////////
/// test_util_deinit_window_buffer
///
/// @brief Destroy window buffers
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_deinit_window_buffer(test_util_ctxt_t *ctxt, test_util_window_t *p_window);

///////////////////////////////////////////////////////////////////////////////
/// test_util_post_window_buffer
///
/// @brief Send frame to display
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param idx              Buffer index
/// @param p_rel_buf_idx    List to fill with buffers ready to release
/// @param field_type       Field type in current frame buffer if interlaced
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_post_window_buffer(test_util_ctxt_t *ctxt, test_util_window_t *o_window, unsigned int idx, std::list<uint32>* p_rel_buf_idx, qcarcam_field_t field_type);

///////////////////////////////////////////////////////////////////////////////
/// test_util_dump_window_buffer
///
/// @brief Dump frame to a file
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param idx              Buffer idx
/// @param filename         Char pointer to file name to be dumped
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_dump_window_buffer(test_util_ctxt_t *ctxt, test_util_window_t *p_window, unsigned int idx, const char *filename);

///////////////////////////////////////////////////////////////////////////////
/// test_util_di_sw_weave_30fps
///
/// @brief Deinterlace 2 fields from souce buf into dest new frame with software weave 30fps method
///
/// @param di_info         Input souce/dest buffer context
/// @param test_util_get_buf_ptr_func    Helper func to get source/destination buffer virtual address
///
/// @return Void
///////////////////////////////////////////////////////////////////////////////
void test_util_di_sw_weave_30fps(test_util_sw_di_t *di_info);

///////////////////////////////////////////////////////////////////////////////
/// test_util_get_buf_ptr
///
/// @brief Get buffer virtual address
///
/// @param p_window       window
/// @param p_buf          pointer to buffer structure to be filled
///
/// @return Void
///////////////////////////////////////////////////////////////////////////////
void test_util_get_buf_ptr(test_util_window_t *p_window, test_util_buf_ptr_t *p_buf);

///////////////////////////////////////////////////////////////////////////////
/// test_util_get_buf
///
/// @brief Get buffer virtual address
///
/// @param p_window       window
/// @param idx            Buffer index
/// @param p_buf          pointer to buffer structure to be filled
/// @param buf_len        buffer size
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_get_buf(test_util_window_t *p_window, unsigned int idx, test_util_buf_ptr_t *p_buf, size_t *buf_len);


///////////////////////////////////////////////////////////////////////////////
/// test_util_create_c2d_surface
///
/// @brief Create a C2D surface
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param idx              Buffer index
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_create_c2d_surface(test_util_ctxt_t *ctxt, test_util_window_t *p_window, unsigned int idx);

///////////////////////////////////////////////////////////////////////////////
/// test_util_get_c2d_surface_id
///
/// @brief Get the ID from a C2D surface
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param idx              Buffer index
/// @param surface_id       Pointer to C2D sruface ID number
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_get_c2d_surface_id(test_util_ctxt_t *ctxt, test_util_window_t *p_window, unsigned int idx, unsigned int *surface_id);

///////////////////////////////////////////////////////////////////////////////
/// parse_xml_config_file
///
/// @brief Parse XML config file for qcarcam_test
///
/// @param filename         Char pointer to XML config file name
/// @param inputs           Pointer to struct to store parsed inputs parameters
/// @param max_num_inputs   Maximum number of inputs to be parsed from config file
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
int test_util_parse_xml_config_file(const char *filename, test_util_xml_input_t *inputs, unsigned int max_num_inputs);

///////////////////////////////////////////////////////////////////////////////
/// test_util_allocate_input_buffers
///
/// @brief Allocate buffers for injection as input to qcarcam
///
/// @param buffers          Pointer to qcarcam buffers structure
/// @param size             size to allocate
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_allocate_input_buffers(qcarcam_buffers_t *buffers, unsigned int size);

///////////////////////////////////////////////////////////////////////////////
/// test_util_read_input_data
///
/// @brief Read input data into buffer
///
/// @param buffers          Pointer to qcarcam buffers structure
/// @param idx              Index of buffer to read data into
/// @param filename         Path to data file to be read
/// @param size             Size to read from file
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_read_input_data(qcarcam_buffers_t *buffers, unsigned int idx, const char *filename, unsigned int size);

///////////////////////////////////////////////////////////////////////////////
/// test_util_get_time
///
/// @brief Get current time
///
/// @param pTime          Pointer to current time
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
int test_util_get_time(unsigned long long *pTime);

///////////////////////////////////////////////////////////////////////////////
/// test_util_set_diag
///
/// @brief set the diagnostic structure to test_util_window_t
///
/// @param ctxt             Pointer to test_util context
/// @param p_window         Pointer to window
/// @param diag             diagnostic structure
///
/// @return Void
///////////////////////////////////////////////////////////////////////////////
void test_util_set_diag(test_util_ctxt_t *ctxt, test_util_window_t *p_window, test_util_diag_t* diag);

///////////////////////////////////////////////////////////////////////////////
/// test_util_gpio_config
///
/// @brief enable IO privileges, configure the gpio and set it up for interrupts
///
/// @param intr             Pointer for the IRQ to be stored
/// @param gpio_number      Specific gpio that is being utilised
/// @param trigger          Instance of the signal which shall causes the interrupt
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_gpio_interrupt_config(uint32_t *intr, int gpio_number, test_util_trigger_type_t trigger);

///////////////////////////////////////////////////////////////////////////////
/// test_util_interrupt_attach
///
/// @brief attach the interrupt event to an interrupt id
///
/// @param arguments    arguments to pass to the newly created thread
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_interrupt_attach(test_util_intr_thrd_args_t *arguments);

///////////////////////////////////////////////////////////////////////////////
/// test_util_interrupt_wait_and_unmask
///
/// @brief wait for a GPIO interrupt and then unmask it
///
/// @param irq              IRQ to unmask
/// @param interrupt_id     interrupt id to unmask
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_interrupt_wait_and_unmask(uint32_t irq, int interrupt_id);

///////////////////////////////////////////////////////////////////////////////
/// test_util_get_param
///
/// @brief get the value of the window parameter of the window
///
/// @param p_window         Pointer to window
/// @param param            window parameter you are trying to access
/// @param value            value of parameter will be stored here
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_get_param(test_util_window_t *p_window, test_util_params_t param, int *value);

///////////////////////////////////////////////////////////////////////////////
/// test_util_set_param
///
/// @brief set the value of the window parameter
///
/// @param p_window         Pointer to window
/// @param param            window parameter you want to change
/// @param value            value you want to set the param to
///
/// @return QCARCAM_RET_OK if successful
///////////////////////////////////////////////////////////////////////////////
qcarcam_ret_t test_util_set_param(test_util_window_t *p_window, test_util_params_t param, int value);

#endif /* _TEST_UTIL_H */

