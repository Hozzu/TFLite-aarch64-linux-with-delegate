#ifndef CAMXHCLIBRARY_H__
#define CAMXHCLIBRARY_H__

#include "camxdefs.h"

CAMX_NAMESPACE_BEGIN

#ifdef __cplusplus
extern "C" {
#endif
/*-----------------------------------------------------------------------------
 * define/typedef
 *---------------------------------------------------------------------------*/
// Image Format
#define D_IMAGE_FORMAT_RAW10PACKED  (0) // Image Format of RAW10 Packed
// ERROR Code Definitions
#define D_HC_SUCCESS                          (  0)
#define D_HC_ERROR_ALREADY_INITIALIZED        (- 1)
#define D_HC_ERROR_CONF_NULL                  (- 2)
#define D_HC_ERROR_IMAGE_SIZE_OUTRANGE        (- 3)
#define D_HC_ERROR_IMAGE_FORMAT_OUTRANGE      (- 4)
#define D_HC_ERROR_THREAD_NUM_OUTRANGE        (- 5)
#define D_HC_ERROR_NOT_INITIALIZED            (- 6)
#define D_HC_ERROR_DATA_IN_NULL               (- 7)
#define D_HC_ERROR_RAW_IMG_PACKED_NULL        (- 8)
#define D_HC_ERROR_RAW_IMG_NOPACKED_NULL      (- 9)
#define D_HC_ERROR_HIST_NULL                  (-10)
#define D_HC_ERROR_PARAM_NULL                 (-11)
#define D_HC_ERROR_GAIN_OUTRANGE              (-12)
#define D_HC_ERROR_PARAM_MODE_OUTRANGE        (-13)
#define D_HC_ERROR_DATA_OUT_NULL              (-14)
#define D_HC_ERROR_SYSTEM_OFFSET              (-100)
// Configuration Data
typedef struct
{
    INT32           Width;              // Width of the Image data
    INT32           Height;             // Height of the Image data
    INT32           ImageFormat;        // Image Format ( RAW10 Packed Format or 16Bits Format )
    INT32           nThreads;           // The Number of Thread.
} HcLibConfig_t;
// Input Data
typedef struct
{
    UINT8           *pImgRaw10Packed;  // Image Data in RAW10 Packed Format.
    UINT16          *pHistogram;       // Local Y HIST Data of 8x6 Blocks with 18 Bin Data.
} HcLibDataIn_t;// Parameter
typedef struct
{
    UINT32          TotalGain;          // Total Gain ( Analog Gain x Digital Gain )
    UINT16          ParamMode;          // Parameter Mode
} HcLibParam_t;
// Output Data
typedef struct
{
    UINT8           LTCRatio;               // LTC Ratio for Still
    UINT8           LTCRatioLowpassOn;      // LTC Ratio for Preview
    INT32           LTCRatio_percentage;    // LTC Ratio for Still
} HcLibDataOut_t;

/// @brief Represents the input and output parameters of function LocalHistCalculation
struct LocalHistCalculationParams
{
    //  Input
    UINT8*          pImageAddress;          // Y plane image address
    FLOAT           DRCGainLTM;             // DRC gain ^ LTM percentage
    FLOAT           DRCDarkGain;            // DRC dark gain
    UINT32          sensorGain;             // Sensor real gain programed in this frame

    //  Output
    UINT8           LTCRatio;               // LTC Ratio for Still
    INT32           LTCRatio_percentage;    // LTC Ratio for Still
};

/*-----------------------------------------------------------------------------
 * external function
 *---------------------------------------------------------------------------*/

CAMX_VISIBILITY_PUBLIC extern INT32 HcLibInitialize
(
    // Input
    HcLibConfig_t   *p_Conf             // Configuration Data
    // Return                           // ERROR Code
);
// Execute API
CAMX_VISIBILITY_PUBLIC extern INT32 HcLibExecute
(
    // Input
    HcLibDataIn_t   *p_DataIn,          // Input Data
    HcLibParam_t    *p_Param,           // Parameter
    // Output
    HcLibDataOut_t  *p_DataOut          // Output Data
    // Return                           // ERROR Code
);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// LocalHistCalculation
///
/// @brief  This method creates an instance to the Local histogram algo.
///
/// @param  pLocalHistParams        Pointer to create params
///
/// @return None
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef VOID (*LocalHistCalculationType)(
    LocalHistCalculationParams* pLocalHistParams);

#ifdef __cplusplus
}
#endif

CAMX_NAMESPACE_END
#endif