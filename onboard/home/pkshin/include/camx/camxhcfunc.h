#ifndef CAMXHCFUNC_H
#define CAMXHCFUNC_H
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file  camxhcfunc.h
/// @brief Histogram Process node class declarations
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "camxdefs.h"

#define D_L_AREA_DIV_NUM    (2)                      // Division Number of Large Area to Get Small Area
#define D_S_AREA_DIV_NUM_Y  (15)                     // Division Number of Small Area to Get Small Small Area
#define D_S_AREA_DIV_NUM_X  (15)                     // Division Number of Small Area to Get Small Small Area
#define D_L_AREA_NUM_Y      (6)                                                     // Y Address of Large Area
#define D_L_AREA_NUM_X      (8)                                                     // X Address of Large Area
#define D_S_AREA_NUM_Y      (D_L_AREA_NUM_Y*D_L_AREA_DIV_NUM)                       // Y Address of Small Area
#define D_S_AREA_NUM_X      (D_L_AREA_NUM_X*D_L_AREA_DIV_NUM)                       // X Address of Small Area
#define D_SS_AREA_NUM_Y     (D_L_AREA_NUM_Y*D_L_AREA_DIV_NUM*D_S_AREA_DIV_NUM_Y)    // Y Address of Small Small Area
#define D_SS_AREA_NUM_X     (D_L_AREA_NUM_X*D_L_AREA_DIV_NUM*D_S_AREA_DIV_NUM_X)    // X Address of Small Small Area

#define D_HIST_BIN_NUM      (8)                                            // The Number of Histogram Bin
#define D_HIST_DIFF_DIR_NUM (4)                                             // The Number of Substration Direction
#define D_TABLE_POINT_NUM   (5)                                             // The Number of Table Point
#define D_PARAM_MODE_NUM    (2)                                             // The Number of Parameter Mode
// Parameter for IQ Turning
typedef struct
{
    double  histDiffThr;                                                    // Threshold of Histogram Difference
    INT     histDiffLevelTableX       [D_TABLE_POINT_NUM];                  // X Address of Table for Histogram Difference Level
    INT     histDiffLevelTableY       [D_TABLE_POINT_NUM];                  // Y Address of Table for Histogram Difference Level
    INT     brightnessLevelTableX     [D_TABLE_POINT_NUM];                  // X Address of Table for Brightness Level
    INT     brightnessLevelTableY     [D_TABLE_POINT_NUM];                  // Y Address of Table for Brightness Level
    INT     brightnessCompLevelTableX [D_TABLE_POINT_NUM];                  // X Address of Table for Brightness Comparison Level
    INT     brightnessCompLevelTableY [D_TABLE_POINT_NUM];                  // Y Address of Table for Brightness Comparison Level
    INT     lowContrastLevelTableX    [D_TABLE_POINT_NUM];                  // X Address of Table for Low Contrast Level
    INT     lowContrastLevelTableY    [D_TABLE_POINT_NUM];                  // Y Address of Table for Low Contrast Level
    INT     calcLTCRatioTableX        [D_TABLE_POINT_NUM];                  // X Address of Table for Calculation of LTC Ratio
    INT     calcLTCRatioTableY        [D_TABLE_POINT_NUM];                  // Y Address of Table for Calculation of LTC Ratio
    INT     adjValForLTCRatioYTableX  [D_TABLE_POINT_NUM];                  // X Address of Table for Adjustment Value of CalcLTCRatioTableY Table Point
    INT     adjValForLTCRatioYTableY  [D_TABLE_POINT_NUM];                  // Y Address of Table for Adjustment Value of CalcLTCRatioTableY Table Point
} HcParamVal_t;
// Area with Large Histogram Difference
typedef struct
{
    INT largeHistDiffAreaY[D_L_AREA_NUM_Y*D_L_AREA_NUM_X];                  // Y Address of Large Histogram Difference Area
    INT largeHistDiffAreaX[D_L_AREA_NUM_Y*D_L_AREA_NUM_X];                  // X Address of Large Histogram Difference Area
    INT largeHistDiffAreaNum;                                               // The Number of Large Histogram Difference Area
} AreaListOfLargeHistDiff_t;
/*----------------------------------------------------------------------------- * external function
 *---------------------------------------------------------------------------*/
// Calculate Pixel Address of Each Area(Large Area/Small Area/Small Small Area)
extern void CalculateAreaPixelAddress
(
    // Input
    INT sizeY,                                                              // Y Size of Image Data
    INT sizeX                                                               // X Size of Image Data
);
// Calculate Histogram Difference Level using Histogram Data
extern void CalcLevelFromHist
(
    // Input
    INT HistData[D_L_AREA_NUM_Y][D_L_AREA_NUM_X][D_HIST_BIN_NUM],           // Histogram Data
    INT ParamMode,                                                          // Parameter Mode
    // Output
    INT HistDiffLevel[D_L_AREA_NUM_Y][D_L_AREA_NUM_X],                      // Histogram Difference Level
    AreaListOfLargeHistDiff_t *pS_AreaListOfLargeHistDiff                   // Area List of Large Histogram Difference
);
// Calculate Histogram Difference
extern void CalcHistDiff
(
    // Input
    INT HistData[D_L_AREA_NUM_Y][D_L_AREA_NUM_X][D_HIST_BIN_NUM],           // Histogram Data
    // Output
    INT HistDiff[D_L_AREA_NUM_Y][D_L_AREA_NUM_X][D_HIST_DIFF_DIR_NUM]       // Histogram Difference Data
);
// Calculate Y Data in Area(Large)
extern void CalcLargeAreaY
(
    // Input
    INT HistData[D_L_AREA_NUM_Y][D_L_AREA_NUM_X][D_HIST_BIN_NUM],           // Histogram Data(Cumulative)
    // Output
    INT LargeAreaY[D_L_AREA_NUM_Y][D_L_AREA_NUM_X]                          // Y Data of Each Area(Large)
);
// Calculate Histogram Difference Level
extern void CalcHistDiffLevel
(
    // Input
    INT HistDiff[D_L_AREA_NUM_Y][D_L_AREA_NUM_X][D_HIST_DIFF_DIR_NUM],      // Histogram Difference Data
    INT LargeAreaY[D_L_AREA_NUM_Y][D_L_AREA_NUM_X],                         // Y Data of Each Area(Large)
    INT ParamMode,                                                          // Parameter Mode
    // Output
    INT HistDiffLevel[D_L_AREA_NUM_Y][D_L_AREA_NUM_X]                       // Histogram Difference Level
);
// Create Area(Large) List of Large Histogram Difference
extern void CreateAreaListOfLargeHistDiff
(
    // Input
    INT HistDiffLevel[D_L_AREA_NUM_Y][D_L_AREA_NUM_X],                      // Histogram Difference Level
    INT LargeAreaY[D_L_AREA_NUM_Y][D_L_AREA_NUM_X],                         // Y Data of Each Area(Large)
    // Output
    AreaListOfLargeHistDiff_t *pS_AreaListOfLargeHistDiff                   // Area List of Large Histogram Difference
);
// Sort
extern void QuSort
(
    // Input
    INT f_Left,                                                             // Left  Index of Data Array
    INT f_Right,                                                            // Right Index of Data Array    // Input/Output
    INT *fp_Data1,                                                          // Sort Data1
    INT *fp_Data2,                                                          // Sort Data2
    INT *fp_Data3                                                           // Sort Data3
);
// Calculate Brightness/Brightness Comparison/Low Contrast Level using Image Data
extern void CalcLevelFromImg
(
    // Input
    unsigned char  *pImgRaw10Packed,                                       // Image Data in RAW10 Packed format
    INT SizeX,                                                              // X Size of Image Data
    INT AreaY,                                                              // Y Address of Area
    INT AreaX,                                                              // X Address of Area
    INT ParamMode,                                                          // Parameter Mode
    // Output
    INT BrightnessLevel    [D_S_AREA_NUM_Y][D_S_AREA_NUM_X],                // Brightness Level
    INT BrightnessCompLevel[D_S_AREA_NUM_Y][D_S_AREA_NUM_X],                // Brightness Comparison Level
    INT LowContrastLevel   [D_S_AREA_NUM_Y][D_S_AREA_NUM_X]                 // Low Contrast Level
);
// Calculate Y Data in Area(Small)
extern void CalcYDataFromImg
(
    // Input
    unsigned char  *pImgRaw10Packed,                                       // Image Data in RAW10 Packed format
    INT SizeX,                                                              // X Size of Image Data
    INT AreaY,                                                              // Y Address of Area
    INT AreaX,                                                              // X Address of Area
    // Output
    INT YDataMin[D_L_AREA_DIV_NUM][D_L_AREA_DIV_NUM],                       // Minimum Y Data
    INT YDataMax[D_L_AREA_DIV_NUM][D_L_AREA_DIV_NUM],                       // Maximum Y Data
    INT YDataAvg[D_L_AREA_DIV_NUM][D_L_AREA_DIV_NUM]                        // Average Y Data
);
// Calculate Maximum of Average Y Data
extern INT CalcYDataAvgMax
(
    // Input
    INT YDataAvg[D_L_AREA_DIV_NUM][D_L_AREA_DIV_NUM]                        // Average Y Data
    // Return                                                               // Maximum of Average Y Data
);
// Calculate Brightness Level
extern INT CalcBrightnessLevel
(
    // Input
    INT YDataAve,                                                           // Average Y Data
    HcParamVal_t *p_HcParamVal                                              // Parameter
    // Output                                                               // Brightness Level
);
// Calculate Brightness Comparison Level
extern INT CalcBrightnessCompLevel
(
    // Input
    INT YDataAvg,                                                           // Average Y Data
    INT YDataAvgMax,                                                        // Maximum of Average Y Data
    HcParamVal_t *p_HcParamVal                                              // Parameter
    // Return                                                               // Brightness Comparison Level
);// Calculate Low Contrast Level
extern INT CalcLowContrastLevel
(
    // Input
    INT YDataMin,                                                           // Minimum Y Data
    INT YDataMax,                                                           // Maximum Y Data
    HcParamVal_t *p_HcParamVal                                              // Parameter
    // Return                                                               // Low Contrast Level
);
// Calculate Total Level of Histogram Difference/Brightness/Brightness Comparison/Low Contrast Level
extern INT CalcTotalLevel
(
    // Input
    INT HistDiffLevel       [D_L_AREA_NUM_Y][D_L_AREA_NUM_X],               // Histogram Difference Level
    INT BrightnessLevel     [D_S_AREA_NUM_Y][D_S_AREA_NUM_X],               // Brightness Level
    INT BrightnessCompLevel [D_S_AREA_NUM_Y][D_S_AREA_NUM_X],               // Brightness Comparison Level
    INT LowContrastLevel    [D_S_AREA_NUM_Y][D_S_AREA_NUM_X],               // Low Contrast Level
    INT TotalLevelInEachArea[D_S_AREA_NUM_Y][D_S_AREA_NUM_X]                // Total Level (for Debug) in Each Area
    // Return                                                               // Total Level
);
// Calculate LTC Ratio
extern INT CalcLTCRatio
(
    // Input
    INT TotalLevel,                                                         // Total Level
    INT ParamMode,                                                          // Parameter Mode
    INT TotalGain                                                           // Total Gain
    // Return                                                               // LTC Ratio
);
// Convert Unit of LTCRatio (Percentage to Register Unit)
extern unsigned char ConvertUnitOfLTCRatio
(
    // Input
    INT LTCRatio_Percentage                                                 // LTC Ratio in Percentage
    // Return                                                               // LTC Ratio in Register Unit
);
// Initialize Parameter for Lowpass Filter
extern void InitLTCRatioLowpass
(
    void
);
// Calculate LTC Ratio after Lowpass Filter
extern unsigned char CalcLTCRatioLowpass
(
    // Input
    unsigned char LTCRatio                                                  // LTC Ratio
    // Return                                                               // LTC Ratio after Lowpass
);
// Divide Data Array Equally
extern void DivDataArr
(
    // Input
    INT IndexStart,                                                         // Start Index of Data Array
    INT IndexEnd,                                                           // End   Index of Data Array
    INT Div,                                                                // The Number of Division
    // Output
    INT *p_DataArr                                                          // Array of Index which Divides Data Array Equally, Array Size must be Div+1
);
// MIPI to Plain Imgae
extern unsigned short Mipi2Plain2
(
    // Input
    unsigned char *p_MData,                                                          // RAW10Packed Data
    INT MSizeX,                                                             // X Size of Image
    INT MY,                                                                 // Y Address
    INT MX                                                                  // X Address
    // Return                                                               // Unpacked Data
);
#endif