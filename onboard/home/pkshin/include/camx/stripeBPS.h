//-------------------------------------------------------------------------
// Copyright (c) 2015-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//------------------------------------------------------------------------
#ifndef _STRIPEBPS_H_
#define _STRIPEBPS_H_

/*------------------------------------------------------------------------
*       Include Files
* ----------------------------------------------------------------------- */
#include "list.h"
#include "icpcomdef.h"
#include "modules.h"
#include "scalers.h"

/*------------------------------------------------------------------------
*       Definitions and Constants
* ----------------------------------------------------------------------- */

/** Defined by HW, line buffer size of BPS pipe */
#define STRIPING_LIB_BPS_LINE_BUFFER_SIZE         448

/*------------------------------------------------------------------------
*       Type Declarations
* ----------------------------------------------------------------------- */
typedef struct _BpsStripingModule1dOutputStorage
{
    CRCv10Striping1dOutputParams    preRolloffCrop;
    CRCv10Striping1dOutputParams    preChromadownCropLuma;
    CRCv10Striping1dOutputParams    preChromadownCropChroma;
    CRCv10Striping1dOutputParams    fullDs4PreDs4CropLuma;
    CRCv10Striping1dOutputParams    fullDs4PreDs4CropChroma;
    CRCv10Striping1dOutputParams    ds4Ds16PreDs4CropLuma;
    CRCv10Striping1dOutputParams    ds4Ds16PreDs4CropChroma;
    CRCv10Striping1dOutputParams    regPreMndsCropLuma;
    CRCv10Striping1dOutputParams    regPreMndsCropChroma;
    CRCv10Striping1dOutputParams    fullDs4OutCropLuma;
    CRCv10Striping1dOutputParams    fullDs4OutCropChroma;
    CRCv10Striping1dOutputParams    ds4Ds16OutCropLuma;
    CRCv10Striping1dOutputParams    ds4Ds16OutCropChroma;
    CRCv10Striping1dOutputParams    regOutCropLuma;
    CRCv10Striping1dOutputParams    regOutCropChroma;
    MNScaleDownInStruct_V20_1D      regMndsOutLuma;
    MNScaleDownInStruct_V20_1D      regMndsOutChroma;
    MNScaleDownInStruct_V20_1D      chromaDownOutChroma;
}
BpsStripingModule1dOutputStorage;

typedef struct _BpsStripingLibraryOutputPerStripe
{
    // fetch coordinates
    int16_t                                     fetchFirstPixel;
    int16_t                                     fetchLastPixel;

    // write coordinates
    int16_t                                     ds4ds16outFirstPixel;
    int16_t                                     ds4ds16outLastPixel;
    int16_t                                     fullDS4OutFirstPixel;
    int16_t                                     fullDS4OutLastPixel;
    int16_t                                     regOutFirstPixel;
    int16_t                                     regOutLastPixel;

    // flags
    BOOL                                        leftStripe;
    BOOL                                        rightStripe;

    BpsStripingModule1dOutputStorage            module1d;
    //==== generic ends here ====

    // TODO : remove (keep only enable bit) - start
        CRCv10StripingOutputParams              preRolloffCrop;
        CRCv10StripingOutputParams              preChromadownCropLuma;
        CRCv10StripingOutputParams              preChromadownCropChroma;
        CRCv10StripingOutputParams              fullDs4PreDs4CropLuma;
        CRCv10StripingOutputParams              fullDs4PreDs4CropChroma;
        CRCv10StripingOutputParams              ds4Ds16PreDs4CropLuma;
        CRCv10StripingOutputParams              ds4Ds16PreDs4CropChroma;
        CRCv10StripingOutputParams              regPreMndsCropLuma;
        CRCv10StripingOutputParams              regPreMndsCropChroma;
        CRCv10StripingOutputParams              fullDs4OutCropLuma;
        CRCv10StripingOutputParams              fullDs4OutCropChroma;
        CRCv10StripingOutputParams              ds4Ds16OutCropLuma;
        CRCv10StripingOutputParams              ds4Ds16OutCropChroma;
        CRCv10StripingOutputParams              regOutCropLuma;
        CRCv10StripingOutputParams              regOutCropChroma;
    // TODO : remove (keep only enable bit) - end

    Rolloffv34Pedestalv13StripingOutputParams   pedestal;
    Rolloffv34Pedestalv13StripingOutputParams   rolloff;
    RnrStripingOutputParams                     gic;
    RnrStripingOutputParams                     abf;
    PDPCv20v30stripingOutputParams              pdpc;
    BayerGridOutputParam                        bayerGrid;
    HNRv10StripingOutputParams                  hnr;

    // TODO : remove - start
        MNDSv20StripingOutputParams             reg_mnds_y_out;
        MNDSv20StripingOutputParams             reg_mnds_c_out;
        MNDSv20StripingOutputParams             chroma_down_c_out;
    // TODO : remove - end

    hdrOutStruct_v20                            hdr;
    HDRBayerHist_v13OutputParams                bayerHistParam;
    WriteEngineStripeParam                      bgStatsWriteEngineStripeParam;

    int32_t                                     qosBPScounter;
}
BpsStripingLibraryOutputPerStripe;

typedef struct _BpsStripingLibraryOutputPerPass
{
    /* pass-level parameters */
    // fetch coordinates
    int16_t                                     fetchFirstLine;
    int16_t                                     fetchLastLine;

    // write coordinates
    int16_t                                     ds4ds16outFirstLine;
    int16_t                                     ds4ds16outLastLine;
    int16_t                                     fullDS4OutFirstLine;
    int16_t                                     fullDS4OutLastLine;
    int16_t                                     regOutFirstLine;
    int16_t                                     regOutLastLine;

    // flags
    BOOL                                        topStripe;
    BOOL                                        bottomStripe;

    BpsStripingModule1dOutputStorage            module1d;
    //==== generic ends here

    WriteEnginePassParam                        bgStatsWriteEnginePassParam;
    int16_t                                     fullds4OutImageLumaWidth;
    int16_t                                     ds4ds16OutImageLumaWidth;
    int16_t                                     regOutImageLumaWidth;

    /* stripes */
    int16_t                                     numStripes;
    int32_t dummy_field_for_byte_padding;
    ListHandle                                  hStripeList;
}
BpsStripingLibraryOutputPerPass;

typedef struct
{
    /* frame-level parameters */

    /* passes */
    int32_t                                     numPasses;
    int32_t dummy_field_for_byte_padding;
    BpsStripingLibraryOutputPerPass*            passes;
}
BpsStripingLibraryOutputPerFrame;

typedef struct _BpsStripingLibraryInput
{
    // top level
    int16_t                                     tiering;

    int16_t                                     inputFormat;
    int16_t                                     inputWidth;
    int16_t                                     inputHeight;

    int16_t                                     fullDS4Format;
    int16_t                                     fullDS4OutWidth;
    int16_t                                     fullDS4OutHeight;

    int16_t                                     ds4ds16outFormat;
    int16_t                                     ds4ds16outWidth;
    int16_t                                     ds4ds16outHeight;

    int16_t                                     regOutFormat;
    int16_t                                     regOutWidth;
    int16_t                                     regOutHeight;

    int16_t dummy_field_for_byte_padding;

    BasicModuleInput                            abf;
    BasicModuleInput                            demosaic;
    MNDSv20StripingInputParams                  mndsReg;
    MNDSv20StripingInputParams                  chromaDown;
    Pedestalv13InputParams                      pedestal;
    RollOffv34InputParameters                   rolloff;
    HDRv20v30stripingInputParams                hdr;
    PDPCv20v30stripingInputParams               pdpcbpc;
    HDRBayerHist_v13InputParams                 hdrBhist;
    BayerGridInputParam                         bayerGrid;
    HNRInputParam                               hnr;
    GICv30InputParams                           gic;
}
BpsStripingLibraryInput;


#endif /* _STRIPEBPSPPS_H_ */
