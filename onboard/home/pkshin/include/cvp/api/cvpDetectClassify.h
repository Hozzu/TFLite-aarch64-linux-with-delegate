/**=============================================================================

@file
   cvpDetectClassify.h

@brief
   API Definitions for Detection and Classification

Copyright (c) 2017-2018 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.

=============================================================================**/

//=============================================================================
///@details CVP Detection and Classification APIs using Computer Vision Processor acceleration
///    The pipeline is described below
///     Y --> Feature Point Extractor (FPX) -> FPX (Peak 8x8) out (optional)
///        |
///        |                Templates
///        |                    |
///        |-> Detector --> Classifier -> Classification output
///
///@ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//=============================================================================

#ifndef CVP_DETECTION_CLASSIFICATION_H
#define CVP_DETECTION_CLASSIFICATION_H

#include "cvpTypes.h"
#include "cvpFeaturePoint.h"

#define CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_OCTAVES           (3)
#define CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_SCALES_PER_OCTAVE (3)
#define CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_LEVELS            (CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_OCTAVES * CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_SCALES_PER_OCTAVE + 1)

#ifdef __cplusplus
extern "C"
{
#endif

//------------------------------------------------------------------------------
/// @brief
///    Structure representing Detector Classifier pipeline output.
/// @param sClassifierOut
///    Output structure for the classification process.
///    The nLevels are equal to (nOctaves * nScalesPerOctave) + 1.
/// @param sFpxOut
///    Output structure for the Feature Point Extraction process. The FPX mode
///    is CVP_FPX_PEAK_8x8.
/// @param bValidClassifier
///    Boolean value showing whether Classifier output is valid.
/// @param bValidFpx
///    Boolean value showing whether Feature Point Extraction output is valid.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
typedef struct _cvpDetectionClassificationOutput
{
   cvpPyramidu16         sClassifierOut;
   cvpFeaturePointOutput sFpxOut;
   bool                  bValidClassifier;
   bool                  bValidFpx;

   #ifdef __cplusplus
   INLINE _cvpDetectionClassificationOutput() : bValidClassifier(false), bValidFpx(false){}
   #endif
} cvpDetectionClassificationOutput;

//------------------------------------------------------------------------------
/// @brief
///    Enumeration representing Detector output channel options.
/// @param CVP_DETECTOR_36_CHANNELS
///    36 channels output.
/// @param CVP_DETECTOR_13_CHANNELS
///    13 channels output.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef enum _cvpDetectorChannel
{
   CVP_DETECTOR_36_CHANNELS,
   CVP_DETECTOR_13_CHANNELS
} cvpDetectorChannel;

//------------------------------------------------------------------------------
/// @brief
///    Structure for detector configuration.
/// @param sImageInfo
///    Structure for image information.
/// @param nOctaves
///    Number of octaves. Image size is halved between ajacent octaves.
/// @param nScalesPerOctave
///    Number of scales per octave. Total scales = num_oct*num_scales+1
/// @param eOutChannels
///    Output channels option.
///
/// @ingroup cvp_object_detection
//------------------------------------------------------------------------------
typedef struct _cvpConfigDetector
{
   cvpImageInfo       sImageInfo;
   uint8_t            nOctaves;
   uint8_t            nScalesPerOctave;
   cvpDetectorChannel eOutChannels;

   #ifdef __cplusplus
   INLINE _cvpConfigDetector() : nOctaves(0), nScalesPerOctave(0), eOutChannels(CVP_DETECTOR_36_CHANNELS){}
   #endif
} cvpConfigDetector;

//------------------------------------------------------------------------------
/// @brief
///    Structure for Classifier configuration.
/// @param nIntPrec
///    Classifier integer precision. The number of integer bits in the final output width
///    and the rest are fractional bits.  Must be >= 1.
///
/// @ingroup cvp_machine_learning
//------------------------------------------------------------------------------
typedef struct _cvpConfigClassifier
{
    uint8_t nIntPrec;

   #ifdef __cplusplus
   INLINE _cvpConfigClassifier() : nIntPrec(1){}
   #endif
} cvpConfigClassifier;

//------------------------------------------------------------------------------
/// @brief
///    Structure for classifier packet information.
/// @param pTemplateData
///    Pointer to the model data and bias. The size of pTemplateData depends on
///    cvpDetectorChannel. There is alignment requirement to the cvpDetectorChannel.
///    For CVP_DETECTOR_36_CHANNELS, channelAlignment is equal to 8.
///    For CVP_DETECTOR_13_CHANNELS, channelAlignment is equal to 16.
///    The buffer structure contains all template data with int16_t type followed
///    by all the bias with int32_t type.
///    The size = (nTemplateWidth * nTemplateHeight * channelAlignment *
///    nTemplates * sizeof(int16_t)) + (nTemplates * sizeof(int32_t))
/// @param nTemplateWidth
///    Templates width.
/// @param nTemplateHeight
///    Templates height.
/// @param nTemplates
///    Number of templates.
///
/// @ingroup cvp_machine_learning
//------------------------------------------------------------------------------
typedef struct _cvpClassifierPacket
{
   uint8_t  *pTemplateData;
   uint32_t  nTemplateWidth;
   uint32_t  nTemplateHeight;
   uint32_t  nTemplates;

   #ifdef __cplusplus
   INLINE _cvpClassifierPacket() : pTemplateData(NULL), nTemplateWidth(0), nTemplateHeight(0),
                                   nTemplates(0){}
   #endif
} cvpClassifierPacket;

//------------------------------------------------------------------------------
/// @brief
///    Enumeration for output enablement.
/// @param CVP_OUTPUT_MODE_CLASSIFIER
///    Enable output for classifier. The input for Classifier is from Detector in the hardware pipeline
/// @param CVP_OUTPUT_MODE_CLASSIFIER_FPX
///    Enable output for both Feature Point Extraction (FPX) and Classifier.
///    The input for Classifier is from Detector in the hardware pipeline
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
typedef enum
{
   CVP_OUTPUT_MODE_CLASSIFIER,
   CVP_OUTPUT_MODE_CLASSIFIER_FPX
} cvpDetectionClassificationMode;

//------------------------------------------------------------------------------
/// @brief
///    The Detector Classifier pipeline has been processed by the CVP system, and the
///    output is ready to be consumed. This callback is used to notify the
///    application. The application sends the image using the
///    cvpDetectionClassification_Async call.
///
/// @param eStatus
///    CVP status for the current process.
/// @param pOutput
///    Pointer to the Detector Classifier pipeline ouput structure.
/// @param hDetectorClassifier
///    Handle for the Detector Classifier pipeline that was passed in the
///    cvpDetectionClassification_Async function.
/// @param pSessionUserData
///    User-data that was set in the cvpConfigDetectorClassifier structure.
/// @param pTaskUserData
///    User-data that was passed in the cvpDetectionClassification_Async function
///    which corresponds to this callback.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
typedef void (*CvpDetectionClassificationCb)(cvpStatus                         eStatus,
                                             cvpDetectionClassificationOutput *pOutput,
                                             cvpHandle                         hDetectorClassifier,
                                             void                             *pSessionUserData,
                                             void                             *pTaskUserData);

//------------------------------------------------------------------------------
/// @brief
///    Configuration structure for CVP - Detection Classification pipeline.
///    It contains Feature Point Extraction (FPX), Detector, and Classifier.
///
/// @param sDetectorConfig
///    Structure for Detector config.
/// @param sClassifierConfig
///    Structure for Classifier config.
/// @param eMode
///    Mode option for Feature Point Extraction, Detector or Classifier.
/// @param nRobustness
///    This parameter controls the robustness of the feature point detector.
///    Lower robustness setting produces more candidate feature points and vice versa.
///    Valid range is 0 to 127. Default value is 10.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
typedef struct _cvpConfigDetectorClassifier
{
   cvpConfigDetector              sDetectorConfig;
   cvpConfigClassifier            sClassifierConfig;
   cvpDetectionClassificationMode eMode;
   uint8_t                        nRobustness;

   #ifdef __cplusplus
   INLINE _cvpConfigDetectorClassifier() : eMode(CVP_OUTPUT_MODE_CLASSIFIER), nRobustness(10){}
   #endif
} cvpConfigDetectorClassifier;

//------------------------------------------------------------------------------
/// @brief
///    Structure for Detection Classification output buffer requirement
/// @param nClassifierBytesPerTemplate
///    The required size in bytes for pyramid Classification output data for each
///    classification template. The total
///    cvpDetectionClassificationOutput.sClassifierOut.pPyramidLevel[i].pData will be
///    equal to nClassifierBytesPerTemplate[i] * cvpClassifierPacket.nTemplates.
/// @param nClassifierLevels
///    Number of Classifier pyramid levels.
/// @param nFeaturePointBytes
///    The required size in bytes for feature point output
///    (cvpDetectionClassificationOutput.sFpxOut.pPoints)
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
typedef struct _cvpDetectionClassificationOutBuffReq
{
   uint32_t nClassifierBytesPerTemplate[CVP_MAX_PYRAMID_DETECTOR_CLASSIFIER_LEVELS];
   uint32_t nClassifierLevels;
   uint32_t nFeaturePointBytes;

   #ifdef __cplusplus
   INLINE _cvpDetectionClassificationOutBuffReq() : nClassifierLevels(0), nFeaturePointBytes(0)

   {
      memset(nClassifierBytesPerTemplate, 0, sizeof(nClassifierBytesPerTemplate));
   };
   #endif
} cvpDetectionClassificationOutBuffReq;

//------------------------------------------------------------------------------
/// @brief
///    Initialize CVP - Feature Point Extraction, Detector, Classifier pipeline.
/// @param hSession
///    [Input] CVP session handle
/// @param pConfig
///    [Input] Pointer to the configuration.
/// @param pOutMemReq
///    [Output] Pointer to the output memory requirement.
/// @param nFps
///    [Input] CVP Frames per Second.
/// @param fnCb
///    [Input] Callback function for the asynchronous API
///    Setting to NULL will result in initializing for synchronous API
/// @param pSessionUserData
///    [Input] A private pointer the user can set with this session, and this
///    pointer will be provided as parameter to all callback functions
///    originated from the current session. This could be used to associate a
///    callback to this session. This can only be set once while initializing
///    the handle. This value will not/cannot-be changed for life
///    of a session.
///
/// @retval CVP handle for Detection Classification pipeline
///    If successful.
/// @retval NULL
///    If initialization failed.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
CVP_API cvpHandle cvpInitDetectionClassification(cvpSession                           hSession,
                                                 const cvpConfigDetectorClassifier    *pConfig,
                                                 cvpDetectionClassificationOutBuffReq *pOutMemReq,
                                                 uint32_t                              nFps,
                                                 CvpDetectionClassificationCb          fnCb,
                                                 void                                 *pSessionUserData);

//------------------------------------------------------------------------------
/// @brief
///    Deinitialize CVP - Feature Point Extraction, Detector, Classifier pipeline.
/// @param hDetectorClassifier
///    [Input] CVP handle for Detection Classification pipeline
///
/// @retval CVP_SUCCESS
///    If deinit is successful.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDeInitDetectionClassification(cvpHandle hDetectorClassifier);

//------------------------------------------------------------------------------
/// @brief
///    Feature Point Extraction, Detector, Classifier pipeline.
/// @details
///    Synchronous (blocking) function that will do Detection Classification pipeline.
/// @param hDetectorClassifier
///    [Input] Handle for the Detection Classification pipeline.
/// @param pImage
///    [Input] Pointer to the CVP image.
/// @param nFpxScoreShift
///    [Input] FPX measure shift value. This value can be calculated by calling
///    cvpGetFpxMeasureShift() using pOutput->sFpxOut.nMaxFpxMeasure in
///    previous result. It's suggested to set to 8 for the first call.
/// @param nFpxThreshold
///    [Input] Threshold to filter the feature point measurement.
/// @param pClassifierInfo
///    [Input] Pointer to the Classifier packet information.
///    If NULL, Classifier will be skipped.
/// @param pOutput
///    [Output] Pointer to the pipeline ouput structure.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDetectionClassification_Sync(cvpHandle                         hDetectorClassifier,
                                                  const cvpImage                   *pImage,
                                                  uint32_t                          nFpxScoreShift,
                                                  uint32_t                          nFpxThreshold,
                                                  const cvpClassifierPacket        *pClassifierInfo,
                                                  cvpDetectionClassificationOutput *pOutput);

//------------------------------------------------------------------------------
/// @brief
///    Feature Point Extraction, Detector, Classifier pipeline.
/// @details
///    Asynchronous function that will queue the image and return almost
///    immediately. In the background, it will do Detection Classification pipeline.
///    Once the output is ready, it will notify the user through the callback
///    function and user can queue another image using the same buffer.
/// @param hDetectorClassifier
///    [Input] Handle for the Detection Classification pipeline.
/// @param pImage
///    [Input] Pointer to the CVP image.
/// @param nFpxScoreShift
///    [Input] FPX measure shift value. This value can be calculated by calling
///    cvpGetFpxMeasureShift() using pOutput->sFpxOut.nMaxFpxMeasure in
///    previous result. It's suggested to set to 8 for the first call.
/// @param nFpxThreshold
///    [Input] Threshold to filter the feature point measurement.
/// @param pClassifierInfo
///    [Input] Pointer to the Classifier packet information.
///    If NULL, Classifier will be skipped.
/// @param pOutput
///    [Output] Pointer to the pipeline ouput structure which corresponds
///    to the callback.
/// @param pTaskUserData
///    [Input] User-data which corresponds to the callback.
///
/// @retval CVP_SUCCESS
///    If the image is successfully pushed to the queue. It will be processed
///    immediately.
/// @retval CVP_EBADPARAM
///    If there is any bad parameter
/// @retval CVP_EUNSUPPORTED
///    If the handle is initialized for synchronous API.
///
/// @ingroup cvp_feature_detection, cvp_object_detection, cvp_machine_learning
//------------------------------------------------------------------------------
CVP_API cvpStatus cvpDetectionClassification_Async(cvpHandle                         hDetectorClassifier,
                                                   const cvpImage                   *pImage,
                                                   uint32_t                          nFpxScoreShift,
                                                   uint32_t                          nFpxThreshold,
                                                   const cvpClassifierPacket        *pClassifierInfo,
                                                   cvpDetectionClassificationOutput *pOutput,
                                                   const void                       *pTaskUserData);

#ifdef __cplusplus
}//extern "C"
#endif

#endif
