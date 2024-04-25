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

#ifndef DPDUAPI_INTERFACE_H_
#define DPDUAPI_INTERFACE_H_

#include <stdint.h>

#ifdef _PDUAPI_EXPORT
#    define EXTERNC extern "C"
#else  // _PDUAPI_EXPORT
#    define EXTERNC /* EXTERNC */
#endif  // _PDUAPI_EXPORT

typedef uint8_t UNUM8; /* Unsigned numeric 8 bits.*/
typedef int8_t SNUM8; /* Signed numeric 8 bits.*/
typedef uint16_t UNUM16; /* Unsigned numeric 16 bits.*/
typedef int16_t SNUM16; /* Signed numeric 16 bits.*/
typedef uint32_t UNUM32; /* Unsigned numeric 32 bits.*/
typedef int32_t SNUM32; /* Signed numeric 32 bits.*/
typedef char CHAR8; /* ASCII-coded 8-bit character value (ISO 8859-1 (Latin 1)).*/

const UNUM32 PDU_ID_UNDEF = 0xFFFFFFFE; /* Undefined ID value. Used to indicate
                                           an ID value is undefined.*/
const UNUM32 PDU_HANDLE_UNDEF = 0xFFFFFFFF; /* Undefined handle value. Used to indicate a Handle value is
                                               undefined. */

typedef enum E_PDU_IT
{
    PDU_IT_IO_UNUM32 = 0x1000, /* IOCTL UNUM32 item. */
    PDU_IT_IO_PROG_VOLTAGE = 0x1001, /* IOCTL Program Voltage item. */
    PDU_IT_IO_BYTEARRAY = 0x1002, /* IOCTL Byte Array item. */
    PDU_IT_IO_FILTER = 0x1003, /* IOCTL Filter item. */
    PDU_IT_IO_EVENT_QUEUE_PROPERTY = 0x1004, /* IOCTL Event Queue Property item. */
    PDU_IT_RSC_STATUS = 0x1100, /* Resource Status item */
    PDU_IT_PARAM = 0x1200, /* ComParam item */
    PDU_IT_RESULT = 0x1300, /* Result item */
    PDU_IT_STATUS = 0x1301, /* Status notification item */
    PDU_IT_ERROR = 0x1302, /* Error notification item */
    PDU_IT_INFO = 0x1303, /* Information notification item */
    PDU_IT_RSC_ID = 0x1400, /* Resource ID item */
    PDU_IT_RSC_CONFLICT = 0x1500, /* Resource Conflict Item */
    PDU_IT_MODULE_ID = 0x1600, /* Module item */
    PDU_IT_UNIQUE_RESP_ID_TABLE = 0x1700, /* Unique Response Id Table Item */
} T_PDU_IT;

typedef enum E_PDU_COPT
{
    PDU_COPT_STARTCOMM = 0x8001,
    PDU_COPT_STOPCOMM = 0x8002,
    PDU_COPT_UPDATEPARAM = 0x8003,
    PDU_COPT_SENDRECV = 0x8004,
    PDU_COPT_DELAY = 0x8005,
    PDU_COPT_RESTORE_PARAM = 0x8006
} T_PDU_COPT;

typedef enum E_PDU_OBJT
{
    PDU_OBJT_PROTOCOL = 0x8021, /* Object type for object PROTOCOL of MDF.*/
    PDU_OBJT_BUSTYPE = 0x8022, /* Object type for object BUSTYPE of MDF.*/
    PDU_OBJT_IO_CTRL = 0x8023, /* Object type for object IO_CTRL of MDF.*/
    PDU_OBJT_COMPARAM = 0x8024, /* Object type for object COMPARAM of MDF.*/
    PDU_OBJT_PINTYPE = 0x8025, /* Object type for object PINTYPE of MDF.*/
    PDU_OBJT_RESOURCE = 0x8026 /* Object type for object RESOURCE of MDF.*/
} T_PDU_OBJT;

typedef enum E_PDU_STATUS
{
    /* ComPrimitive status */
    PDU_COPST_IDLE = 0x8010,
    PDU_COPST_EXECUTING = 0x8011,
    PDU_COPST_FINISHED = 0x8012,
    PDU_COPST_CANCELLED = 0x8013,
    PDU_COPST_WAITING = 0x8014,
    /* ComLogicalLink status */
    PDU_CLLST_OFFLINE = 0x8050,
    PDU_CLLST_ONLINE = 0x8051,
    PDU_CLLST_COMM_STARTED = 0x8052,
    /* Module status */
    PDU_MODST_READY = 0x8060,
    PDU_MODST_NOT_READY = 0x8061,
    PDU_MODST_NOT_AVAIL = 0x8062,
    PDU_MODST_AVAIL = 0x8063,
} T_PDU_STATUS;

typedef enum E_PDU_INFO
{
    PDU_INFO_MODULE_LIST_CHG = 0x8070,
    PDU_INFO_RSC_LOCK_CHG = 0x8071,
    PDU_INFO_PHYS_COMPARAM_CHG = 0x8072
} T_PDU_INFO;

typedef enum E_PDU_EVT_DATA
{
    PDU_EVT_DATA_AVAILABLE = 0x0801,
    PDU_EVT_DATA_LOST = 0x0802
} T_PDU_EVT_DATA;

typedef enum E_PDU_FILTER
{
    PDU_FLT_PASS = 0x00000001,
    PDU_FLT_BLOCK = 0x00000002,
    PDU_FLT_PASS_UUDT = 0x00000011,
    PDU_FLT_BLOCK_UUDT = 0x00000012
} T_PDU_FILTER;

typedef enum E_PDU_QUEUE_MODE
{
    PDU_QUE_UNLIMITED = 0x00000000, /* In Unlimited Mode, the QueueSize is ignored.*/
    PDU_QUE_LIMITED = 0x00000001, /* When the ComLogicalLink's event queue is full, no new items
                                     are placed on the event queue.*/
    PDU_QUE_CIRCULAR = 0x00000002 /* When the ComLogicalLink's event queue is full (i.e. maximum
                                     size has been reached), then the oldest event item in the
                                     queue is deleted so that the new event item can then be
                                     placed in the event queue.*/
} T_PDU_QUEUE_MODE;

typedef enum E_PDU_ERROR
{
    PDU_STATUS_NOERROR = 0x00000000, /* No error for the function call */
    PDU_ERR_FCT_FAILED = 0x00000001, /* Function call failed (generic failure) */
    PDU_ERR_RESERVED_1 = 0x00000010, /* Reserved by ISO 22900-2 */
    PDU_ERR_COMM_PC_TO_VCI_FAILED = 0x00000011, /* Communication between host and
                                                   MVCI protocol module failed */
    PDU_ERR_PDUAPI_NOT_CONSTRUCTED = 0x00000020, /* The D-PDU API has not yet been constructed */
    PDU_ERR_SHARING_VIOLATION = 0x00000021, /* A PDUDestruct was not called before another PDUConstruct */
    PDU_ERR_RESOURCE_BUSY = 0x00000030, /* the requested resource is already in use.*/
    PDU_ERR_RESOURCE_TABLE_CHANGED = 0x00000031, /* Not used by the D-PDU API */
    PDU_ERR_RESOURCE_ERROR = 0x00000032, /* Not used by the D-PDU API */
    PDU_ERR_CLL_NOT_CONNECTED = 0x00000040, /* The ComLogicalLink cannot be in the PDU_CLLST_OFFLINE state
                                               to perform the requested operation.*/
    PDU_ERR_CLL_NOT_STARTED = 0x00000041, /* The ComLogicalLink must be in the PDU_CLLST_COMM_STARTED
                                             state to perform the requested operation. */
    PDU_ERR_INVALID_PARAMETERS = 0x00000050, /* One or more of the parameters supplied in the function are
                                                invalid. */
    PDU_ERR_INVALID_HANDLE = 0x00000060, /* One or more of the handles supplied in
                                            the function are invalid. */
    PDU_ERR_VALUE_NOT_SUPPORTED = 0x00000061, /* One of the option values in PDUConstruct is invalid. */
    PDU_ERR_ID_NOT_SUPPORTED = 0x00000062, /* IOCTL command id not supported by the implementation of the
                                              D-PDU API */
    PDU_ERR_COMPARAM_NOT_SUPPORTED = 0x00000063, /* ComParam id not supported by the implementation of the
                                                    D-PDU API */
    PDU_ERR_COMPARAM_LOCKED = 0x00000064, /* Physical ComParam cannot be changed because it is locked by
                                             another ComLogicalLink. */
    PDU_ERR_TX_QUEUE_FULL = 0x00000070, /* The ComLogicalLink's transmit queue is full; the
                                           ComPrimitive could not be queued. */
    PDU_ERR_EVENT_QUEUE_EMPTY = 0x00000071, /* No more event items are available to be read from the
                                               requested queue. */
    PDU_ERR_VOLTAGE_NOT_SUPPORTED = 0x00000080, /* The voltage value supplied in the IOCTL call is not
                                                   supported by the MVCI protocol module. */
    PDU_ERR_MUX_RSC_NOT_SUPPORTED = 0x00000081, /* The specified pin / resource are not supported by the MVCI
                                                   protocol module for the IOCTL call. */
    PDU_ERR_CABLE_UNKNOWN = 0x00000082, /* The cable attached to the MVCI protocol
                                           module is of an unknown type. */
    PDU_ERR_NO_CABLE_DETECTED = 0x00000083, /* No cable is detected by the MVCI protocol module */
    PDU_ERR_CLL_CONNECTED = 0x00000084, /* The ComLogicalLink is already in the
                                           PDU_CLLST_ONLINE state. */
    PDU_ERR_TEMPPARAM_NOT_ALLOWED = 0x00000090, /* Physical ComParams cannot be changed as a temporary
                                                   ComParam. */
    PDU_ERR_RSC_LOCKED = 0x000000A0, /* The resource is already locked. */
    PDU_ERR_RSC_LOCKED_BY_OTHER_CLL = 0x000000A1, /* The ComLogicalLink's resource is currently locked by
                                                     another ComLogicalLink. */
    PDU_ERR_RSC_NOT_LOCKED = 0x000000A2, /* The resource is already in the unlocked state. */
    PDU_ERR_MODULE_NOT_CONNECTED = 0x000000A3, /* The module is not in the PDU_MODST_READY state. */
    PDU_ERR_API_SW_OUT_OF_DATE = 0x000000A4, /* The API software is older than the
                                                MVCI protocol module Software*/
    PDU_ERR_MODULE_FW_OUT_OF_DATE = 0x000000A5, /* The MVCI protocol module software is older than the API
                                                   software. */
    PDU_ERR_PIN_NOT_CONNECTED = 0x000000A6 /* The requested Pin is not routed by supported cable */
} T_PDU_ERROR;

typedef enum E_PDU_ERR_EVT
{
    PDU_ERR_EVT_NOERROR = 0x00000000, /* No Error. Event type only returned on a PDUGetLastError if
                                         there were no previous errors for the requested handle */
    PDU_ERR_EVT_FRAME_STRUCT = 0x00000100, /* CLL/CoP Error: The structure of the received protocol frame
                                              is incorrect (e.g. wrong frame number, missing FC �). */
    PDU_ERR_EVT_TX_ERROR = 0x00000101, /* CLL/CoP Error: Error encountered during
                                          transmit of a ComPrimitive PDU. */
    PDU_ERR_EVT_TESTER_PRESENT_ERROR = 0x00000102, /* CLL/CoP Error: Error encountered in transmitting a Tester
                                                      Present message or in receiving an expected response to a
                                                      Tester Present message. */
    PDU_ERR_EVT_RX_TIMEOUT = 0x00000103, /* CLL/CoP Error: Receive timer (e.g. P2Max) expired with no
                                            expected responses received from the vehicle.*/
    PDU_ERR_EVT_RX_ERROR = 0x00000104, /* CLL/CoP Error: Error encountered in receiving a message
                                          from the vehicle bus (e.g. checksum error �). */
    PDU_ERR_EVT_PROT_ERR = 0x00000105, /* CLL/CoP Error: Protocol error encountered during handling
                                          of a ComPrimitive (e.g. if the protocol cannot handle the
                                          length of a ComPrimitive).*/
    PDU_ERR_EVT_LOST_COMM_TO_VCI = 0x00000106, /* Module Error: Communication to a MVCI protocol module has
                                                  been lost.*/
    PDU_ERR_EVT_VCI_HARDWARE_FAULT = 0x00000107, /* Module Error: The MVCI protocol module has detected a
                                                    hardware error.*/
    PDU_ERR_EVT_INIT_ERROR = 0x00000108, /* CLL/CoP Error: A failure occurred during a protocol
                                            initialization sequence. */
    PDU_ERR_EVT_RSC_LOCKED = 0x00000109 /* CLL Error: A physical ComParam was not set because of a
                                           physical ComParam lock. */
} T_PDU_ERR_EVT;

typedef enum E_PDU_PC
{
    PDU_PC_UNDEFINED = 0,
    PDU_PC_TIMING = 1,
    PDU_PC_INIT = 2,
    PDU_PC_COM = 3,
    PDU_PC_ERRHDL = 4,
    PDU_PC_BUSTYPE = 5,
    PDU_PC_UNIQUE_ID = 6,
    PDU_PC_TESTER_PRESENT = 7
} T_PDU_PC;

typedef enum E_PDU_PT
{
    PDU_PT_UNDEFINED = 0x00000000,
    PDU_PT_UNUM8 = 0x00000101, /* Unsigned byte */
    PDU_PT_SNUM8 = 0x00000102, /* Signed byte */
    PDU_PT_UNUM16 = 0x00000103, /* Unsigned two bytes */
    PDU_PT_SNUM16 = 0x00000104, /* Signed two bytes */
    PDU_PT_UNUM32 = 0x00000105, /* Unsigned four bytes */
    PDU_PT_SNUM32 = 0x00000106, /* Signed four bytes */
    PDU_PT_BYTEFIELD = 0x00000107, /* Structure contains an array of UNUM8 bytes with a maximum
                                      length and actual length fields. See ComParam BYTEFIELD
                                      data type for the definition. */
    PDU_PT_STRUCTFIELD = 0x00000108, /* Structure contains a void * pointer to an array of
                                        structures. The ComParamStructType item determines the type
                                        of structure to be typecasted onto the void * pointer. This
                                        structure contains a field for maximum number of struct
                                        entries and the actual number of struct entries. See
                                        ComParam STRUCTFIELD data type for the definition. */
    PDU_PT_LONGFIELD = 0x00000109 /* Structure contains an array of UNUM32 entries with a maximum
                                     length and actual length fields. See ComParam LONGFIELD Data
                                     Type for the definition. */
} T_PDU_PT;

typedef enum E_PDU_CPST
{
    PDU_CPST_SESSION_TIMING = 0x00000001, /* \see PDU_PARAM_STRUCT_SESS_TIMING*/
    PDU_CPST_ACCESS_TIMING = 0x00000002 /* \see PDU_PARAM_STRUCT_ACCESS_TIMING*/
} T_PDU_CPST;

typedef struct
{
    T_PDU_IT ItemType; /* See T_PDU_IT.*/
} PDU_ITEM;

typedef struct
{
    T_PDU_IT ItemType; /* Value= one of the IOCTL constants from T_PDU_IT (\ref
                          E_PDU_IT).*/
    void* pData; /* Pointer to the specific IOCTL data structure.*/
} PDU_DATA_ITEM;

typedef struct
{
    UNUM32 ProgVoltage_mv; /* Programming voltage [mV].*/
    UNUM32 PinOnDLC; /* Pin number on Data Link Connector.*/
} PDU_IO_PROG_VOLTAGE_DATA;

typedef struct
{
    UNUM32 DataSize; /* Number of bytes in the data array.*/
    UNUM8* pData; /* Pointer to the data array.*/
} PDU_IO_BYTEARRAY_DATA;

typedef struct
{
    T_PDU_FILTER
    FilterType; /* type of filter being configured \see T_PDU_FILTER.*/
    UNUM32 FilterNumber; /* Filter Number. Used to replace filters and stop
                            filters.*/
    UNUM32 FilterCompareSize; /* Number of bytes used out of each of the filter
                                 messages arrays Range 1-12.*/
    UNUM8 FilterMaskMessage[12]; /* Mask message to be ANDed to each incoming
                                    message.*/
    UNUM8 FilterPatternMessage[12]; /* Pattern message to be compared to the
                                       incoming message after the
                                       FilterMaskMessage has been applied.*/
} PDU_IO_FILTER_DATA;

typedef struct
{
    UNUM32
    NumFilterEntries; /* Number of Filter entries in the filter list array.*/
    PDU_IO_FILTER_DATA* pFilterData; /* Pointer to an array of filter data.*/
} PDU_IO_FILTER_LIST;

typedef struct
{
    UNUM32 QueueSize; /* Maximum size of event queue. */
    T_PDU_QUEUE_MODE QueueMode; /* Queue mode. see T_PDU_QUEUE_MODE event queue
                                   mode type values.*/
} PDU_IO_EVENT_QUEUE_PROPERTY_DATA;

typedef struct
{
    UNUM32 hMod; /* Handle of a MVCI protocol module (IN parameter).*/
    UNUM32 ResourceId; /*  ID (IN parameter).*/
    UNUM32 ResourceStatus; /* Resource Information Status (OUT Parameter).*/
} PDU_RSC_STATUS_DATA;

typedef struct
{
    T_PDU_IT ItemType; /*! value=PDU_IT_RSC_STATUS (IN parameter).*/
    UNUM32
    NumEntries; /* number of entries in pResourceStatusData  (IN Parameter).*/
    PDU_RSC_STATUS_DATA* pResourceStatusData; /* array to contain resource status (IN Parameter).*/
} PDU_RSC_STATUS_ITEM;

typedef struct
{
    T_PDU_IT ItemType; /* value= PDU_IT_PARAM.*/
    UNUM32 ComParamId; /* ComParam Id.*/
    T_PDU_PT ComParamDataType; /* Defines the data type of the ComParam \ref
                                  T_PDU_PT; ComParam data type.*/
    T_PDU_PC ComParamClass; /* ComParam Class type.*/
    void* pComParamData; /* pointer to ComParam data of type ComParamDataType.*/
} PDU_PARAM_ITEM;

typedef struct
{
    UNUM32 ModuleTypeId; /* MVCI protocol moduleTypeId.*/
    UNUM32 hMod; /* handle of MVCI protocol module assigned by D-PDU.*/
    CHAR8* pVendorModuleName; /* Vendor specific information string for the unique
                                 module identification.*/
    CHAR8* pVendorAdditionalInfo; /* Vendor specific additional information string.*/
    T_PDU_STATUS ModuleStatus; /* Status of MVCI protocol module detected by D-PDU
                                  API session.*/
} PDU_MODULE_DATA;

typedef struct
{
    T_PDU_IT ItemType; /* value= PDU_IT_MODULE_ID */
    UNUM32 NumEntries; /* number of entries written to the pModuleData array */
    PDU_MODULE_DATA* pModuleData; /* pointer to array containing module types and
                                     module handles */
} PDU_MODULE_ITEM;

typedef struct
{
    UNUM32 hMod; /* Module handle*/
    UNUM32 NumIds; /* number of resources that match PDU_RSC_DATA */
    UNUM32* pResourceIdArray; /* pointer to a list of resource ids*/
} PDU_RSC_ID_ITEM_DATA;

typedef struct
{
    T_PDU_IT ItemType; /* value = PDU_IT_RSC_ID (IN parameter)*/
    UNUM32 NumModules; /* number of entries in pResourceIdDataArray. */
    PDU_RSC_ID_ITEM_DATA
    *pResourceIdDataArray; /* pointer to an array of resource Id Item Data */
} PDU_RSC_ID_ITEM;

typedef struct
{
    UNUM32 DLCPinNumber; /* Pin number on DLC */
    UNUM32 DLCPinTypeId; /* Pin ID */
} PDU_PIN_DATA;

typedef struct
{
    UNUM32 BusTypeId; /* Bus Type Id (IN parameter) */
    UNUM32 ProtocolId; /* Protocol Id (IN parameter) */
    UNUM32 NumPinData; /* Number of items in the following array */
    PDU_PIN_DATA* pDLCPinData; /* Pointer to array of PDU_PIN_DATA structures*/
} PDU_RSC_DATA;

typedef struct
{
    UNUM32 hMod; /* Handle of the MVCI protocol module with conflict.*/
    UNUM32 ResourceId; /* Conflicting Resource ID.*/
} PDU_RSC_CONFLICT_DATA;

typedef struct
{
    T_PDU_IT ItemType; /* value= PDU_IT_RSC_CONFLICT.*/
    UNUM32 NumEntries; /* Number of entries written to pRscConflictData.*/
    PDU_RSC_CONFLICT_DATA
    *pRscConflictData; /* Pointer to array of PDU_RSC_CONFLICT_DATA.*/
} PDU_RSC_CONFLICT_ITEM;

typedef struct
{
    UNUM32 UniqueRespIdentifier; /* filled out by application */
    UNUM32 NumParamItems; /* number of ComParams for the Unique Identifier */
    PDU_PARAM_ITEM
    *pParams; /* pointer to array of ComParam items to uniquely define a ECU
                 response. The list is protocol specific */
} PDU_ECU_UNIQUE_RESP_DATA;

typedef struct
{
    T_PDU_IT ItemType; /* Value= PDU_IT_UNIQUE_RESP_ID_TABLE */
    UNUM32 NumEntries; /* Number of entries in the table.*/
    PDU_ECU_UNIQUE_RESP_DATA* pUniqueData; /* Pointer to array of table entries for each ECU response.*/
} PDU_UNIQUE_RESP_ID_TABLE_ITEM;

typedef struct
{
    T_PDU_IT ItemType; /* Value= PDU_IT_RESULT or PDU_IT_STATUS or PDU_IT_ERROR or
                          PDU_IT_INFO.*/
    UNUM32
    hCoP; /* If item is from a ComPrimitive then the hCop contains the valid
             ComPrimitive handle, else it contains PDU_HANDLE_UNDEF.*/
    void* pCoPTag; /* ComPrimitive Tag. Should be ignored if
                      hCop=PDU_HANDLE_UNDEF.*/
    UNUM32 Timestamp; /* Timestamp in microseconds.*/
    void* pData; /* Points to the data for the specified Item Type.*/
} PDU_EVENT_ITEM;

typedef T_PDU_STATUS PDU_STATUS_DATA;

typedef struct
{
    T_PDU_INFO InfoCode; /* Information code.*/
    UNUM32 ExtraInfoData; /* Optional additional information.*/
} PDU_INFO_DATA;

typedef struct
{
    T_PDU_ERR_EVT ErrorCodeId; /* Error code, binary information.*/
    UNUM32 ExtraErrorInfoId; /* Optional additional error information, text
                                translation via MDF file. Binary Information, 0
                                indicates no additional error information.*/
} PDU_ERROR_DATA;

typedef struct
{
    UNUM32 NumFlagBytes; /* Number of bytes in pFlagData array.*/
    UNUM8* pFlagData; /* Pointer to flag bytes used for TxFlag, RxFlag, and
                         CllCreateFlag.*/
} PDU_FLAG_DATA;

typedef struct
{
    UNUM32 NumHeaderBytes; /* Number of header bytes contained in pHeaderBytes
                              array. */
    UNUM32 NumFooterBytes; /* Number of footer bytes contained in pFooterBytes
                              array. */
    UNUM8* pHeaderBytes; /* Reference pointer to Response PDU Header bytes, NULL
                            if NumHeaderBytes = 0.*/
    UNUM8* pFooterBytes; /* Reference pointer to Response PDU Footer bytes, NULL
                            if NumFooterBytes = 0.*/
} PDU_EXTRA_INFO;

typedef struct
{
    PDU_FLAG_DATA RxFlag;
    UNUM32 UniqueRespIdentifier;
    UNUM32 AcceptanceId;
    PDU_FLAG_DATA TimestampFlags;
    UNUM32 TxMsgDoneTimestamp;
    UNUM32 StartMsgTimestamp;
    PDU_EXTRA_INFO* pExtraInfo;
    UNUM32 NumDataBytes;
    UNUM8* pDataBytes;
} PDU_RESULT_DATA;

typedef struct
{
    UNUM32 MVCI_Part1StandardVersion;
    UNUM32 MVCI_Part2StandardVersion;
    UNUM32 HwSerialNumber;
    CHAR8 HwName[64];
    UNUM32 HwVersion;
    UNUM32 HwDate;
    UNUM32 HwInterface;
    CHAR8 FwName[64];
    UNUM32 FwVersion;
    UNUM32 FwDate;
    CHAR8 VendorName[64];
    CHAR8 PDUApiSwName[64];
    UNUM32 PDUApiSwVersion;
    UNUM32 PDUApiSwDate;
} PDU_VERSION_DATA;

typedef struct
{
    UNUM32 ResponseType; /* 0 = positive response; 1 = negative response.*/
    UNUM32 AcceptanceId; /* ID assigned by application to be returned in
                            PDU_RESULT_DATA, which indicates which expected
                            response matched.*/
    UNUM32 NumMaskPatternBytes; /* number of bytes in the Mask Data and Pattern
                                   Data.*/
    UNUM8* pMaskData; /* Pointer to Mask Data. Bits set to a �1' are care bits,
                         �0' are don't care bits.*/
    UNUM8* pPatternData; /* Pointer to Pattern Data. Bytes to compare after the
                            mask is applied.*/
    UNUM32 NumUniqueRespIds; /* Number of items in the following array of unique
                                response identifiers.*/
    UNUM32* pUniqueRespIds; /* Array containing unique response identifiers. Only
                               responses with a unique response identifier found
                               in this array are considered, when trying to match
                               them to this expected response. */
} PDU_EXP_RESP_DATA;

typedef struct
{
    UNUM32 Time; /* Cycle time in ms for cyclic send operation or delay time for
                    PDU_COPT_DELAY ComPrimitive.*/
    SNUM32 NumSendCycles; /* Number of send cycles to be performed.*/
    SNUM32 NumReceiveCycles; /* Number of receive cycles to be performed.*/
    UNUM32 TempParamUpdate; /* Temporary ComParam settings for the ComPrimitive.*/
    PDU_FLAG_DATA TxFlag; /* Transmit Flag used to indicate protocol specific
                             elements for the ComPrimitive's execution..*/
    UNUM32 NumPossibleExpectedResponses; /* number of entries in \ref
                                            pExpectedResponseArray.*/
    PDU_EXP_RESP_DATA
    *pExpectedResponseArray; /* pointer to an array of expected responses.*/
} PDU_COP_CTRL_DATA;

typedef struct
{
    UNUM32 ParamMaxLen; /* Contains the maximum number of UNUM8 bytes the ComParam
                           can contain in \ref pDataArray.*/
    UNUM32 ParamActLen; /* Contains the actual number of UNUM8 bytes in
                           pDataArray..*/
    UNUM8* pDataArray; /* Pointer to an array of \ref UNUM8 values.*/
} PDU_PARAM_BYTEFIELD_DATA;

typedef struct
{
    T_PDU_CPST ComParamStructType; /* Type of ComParam Structure being used.*/
    UNUM32 ParamMaxEntries; /* Contains the maximum number of struct entries in
                               \ref pStructArray.*/
    UNUM32 ParamActEntries; /* Contains the maximum number of struct entries the
                               ComParam can contain in \ref pStructArray.*/
    void* pStructArray; /* Pointer to an array of structs (typecasted to the \ref
                           ComParamStructType).*/
} PDU_PARAM_STRUCTFIELD_DATA;

typedef struct
{
    UNUM16
    session; /* Session Number, for the diagnostic session of ISO 15765-3.*/
    UNUM8 P2Max_high; /* Default P2Can_Server_max timing (1 ms resolution)
                         supported by the server for the activated diagnostic
                         session. Used for ComParam CP_P2Max.*/
    UNUM8 P2Max_low; /* Timing used for ComParam CP_P2Min (1 ms resolution).*/
    UNUM8 P2Star_high; /* Enhanced (NRC 78 hex) P2Can_Server_max (10 ms
                          resolution) supported by the server for the activated
                          diagnostic session. Used for ComParam CP_P2Star.*/
    UNUM8
    P2Star_low; /* Timing (10 ms resolution) used for internal ECU use only.*/
} PDU_PARAM_STRUCT_SESS_TIMING;

typedef struct
{
    UNUM8 P2Min; /* Minimum time (0,5 ms resolution) between tester request and
                    ECU response(s). Used for ComParam CP_P2Min.*/
    UNUM8 P2Max; /* Maximum time between tester request and ECU response(s).*/
    UNUM8 P3Min; /* Minimum time between end of ECU responses and start of new
                    tester request.*/
    UNUM8 P3Max; /* Maximum time between ECU responses and start of new tester
                    request.*/
    UNUM8 P4Min; /* Minimum inter byte time for tester request.*/
    UNUM8 TimingSet; /* Set number allowing multiple sets of timing parameters.*/
} PDU_PARAM_STRUCT_ACCESS_TIMING;

typedef struct
{
    UNUM32 ParamMaxLen; /* Contains the maximum number of UNUM32 entries the
                           ComParam can contain in \ref pDataArray.*/
    UNUM32 ParamActLen; /* Contains the current number of UNUM32 entries the
                           ComParam can contain in \ref pDataArray.*/
    UNUM32* pDataArray; /* Pointer to an array of UNUM32 values.*/
} PDU_PARAM_LONGFIELD_DATA;

typedef void (*CALLBACKFNC)(T_PDU_EVT_DATA eventType, UNUM32 hMod, UNUM32 hCll, void* pCllTag, void* pAPITag);

EXTERNC T_PDU_ERROR PDUConstruct(CHAR8* pszOption, void* pAPITag);
EXTERNC T_PDU_ERROR PDUDestruct();
EXTERNC T_PDU_ERROR PDUModuleConnect(UNUM32 hMod);
EXTERNC T_PDU_ERROR PDUModuleDisconnect(UNUM32 hMod);
EXTERNC T_PDU_ERROR PDUGetModuleIds(PDU_MODULE_ITEM** pModuleIdList);
EXTERNC T_PDU_ERROR PDUGetResourceIds(UNUM32 hMod, PDU_RSC_DATA* pResourceIdData, PDU_RSC_ID_ITEM** pResourceIdList);
EXTERNC T_PDU_ERROR PDUGetResourceStatus(PDU_RSC_STATUS_ITEM* pResourceStatus);
EXTERNC T_PDU_ERROR PDUCreateComLogicalLink(UNUM32 hMod,
    PDU_RSC_DATA* pRscData,
    UNUM32 uiResourceId,
    void* pCllTag,
    UNUM32* phCll,
    PDU_FLAG_DATA* pCllCreateFlag);
EXTERNC T_PDU_ERROR PDUDestroyComLogicalLink(UNUM32 hMod, UNUM32 hCll);
EXTERNC T_PDU_ERROR PDURegisterEventCallback(UNUM32 hMod, UNUM32 hCll, CALLBACKFNC fnCB);
EXTERNC T_PDU_ERROR PDUGetComParam(UNUM32 hMod, UNUM32 hCll, UNUM32 uiParamId, PDU_PARAM_ITEM** pParamItem);
EXTERNC T_PDU_ERROR PDUSetComParam(UNUM32 hMod, UNUM32 hCll, PDU_PARAM_ITEM* pParamItem);
EXTERNC T_PDU_ERROR PDUConnect(UNUM32 hMod, UNUM32 hCll);
EXTERNC T_PDU_ERROR PDUDisconnect(UNUM32 hMod, UNUM32 hCll);
EXTERNC T_PDU_ERROR PDUStartComPrimitive(UNUM32 hMod,
    UNUM32 hCll,
    T_PDU_COPT uiCoPType,
    UNUM32 uiCoPDataSize,
    UNUM8* pCoPData,
    PDU_COP_CTRL_DATA* pCopCtrlData,
    void* pCoPTag,
    UNUM32* phCoP);
EXTERNC T_PDU_ERROR PDUCancelComPrimitive(UNUM32 hMod, UNUM32 hCll, UNUM32 hCoP);
EXTERNC T_PDU_ERROR PDUGetEventItem(UNUM32 hMod, UNUM32 hCll, PDU_EVENT_ITEM** pEventItem);
EXTERNC T_PDU_ERROR PDUDestroyItem(PDU_ITEM* pItem);
EXTERNC T_PDU_ERROR PDUGetVersion(UNUM32 hMod, PDU_VERSION_DATA* pVersionData);
EXTERNC T_PDU_ERROR PDUGetLastError(UNUM32 hMod,
    UNUM32 hCll,
    T_PDU_ERR_EVT* pErrorCode,
    UNUM32* phCoP,
    UNUM32* pTimestamp,
    UNUM32* pExtraErrorInfo);
EXTERNC T_PDU_ERROR PDUGetUniqueRespIdTable(UNUM32 hMod,
    UNUM32 hCll,
    PDU_UNIQUE_RESP_ID_TABLE_ITEM** pUniqueRespIdTable);
EXTERNC T_PDU_ERROR PDUSetUniqueRespIdTable(UNUM32 hMod,
    UNUM32 hCll,
    PDU_UNIQUE_RESP_ID_TABLE_ITEM* pUniqueRespIdTable);
EXTERNC T_PDU_ERROR
PDUIoCtl(UNUM32 hMod, UNUM32 hCll, UNUM32 uiIoCtlCommandId, PDU_DATA_ITEM* pInputData, PDU_DATA_ITEM** pOutputData);
EXTERNC T_PDU_ERROR PDUGetObjectId(UNUM32 uiPDUObjectType, CHAR8* pszShortName, UNUM32* pPDUObjectId);
EXTERNC T_PDU_ERROR PDUGetTimestamp(UNUM32 hMod, UNUM32* puiTimestamp);
EXTERNC T_PDU_ERROR PDUGetStatus(UNUM32 hMod,
    UNUM32 hCll,
    UNUM32 hCoP,
    T_PDU_STATUS* puiStatusCode,
    UNUM32* puiTimestamp,
    UNUM32* puiExtraInfo);
EXTERNC T_PDU_ERROR PDUGetConflictingResources(UNUM32 uiResourceId,
    PDU_MODULE_ITEM* pModuleList,
    PDU_RSC_CONFLICT_ITEM** pConflictList);
EXTERNC T_PDU_ERROR PDULockResource(UNUM32 hMod, UNUM32 hCll, UNUM32 uiLockMask);
EXTERNC T_PDU_ERROR PDUUnlockResource(UNUM32 hMod, UNUM32 hCll, UNUM32 uiLockMask);

#endif  // DPDUAPI_INTERFACE_H_
