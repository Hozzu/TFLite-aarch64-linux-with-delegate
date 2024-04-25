#ifndef _STRIPENPSPPS_H_
#define _STRIPENPSPPS_H_

//-------------------------------------------------------------------------
// Copyright (c) 2015-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.

//------------------------------------------------------------------------
// @file  stripeBPSPPS.h
// @brief IpeStripingLibraryOutputPerStripe Algorithm IPE Lower-layer, NPS and PPS
//------------------------------------------------------------------------

/*------------------------------------------------------------------------
*       Include Files
* ----------------------------------------------------------------------- */
#include "list.h"
#include "icpcomdef.h"
#include "modules.h"
#include "scalers.h"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------
*       Definitions and Constants
* ----------------------------------------------------------------------- */

/** Defined by HW, line buffer size of IPE pipe */
#define STRIPING_LIB_IPE_LINE_BUFFER_SIZE         336

/** Dimension Constarints */

#define LTM_DC_MIN_WIDTH                           72
#define LTM_DC_MIN_HEIGHT                          54

/*------------------------------------------------------------------------
*       Type Declarations
* ----------------------------------------------------------------------- */

typedef enum _IPE_PASS
{
    IPE_FULL = 0,   // Default is INVALID.
    IPE_DC4,
    IPE_DC16,
    IPE_DC64,
    IPE_PASS_COUNT
} IPE_PASS;

typedef struct _IpeStripingModule1dOutputStorage
{
    MNScaleDownInStruct_V20_1D          videoMndsLuma;
    MNScaleDownInStruct_V20_1D          videoMndsChroma;
    MNScaleDownInStruct_V20_1D          displayMndsLuma;
    MNScaleDownInStruct_V20_1D          displayMndsChroma;
    Upscalev20Striping1dOutputParams    upscalar;
    ChromaUpv201dStripingOutputParams   chromaup;
    LTMV13StripeDCParams                ltmDc;
    LTMV13StripeIPParams_1D             ltmIp;
    ANRv10Striping1dOutputParams        anr;
    TFv10Striping1dOutputParams         tf;
    CRCv10Striping1dOutputParams        tfFullOutCropLuma;
    CRCv10Striping1dOutputParams        tfFullOutCropChroma;
    CRCv10Striping1dOutputParams        ds4PreCropLuma;
    CRCv10Striping1dOutputParams        ds4PreCropChroma;
    CRCv10Striping1dOutputParams        tfDs4OutCropLuma;
    CRCv10Striping1dOutputParams        tfDs4OutCropChroma;
    CRCv10Striping1dOutputParams        preChromaupCropLuma;
    CRCv10Striping1dOutputParams        preChromaupCropChroma;
    CRCv10Striping1dOutputParams        preUpscalarCrop; // YUV 444 (same values for Luma and Chroma)
//    CRCv10Striping1dOutputParams        preUpscalarCropChroma;
    CRCv10Striping1dOutputParams        videoPreMndsCropLuma;
    CRCv10Striping1dOutputParams        videoPreMndsCropChroma;
    CRCv10Striping1dOutputParams        displayPreMndsCropLuma;
    CRCv10Striping1dOutputParams        displayPreMndsCropChroma;
    CRCv10Striping1dOutputParams        videoOutCropLuma;
    CRCv10Striping1dOutputParams        videoOutCropChroma;
    CRCv10Striping1dOutputParams        displayOutCropLuma;
    CRCv10Striping1dOutputParams        displayOutCropChroma;
}
IpeStripingModule1dOutputStorage;

typedef struct _IpeStripingLibraryOutputPerStripe
{
    int16_t tfWorkWindowInStart;

    // fetch coordinates
    int16_t tfiFetchFirstPixel;
    int16_t tfiFetchLastPixel;
    int16_t mainFetchFirstPixel;
    int16_t mainFetchLastPixel;
    int16_t refFetchFirstPixel;
    int16_t refFetchLastPixel;
    int16_t pdiFetchFirstPixel;
    int16_t pdiFetchLastPixel;
    int16_t lmcFetchFirstByte;
    int16_t lmcFetchLastByte;
    int16_t lenrDs4FetchFirstPixel;
    int16_t lenrDs4FetchLastPixel;

    // write coordinates
    int16_t pdiOutFirstPixel;
    int16_t pdiOutLastPixel;
    int16_t tfiOutFirstPixel;
    int16_t tfiOutLastPixel;
    int16_t tfFullOutFirstPixel;
    int16_t tfFullOutLastPixel;
    int16_t LMCOutFirstByte;
    int16_t LMCOutLastByte;
    int16_t tfDs4OutFirstPixel;
    int16_t tfDs4OutLastPixel;
    int16_t videoOutFirstPixel;
    int16_t videoOutLastPixel;
    int16_t dispOutFirstPixel;
    int16_t dispOutLastPixel;

    int16_t dummy_field_for_byte_padding;

    // flags
    BOOL leftStripe;
    BOOL rightStripe;
    BOOL leftStripePDI;          // is there corner case where for main input it's at boundary, but not for PDI & TFI?
    BOOL rightStripePDI;
    BOOL leftStripeTFI;
    BOOL rightStripeTFI;

    IpeStripingModule1dOutputStorage    module1d;
    //===== generic ends here ======

    ANRv10StripingOutputParams          anr;
    TFv10v20StripingOutputParams        tf;
    LENRv10StripingOutputParams         lenr;

    CRCv10StripingOutputParams      tfFullOutCropLuma;
    CRCv10StripingOutputParams      tfFullOutCropChroma;
    CRCv10StripingOutputParams      ds4PreCropLuma;
    CRCv10StripingOutputParams      ds4PreCropChroma;
    CRCv10StripingOutputParams      tfDs4OutCropLuma;
    CRCv10StripingOutputParams      tfDs4OutCropChroma;
    CRCv10StripingOutputParams      preChromaupCropLuma;
    CRCv10StripingOutputParams      preChromaupCropChroma;
    CRCv10StripingOutputParams      preUpscalarCrop;     // YUV 444 (same values for Luma and Chroma)
    CRCv10StripingOutputParams      videoPreMndsCropLuma;
    CRCv10StripingOutputParams      videoPreMndsCropChroma;
    CRCv10StripingOutputParams      displayPreMndsCropLuma;
    CRCv10StripingOutputParams      displayPreMndsCropChroma;
    CRCv10StripingOutputParams      videoOutCropLuma;
    CRCv10StripingOutputParams      videoOutCropChroma;
    CRCv10StripingOutputParams      displayOutCropLuma;
    CRCv10StripingOutputParams      displayOutCropChroma;

    GRAv10stripingOutputParams          gra;
    HNRv10StripingOutputParams          hnr;

    MNDSv20StripingOutputParams video_mnds_y;
    MNDSv20StripingOutputParams video_mnds_c;
    MNDSv20StripingOutputParams display_mnds_y;
    MNDSv20StripingOutputParams display_mnds_c;

    LTMv13StripingOutputParams          ltm;

    ChromaUpv20StripingOutputParams     chromaup;

    ASFv30StripingOutputParams          asf;

    Upscalev20StripingOutputParams      upscalar;

    int32_t qosIPEcounter;
}
IpeStripingLibraryOutputPerStripe;

typedef struct _IpeStripingLibraryOutputPerPass
{
    /* pass-level parameters */
    int16_t tfWorkWindowInStart;

    // fetch coordinates
    int16_t tfiFetchFirstLine;
    int16_t tfiFetchLastLine;
    int16_t mainFetchFirstLine;
    int16_t mainFetchLastLine;
    int16_t refFetchFirstLine;
    int16_t refFetchLastLine;
    int16_t pdiFetchFirstLine;
    int16_t pdiFetchLastLine;
    int16_t lmcFetchFirstLine;
    int16_t lmcFetchLastLine;
    int16_t lenrDs4FetchFirstLine;
    int16_t lenrDs4FetchLastLine;

    // write coordinates
    int16_t pdiOutFirstLine;
    int16_t pdiOutLastLine;
    int16_t tfiOutFirstLine;
    int16_t tfiOutLastLine;
    int16_t tfFullOutFirstLine;
    int16_t tfFullOutLastLine;
    int16_t LMCOutFirstLine;
    int16_t LMCOutLastLine;
    int16_t tfDs4OutFirstLine;
    int16_t tfDs4OutLastLine;
    int16_t videoOutFirstLine;
    int16_t videoOutLastLine;
    int16_t dispOutFirstLine;
    int16_t dispOutLastLine;

    int16_t dummy_field_for_byte_padding;

    // flags
    BOOL topPad;
    BOOL bottomPad;
    BOOL topStripePDI;
    BOOL bottomStripePDI;
    BOOL topStripeTFI;
    BOOL bottomStripeTFI;

    IpeStripingModule1dOutputStorage module1d;
    //===== generic ends here ======

    int16_t LTMDCEnable;
    int16_t LTMIPEnable;
    int16_t TFenable;
    int16_t                             ppsEnable;

    int16_t videoOutImageLumaWidth;
    int16_t dispOutImageLumaWidth;

    int16_t   refInOffset_x;
    int16_t   refInOffset_y;
    int16_t   ref1frameWidth;
    int16_t   ref4frameWidth;

    // TODO : pack ZoomWindow parameters in a struct
        int16_t   npsImageZoomWindow_isZoomEnable;
        int16_t   npsImageZoomWindow_startX;
        int16_t   npsImageZoomWindow_startY;
        int16_t   npsImageZoomWindow_sizeX;
        int16_t   npsImageZoomWindow_sizeY;
        int16_t   npsRefZoomWindow_isZoomEnable;
        int16_t   npsRefZoomWindow_startX;
        int16_t   npsRefZoomWindow_startY;
        int16_t   npsRefZoomWindow_sizeX;
        int16_t   npsRefZoomWindow_sizeY;
        int16_t   npsPrevRefZoomWindow_isZoomEnable;
        int16_t   npsPrevRefZoomWindow_startX;
        int16_t   npsPrevRefZoomWindow_startY;
        int16_t   npsPrevRefZoomWindow_sizeX;
        int16_t   npsPrevRefZoomWindow_sizeY;

        /* stripes */
    int16_t numStripes; // TODO : change to uint32_t\uint16_t
    ListHandle hStripeList;
}
IpeStripingLibraryOutputPerPass;

typedef struct _IpeStripingLibraryOutputPerFrame
{
    /* frame-level parameters */

    /* passes */
    int32_t                             numPasses;  // TODO : change to uint32_t
    int32_t dummy_field_for_byte_padding;
    IpeStripingLibraryOutputPerPass*    passes;
}
IpeStripingLibraryOutputPerFrame;

typedef struct _IpeModuleConfig1dInput
{
    // tiering information
    int32_t chip;

    int32_t ANR_CYLPF_dithering_seed_frame;     //initial random seed for dithering in CYLPF
    int32_t ANR_dcnf_dithering_seed_frame;      //initial random seed for dithering in dcnf
    int32_t tf_prngSeed_frame;                  //frame level TF PRNG seed
    int32_t tf_LnrStartIdx_frame;
    int32_t tf_LnrScale;
    BOOL    chromaUp_cosited;
    BOOL    chromaUp_even;
    int16_t mainInFormat;
    int16_t refInFormat;
    int16_t ANRDCInFormat;
    int16_t TFIndFormat;
    int16_t dispOutFormat;
    int16_t videoOutFormat;
    int16_t TFOutFormat;
    int16_t DS4OutFormat;
    int16_t lenrDS4InFormat;
    int16_t mainInDim;
    int16_t videoOutDim;
    int16_t dispOutDim;
    int16_t lenrDs4InDim;
    int16_t videoDimInSource;
    int16_t dispDimInSource;
    int16_t ANRDCInDim;
    int16_t TFIndDim;
    int16_t lineBufferSize;
    int16_t min_ica_out_size;
    uint16_t kernelLENR;
    int16_t kernelTFDilate;
    int16_t kernelTFErode;
    int16_t kernelTFrefinement;     //this is hidden by the TF kernel but is needed to calculate some coordinate constraints
    int16_t TFenable;
    int16_t passIdx;                //0: full, 1: 1:4, 2: 1:16, 3: 1:64
    int16_t LTMDCEnable;            // for DC collection
    int16_t LTMIPEnable;            // call IP code for striping parameters
    int16_t zoomOffsetInSource;
    int16_t tf_dithering_en;
    int16_t ltmDCtableOption;

    int16_t ds4Enable;
    int16_t refInOffset;
    int16_t npsImageZoomWindow_isZoomEnable;
    int16_t npsImageZoomWindow_start;
    int16_t npsImageZoomWindow_size;
    int16_t npsRefZoomWindow_isZoomEnable;
    int16_t npsRefZoomWindow_start;
    int16_t npsRefZoomWindow_size;
    int16_t npsPrevRefZoomWindow_isZoomEnable;
    int16_t npsPrevRefZoomWindow_start;
    int16_t npsPrevRefZoomWindow_size;

    int16_t mainDimInSource;
    int16_t mainOffsetInSource;
    int16_t mainInConstraint;
    int16_t ANRDCInConstraint;
    int16_t refInConstraint;
    int16_t lenrDs4InConstraint;
    int16_t TFIndConstraint;
    int16_t TFOutConstraint;
    int16_t DS4OutConstraint;
    int16_t videoOutConstraint;
    int16_t dispOutConstraint;
    BOOL    upscaleEnable;
    int16_t tf_lmenable_prevpass;
    UpscaleInStruct_V11_1D chromaUpFrame_C;
    Upscalev20Striping1dOutputParams upscaleSIMOFrame;
    MNScaleDownInStruct_V20_1D downscaleVideoLumaFrame;
    MNScaleDownInStruct_V20_1D downscaleVideoChromaFrame;
    MNScaleDownInStruct_V20_1D downscaleDispLumaFrame;
    MNScaleDownInStruct_V20_1D downscaleDispChromaFrame;
    MNScaleDownInStruct_V20_1D downscaleLTMDCFrame;

    TFrefinementInputParams TFrefinementFrame;
    GRAv10stripingInputParams gra;
    ANRLNRInputParams anrlnr;
}
IpeModuleConfig1dInput;

#define STRIPE_IPE_RANGE_START_IDX      0
#define STRIPE_IPE_RANGE_END_IDX        1
#define STRIPE_IPE_RANGE_MAX_IDX        2

#define STRIPE_IPE_RANGE_START(rng)     (rng[STRIPE_IPE_RANGE_START_IDX])
#define STRIPE_IPE_RANGE_END(rng)       (rng[STRIPE_IPE_RANGE_END_IDX])

typedef struct  _IpeStripeInternalRanges
{
    int16_t                     anrIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     anrCylpfOut[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     anrRnrIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     tfIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     ppsIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     lenrIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     cacOut_C[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     chromaUpIn_C[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     chromaUpOut[STRIPE_IPE_RANGE_MAX_IDX];

    int16_t                     asfOutPpsFOV[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     usInPpsFOV[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     usOutPpsFOV[STRIPE_IPE_RANGE_MAX_IDX];
    //int16_t                     usOutPpsFOV_mpix_padded[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     ltm_dc_ds_in_min_rage_start;
    int16_t                     ltm_dc_ds_in;
    int16_t                     ltmDCdsOut[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     ltmDcRightBound;

    int16_t                     videoDSinPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     videoDSinPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     videoMinDSinPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     videoMinDSinPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     videoDSoutPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     videoDSoutPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     other_dimension_video_ds_out_y;
    int16_t                     other_dimension_video_ds_out_c;
    int16_t                     videoPrecropIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispDSinPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispDSinPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispMinDSinPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispMinDSinPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispDSoutPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     dispDSoutPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     other_dimension_display_ds_out_y;
    int16_t                     other_dimension_display_ds_out_c;
    int16_t                     dispPrecropIn[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     tfRefineBlk[STRIPE_IPE_RANGE_MAX_IDX];

    int16_t                     ds4InPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     ds4InPpsFovChroma[STRIPE_IPE_RANGE_MAX_IDX];
    int16_t                     ds4OutPpsFovLuma[STRIPE_IPE_RANGE_MAX_IDX];
}
IpeStripeInternalRanges;        // TODO : rename struct - remove "Internal" part

typedef struct _IpeStripeAllocationResultPerStripe
{
    int16_t tfRefRangeInROI;
    int16_t tfWorkWindowInStart;
    int16_t tfWorkWindowInEnd;
    int16_t tfditheringStart;
    int32_t qosIPEcounter_1d_fetch;
    int32_t qosIPEcounter_1d_usOut;
    int16_t upscalarGoalOutRight;
    int16_t ppsOutOfBoundary;
    int16_t anr_cnrStart;
    int16_t asfStart;
    int16_t edgeStripeLT_PPSFOV;
    int16_t edgeStripeRB_PPSFOV;
    BOOL    edgeStripeLT;
    BOOL    edgeStripeRB;
    int16_t mainFetchFirst;
    int16_t mainFetchLast;
    int16_t lmcFetchFirstByte;
    int16_t lmcFetchLastByte;
    int16_t lenrDs4FetchFirst;
    int16_t lenrDs4FetchLast;
    int16_t PDIOutFirst;
    int16_t PDIOutLast;
    int16_t TFIOutFirst;
    int16_t TFIOutLast;
    int16_t LMCOutFirst;
    int16_t LMCOutLast;
    int16_t TFOutFirst;
    int16_t TFOutLast;
    int16_t DS4OutFirst;
    int16_t DS4OutLast;
    int16_t    mndsVideoDropEnd;
    int16_t    mndsDispDropEnd;
    int16_t videoOutLumaFirst;
    int16_t videoOutLumaLast;
    int16_t dispOutLumaFirst;
    int16_t dispOutLumaLast;
    int16_t ltmDcRangeFirst;
    int16_t ltmDcRangeLast;
    int16_t dummy_field_for_byte_padding;
    IpeStripeInternalRanges stripeRanges;
}
IpeStripeAllocationResultPerStripe;

typedef struct _IpeStripeAllocationResultPerPass
{
    IpeModuleConfig1dInput module_config_input_x;
    IpeModuleConfig1dInput module_config_input_y;
    IpeStripeAllocationResultPerStripe allocation_result_y;

    /* stripes */
    int16_t    numStripes;
    int16_t dummy_field_for_byte_padding_0;
    int32_t dummy_field_for_byte_padding_1;
    ListHandle hStripeAllocationResultList;
}
IpeStripeAllocationResultPerPass;

typedef struct _IpeStripeAllocationResultPerFrame
{
    /* frame-level parameters */
    int16_t tiering;
    int16_t mux_mode;

    /* passes */
    int32_t numPasses;
    IpeStripeAllocationResultPerPass*   passes;
}
IpeStripeAllocationResultPerFrame;

#pragma pack(push)
#pragma pack(4)

typedef struct _IpeStripingLibraryInput
{
    int16_t                         overrideMaxBufferSize; //moved here to remove byte padding warning

    // top level
    int16_t                             tiering;
    int16_t                             mux_mode;
    int16_t                             oneto4PassEnable;
    int16_t                             oneto16PassEnable;
    int16_t                             oneto64PassEnable;
    int16_t                             passSkipThreshold_w;
    int16_t                             passSkipThreshold_h;

    int16_t                             TFfullOutFormat_full;
    int16_t                             TFds4OutFormat[IPE_PASS_COUNT];
    int16_t                             TFds4OutFormat_1to4;

    // main input
    int16_t                             mainInFormat;
    int16_t                             mainRefInFormat;
    int16_t                             mainInWidth;
    int16_t                             mainInHeight;
    int16_t                             zoomEnable;
    int16_t                             zoomFirstPixelInSource;
    int16_t                             zoomFirstLineInSource;
    int16_t                             zoomInWidth;
    int16_t                             zoomInHeight;
    int16_t                             prevZoomEnable;
    int16_t                             prevZoomFirstPixelInSource;
    int16_t                             prevZoomFirstLineInSource;
    int16_t                             prevZoomInWidth;
    int16_t                             prevZoomInHeight;
    int16_t                             mainInStride;


    // 1:4 input frame
    int16_t                             oneToFourInputFormat;
    int16_t                             oneToFourRefInFormat;
    int16_t                             oneToFourInputWidth;
    int16_t                             oneToFourInputHeight;
    int16_t                             oneToFourInputStride;

    // 1:16 input frame
    int16_t                             oneToSixteenInputFormat;
    int16_t                             oneToSixteenRefInFormat;
    int16_t                             oneToSixteenInputWidth;
    int16_t                             oneToSixteenInputHeight;
    int16_t                             oneToSixteenInputStride;

    // 1:64 input frame
    int16_t                             oneTo64InputFormat;
    int16_t                             oneTo64RefInFormat;
    int16_t                             oneTo64InputWidth;
    int16_t                             oneTo64InputHeight;
    int16_t                             oneTo64InputStride;

    // IPE_LENR_DS4_IN
    int16_t                               lenrDs4InputFormat;

    // display output
    int16_t                             dispOutFormat;
    int16_t                             dispOutWidth;
    int16_t                             dispOutHeight;
    int16_t                             dispOutFirstPixelInSource;
    int16_t                             dispOutFirstLineInSource;
    int16_t                             dispOutWidthInSource;
    int16_t                             dispOutHeightInSource;
    int16_t                             dispOutStride;
    int32_t                             dispPrevFirstPixelInSource;
    int32_t                             dispPrevFirstLineInSource;

    // video output
    int16_t                             videoOutFormat;
    int16_t                             videoOutWidth;
    int16_t                             videoOutHeight;
    int16_t                             videoOutFirstPixelInSource;
    int16_t                             videoOutFirstLineInSource;
    int16_t                             videoOutWidthInSource;
    int16_t                             videoOutHeightInSource;
    int16_t                             videoOutStride;
    int32_t                             videoPrevFirstPixelInSource;
    int32_t                             videoPrevFirstLineInSource;

    ICAv10InputParams                   ica1;
    ICAv10InputParams                   ica2;
    ANRv10StripingInputParams           anr[4];
    TFv10v20StripingInputParams         tf[4];
    ChromaUpv20StripingInputParams      chroma_up;
    CACv22StripingInputParams           cac;
    LTMv13StripingInputParams           ltm;
    ASFv30StripingInputParams           asf;
    GRAv10stripingInputParams           gra;
    Upscalarv20StripingInputParams      upscalar;
    DS4v10StripingInputParams           ds4[IPE_PASS_COUNT];
    MNDSv20StripingInputParams          mndsInVideo;
    MNDSv20StripingInputParams          mndsInDisplay;
    HNRInputParam                       hnr;

    // debug
    // TODO : find a way to remove below variables
    //int16_t                         overrideMaxBufferSize;
    BOOL                            forceEvenStripe;
    BOOL                            enforceMinOutputConstraint;
}
IpeStripingLibraryInput;


#pragma pack(pop)

#ifdef __cplusplus
}
#endif

#endif /* _STRIPENPSPPS_H_ */
