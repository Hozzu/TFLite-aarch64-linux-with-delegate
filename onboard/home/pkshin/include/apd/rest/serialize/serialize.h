// --------------------------------------------------------------------------
// |              _    _ _______     .----.      _____         _____        |
// |         /\  | |  | |__   __|  .  ____ .    / ____|  /\   |  __ \       |
// |        /  \ | |  | |  | |    .  / __ \ .  | (___   /  \  | |__) |      |
// |       / /\ \| |  | |  | |   .  / / / / v   \___ \ / /\ \ |  _  /       |
// |      / /__\ \ |__| |  | |   . / /_/ /  .   ____) / /__\ \| | \ \       |
// |     /________\____/   |_|   ^ \____/  .   |_____/________\_|  \_\      |
// |                              . _ _  .                                  |
// --------------------------------------------------------------------------
//
// All Rights Reserved.
// Any use of this source code is subject to a license agreement with the
// AUTOSAR development cooperation.
// More information is available at www.autosar.org.
//
// Disclaimer
//
// This work (specification and/or software implementation) and the material
// contained in it, as released by AUTOSAR, is for the purpose of information
// only. AUTOSAR and the companies that have contributed to it shall not be
// liable for any use of the work.
//
// The material contained in this work is protected by copyright and other
// types of intellectual property rights. The commercial exploitation of the
// material contained in this work requires a license to such intellectual
// property rights.
//
// This work may be utilized or reproduced without any modification, in any
// form or by any means, for informational purposes only. For any other
// purpose, no part of the work may be utilized or reproduced, in any form
// or by any means, without permission in writing from the publisher.
//
// The work has been developed for automotive applications only. It has
// neither been developed, nor tested for non-automotive applications.
//
// The word AUTOSAR and the AUTOSAR logo are registered trademarks.
// --------------------------------------------------------------------------

#ifndef LIB_APDREST_INCLUDE_APD_REST_SERIALIZE_SERIALIZE_H_
#define LIB_APDREST_INCLUDE_APD_REST_SERIALIZE_SERIALIZE_H_

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include <rapidjson/document.h>
#include <iostream>
#include <vector>

#include "apd/rest/ogm/array.h"
#include "apd/rest/ogm/copy.h"
#include "apd/rest/ogm/field.h"
#include "apd/rest/ogm/int.h"
#include "apd/rest/ogm/object.h"
#include "apd/rest/ogm/real.h"
#include "apd/rest/ogm/string.h"
#include "apd/rest/ogm/uri.h"
#include "apd/rest/ogm/uuid.h"
#include "apd/rest/ogm/visit.h"
#include "apd/rest/pointer.h"
#include "apd/rest/string.h"
#include "apd/rest/uuid.h"

namespace apd
{
namespace rest
{
namespace serialize
{
/**
 * \brief This class for serializer functionality
 */
class Serializer
{
public:
    /**
     * \brief parse JSON string.
     *
     * \return ogm::Object pointer.
     * \param json_string
     */
    static Pointer<ogm::Object> JsonToOgm(String json_string);

    /**
     * \brief creates json document from ogm::Object.
     *
     * \param ogm_object .
     * \return json string.
     */
    static String OgmToJson(const Pointer<ogm::Object>& ogm_object);

private:
    /**
     * \brief constructor. (added to avoid class instantiation)
     *
     */
    Serializer();

    /**
     * \brief creates ogm array from  json Object.
     *
     * \param array .
     * \param obj_name .
     * \return ogm::Array pointer.
     */
    static Pointer<ogm::Array> CreateOgmArray(const rapidjson::Value& array, String obj_name);

    /**
     * \brief creates ogm::Object from parsed json string.
     *
     * \param array_obj The rapidjson object to json string.
     * \return ogm::Object pointer.
     * \uptrace{SWS_REST_01853}
     * \uptrace{SWS_REST_01854}
     * \uptrace{SWS_REST_01855}
     * \uptrace{SWS_REST_01856}
     * \uptrace{SWS_REST_01857}
     * \uptrace{SWS_REST_01858}
     */
    static Pointer<ogm::Object> CreateOgmNode(const rapidjson::Value& array_obj);

    /**
     * \brief creates json document from ogm::Object.
     *
     * \param ogm_object .
     * \param document The rapidjson object
     * \uptrace{SWS_REST_01853}
     * \uptrace{SWS_REST_01854}
     * \uptrace{SWS_REST_01855}
     * \uptrace{SWS_REST_01856}
     * \uptrace{SWS_REST_01857}
     * \uptrace{SWS_REST_01858}
     */
    static void createJsonObject(const Pointer<ogm::Object>& ogm_object, rapidjson::Document& document);
    /**
     * \brief creates json string from json document.
     *
     * \param document The rapidjson object
     * \return json string.
     */
    static String GetJsonString(rapidjson::Document& document);
};
}  // namespace serialize
}  // namespace rest
}  // namespace apd

#endif  // LIB_APDREST_INCLUDE_APD_REST_SERIALIZE_SERIALIZE_H_
