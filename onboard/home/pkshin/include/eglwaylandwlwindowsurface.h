//******************************************************************************************************************************
// Copyright (c) 2014-2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandwlwindowsurface.h
* @brief Wayland WL Surface class. This class is used by the wayland clients
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDWLWINDOWSURFACE_H
#define EGLWAYLANDWLWINDOWSURFACE_H

#include "eglwaylandconfig.h"
#include "eglwaylandupdater.h"
#include "eglwaylandwindowsurfacebase.h"

// Forward declaration
struct gbm_bo;                  // NOWHINE NC004 <- gbm_bo externally declared by libgbm
struct wl_buffer;               // NOWHINE NC004 <- wl_buffer externally declared by Wayland
struct wl_buffer_listener;      // NOWHINE NC004 <- wl_buffer_listener externally declared by Wayland
struct wl_callback;             // NOWHINE NC004 <- wl_callback externally declared by Wayland
struct wl_callback_listener;    // NOWHINE NC004 <- wl_callback_listener externally declared by Wayland
struct wl_egl_window;           // NOWHINE NC004 <- wl_egl_window externally declared by Wayland
class  EglWaylandWlDisplay;

class EglWaylandWlWindowSurface final : public EglWaylandWindowSurfaceBase
{
public:
    static EglWaylandWlWindowSurface* Create(EglNativeDisplay*   pNativeDisplay,
                                             EglWaylandConfig*   pNativeConfig,
                                             EGLNativeWindowType window,
                                             const EGLINT*       pAttribList);
    static EglWaylandWlWindowSurface* Create64(EglNativeDisplay*   pNativeDisplay,
                                               EglWaylandConfig*   pNativeConfig,
                                               EGLNativeWindowType window,
                                               const EGLAttrib*    pAttribList);
    static EGLVOID BufferReleaseCallback(EGLVOID* pData, wl_buffer* pWlBuffer);
    static EGLVOID Callback(EGLVOID* pData, wl_callback* pWlCallback, EGLUINT callbackData);
    static EGLVOID CommitBuffer(EGLVOID* pSurface, EGLUINT bufferIndex);

    virtual EGLINT  SetSwapInterval(EGLINT interval);
    virtual EGLINT  SwapBuffers(EglResourceAccessInfo* pAccessInfo);
    virtual EGLINT  GetAttribute(EGLINT attribute, EGLINT* pValue);
    virtual EGLINT  GetBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    virtual EGLBOOL IsValidAttribute(EGLINT attribute);
    virtual EGLINT  ResizeCallback(EGLINT x, EGLINT y, EGLINT width, EGLINT height);
    virtual EGLVOID GetAttachedDimensions(EGLINT* pWidth, EGLINT* pHeight);
    virtual EGLINT  Destroy();
    virtual EGLVOID CacheOperation(EglCacheCommands cacheCommand, EGLVOID* pCpuAddress);
    virtual EGLBOOL SetRuntimeAttribute(EGLINT attribute, EGLINT value);

    virtual EGLINT  GetBufferCount()    { return m_bufferCount; }

protected:
    EGLBOOL Init(EglNativeDisplay* pEglNativeDisplay, const EGLINT* pAttribList);
    EGLBOOL Init64(EglNativeDisplay* pEglNativeDisplay, const EGLAttrib* pAttribList);
    EGLBOOL InitInternal(EglNativeDisplay* pEglNativeDisplay);
    virtual EGLVOID HandlePreserveOnSwapEnabled();

    virtual ~EglWaylandWlWindowSurface();

private:

/*******************************************************************************************************************************
*   @brief
        Structure to describe a node in the tracking list.
*******************************************************************************************************************************/
    struct BufferNode
    {
        EGLUINT     bufferIndex;                        ///< Index of buffer the node is tracking
        BufferNode* pNext;                               ///< The pNext node in the list
    };

/*******************************************************************************************************************************
*   @brief
        Structure to describe the Wayland buffer information.
*******************************************************************************************************************************/
    struct WaylandBufferInfo
    {
        EGLBOOL                    wlBufferReleasePending; ///< Indicates if the wl_buffer.release event is pending
        EGLUINT                    timestamp;              ///< Timestamp when the buffer was last used
        EGLUINT                    context;                ///< Gsl Context used for the last submit
        EGLUINT                    bufferAge;              ///< Buffer age
        EglMemoryDesc              memDesc;                ///< Egl Memory descriptor
        gbm_bo*                    pGbmBo;                 ///< Backing store of the buffer
        wl_buffer*                 pWlBuffer;              ///< Then wayland protocol wl_buffer object
        EglWaylandWlWindowSurface* pSurface;               ///< The EglWaylandWlWindowSurface
    };

/*******************************************************************************************************************************
*   @brief
        Flags for the WL window surface
*******************************************************************************************************************************/
    union EglWaylandWlWindowSurfaceFlags
    {
        EGLUINT32 value;               ///< Value of the bits

        struct
        {
            EGLBIT  waitForCallback     : 1;  ///< Flag to indicate if we need to wait for any type of callback event
            EGLBIT  isBufferDequeued    : 1;  ///< Flag to check if a buffer was dequeued this frame
            EGLUINT reserved            : 30; ///< Reserved bits
        };
    };

    EGLINT  SetAttributeList(const EGLINT* pAttribList);
    EGLINT  SetAttributeList64(const EGLAttrib* pAttribList);
    EGLINT  DequeueBuffer();
    EGLINT  UpdateCurrentBuffer(EglSubResource* pSubResource, EglMemoryDesc* pMemDesc);
    EGLVOID UpdateBufferList(gbm_bo* pGbmBo);
    EGLVOID DestroyBuffer(WaylandBufferInfo* pWlBufferInfo);
    EGLVOID PruneBusyList();


    /// Lock updater mutex if we have an updater
    EGL_INLINE EGLVOID LockUpdaterMutex()
    {
        if (NULL != m_pUpdater)
        {
            m_pUpdater->LockMutex();
        }
    }

    /// Unlock updater mutex if we have an updater
    EGL_INLINE EGLVOID UnlockUpdaterMutex()
    {
        if (NULL != m_pUpdater)
        {
            m_pUpdater->UnlockMutex();
        }
    }

    /// Set BufferDequeued flag
    EGL_INLINE EGLVOID SetBufferDequeued(EGLBOOL value)
    {
        LockUpdaterMutex();
        m_flags.isBufferDequeued = value;
        UnlockUpdaterMutex();
    }

    /// Set WaitForCallback flag
    EGL_INLINE EGLVOID SetWaitForCallback(EGLBOOL value)
    {
        LockUpdaterMutex();
        m_flags.waitForCallback = value;
        UnlockUpdaterMutex();
    }

    /// There is a buffer has been dequeued
    EGL_INLINE EGLBOOL IsBufferDequeued()
    {
        EGLBOOL ret;
        LockUpdaterMutex();
        ret = m_flags.isBufferDequeued;
        UnlockUpdaterMutex();
        return ret;
    }

    /// Callback has not been called
    EGL_INLINE EGLBOOL CallbackUnCalled()
    {
        EGLBOOL ret;
        LockUpdaterMutex();
        ret = m_flags.waitForCallback;
        UnlockUpdaterMutex();
        return ret;
    }

    /// Initialize the given list head
    EGL_INLINE EGLVOID InitListHead(BufferNode* listHead)
    {
        listHead->bufferIndex = EglInvalidIndex;
        listHead->pNext        = NULL;
    }

    /// Queue the given node to the end of the given list
    EGL_INLINE EGLVOID QueueNodeToList(BufferNode* listHead, BufferNode* node)
    {
        BufferNode* pLastNode = listHead;
        while (NULL != pLastNode->pNext)
        {
            pLastNode = pLastNode->pNext;
        }

        node->pNext     = NULL;
        pLastNode->pNext = node;
    }

    /// Dequeue a node from the front of the given list
    EGL_INLINE BufferNode* DequeueNodeFromList(BufferNode* listHead)
    {
        BufferNode* pFirstNode = listHead->pNext;
        if (NULL != pFirstNode)
        {
            listHead->pNext  = pFirstNode->pNext;
            pFirstNode->pNext = NULL;
        }
        return pFirstNode;
    }

    /// Is the given list empty
    EGL_INLINE EGLBOOL IsEmptyList(BufferNode* listHead)
    {
        EGLBOOL isEmpty = EGL_TRUE;
        if (NULL != listHead->pNext)
        {
            isEmpty = EGL_FALSE;
        }
        return isEmpty;
    }

    /// Destroy the given list
    EGL_INLINE EGLVOID DestroyList(BufferNode* listHead)
    {
        BufferNode* pNode = NULL;
        while (NULL != listHead->pNext)
        {
            pNode           = listHead->pNext;
            listHead->pNext = pNode->pNext;
            EGL_FREE(pNode);
        }
        listHead->pNext = NULL;
    }

    /// Initialize free list
    EGL_INLINE EGLVOID InitializeFreeList()
    {
        InitListHead(&m_freeNodeList);
    }

    /// Initialize staging list
    EGL_INLINE EGLVOID InitializeStagingList()
    {
        InitListHead(&m_stagingNodeList);
    }

    /// Initialize busy list
    EGL_INLINE EGLVOID InitializeBusyList()
    {
        InitListHead(&m_busyNodeList);
    }

    /// Queue to free list
    EGL_INLINE EGLVOID QueueToFreeList(BufferNode* node)
    {
        QueueNodeToList(&m_freeNodeList, node);
    }

    /// Queue to staging list
    EGL_INLINE EGLVOID QueueToStagingList(BufferNode* node)
    {
        QueueNodeToList(&m_stagingNodeList, node);
    }

    /// Queue to busy list
    EGL_INLINE EGLVOID QueueToBusyList(BufferNode* node)
    {
        QueueNodeToList(&m_busyNodeList, node);
    }

    /// Dequeue from free list
    EGL_INLINE BufferNode* DequeueFromFreeList()
    {
        return DequeueNodeFromList(&m_freeNodeList);
    }

    /// Dequeue from staging list
    EGL_INLINE BufferNode* DequeueFromStagingList()
    {
        return DequeueNodeFromList(&m_stagingNodeList);
    }

    /// Dequeue from busy list
    EGL_INLINE BufferNode* DequeueFromBusyList()
    {
        return DequeueNodeFromList(&m_busyNodeList);
    }

    /// Is the free list empty
    EGL_INLINE EGLBOOL IsEmptyFreeList()
    {
        return IsEmptyList(&m_freeNodeList);
    }

    /// Is the staging list empty
    EGL_INLINE EGLBOOL IsEmptyStagingList()
    {
        return IsEmptyList(&m_stagingNodeList);
    }

    /// Is the busy list empty
    EGL_INLINE EGLBOOL IsEmptyBusyList()
    {
        return IsEmptyList(&m_busyNodeList);
    }

    /// Destroy the free list
    EGL_INLINE EGLVOID DestroyFreeList()
    {
        DestroyList(&m_freeNodeList);
    }

    /// Destroy the staging list
    EGL_INLINE EGLVOID DestroyStagingList()
    {
        DestroyList(&m_stagingNodeList);
    }

    /// Destroy the busy list
    EGL_INLINE EGLVOID DestroyBusyList()
    {
        DestroyList(&m_busyNodeList);
    }

    explicit EglWaylandWlWindowSurface(EglWaylandDisplayBase* pDisplayBase,
                                       EglWaylandConfig*      pNativeConfig,
                                       wl_egl_window*         pWlEglWindow);

    EglWaylandWlWindowSurface(const EglWaylandWlWindowSurface&);                ///< Disallow the copy constructor
    EglWaylandWlWindowSurface& operator=(const EglWaylandWlWindowSurface&);     ///< Disallow assignment operator

    static const EGLUINT           MaxBuffers = 5;                ///< Maximum number of buffers in the buffer list
    static const EGLUINT           MinBuffers = 4;                ///< Minimum number of buffers in the buffer list

    EGLUINT                        m_activeBufferIndex;           ///< Index of the current buffer being rendered to
    EGLUINT                        m_attachedWidth;               ///< The last known attached width of the surface's buffer
    EGLUINT                        m_attachedHeight;              ///< The last known attached height of the surface's buffer
    EGLUINT                        m_bufferCount;                 ///< The count of the surface's buffers
    wl_egl_window*                 m_pWlEglWindow;                ///< The native window
    EglWaylandWlDisplay*           m_pEglWlDisplay;               ///< The owning EGL wayland display
    WaylandBufferInfo*             m_pWlBufferList[MaxBuffers];   ///< Array of WaylandBufferInfo
    wl_buffer_listener*            m_pBufferListenerHandler;      ///< The buffer listener handler
    wl_callback_listener*          m_pCallbackHandler;            ///< The frame callback handler
    wl_event_queue*                m_pCallbackEventQueue;         ///< The event queue for Callback
    EglWaylandWlWindowSurfaceFlags m_flags;                       ///< Flags for the WL Window Surface
    EglWaylandUpdater*             m_pUpdater;                    ///< Window updater thread class pointer
    EGLBOOL                        m_enableUbwc;                  ///< Indicate if enable UBWC or not, default is true
    BufferNode                     m_freeNodeList;                ///< Head of the list that tracks free buffers
    BufferNode                     m_stagingNodeList;             ///< Head of the list that tracks staged buffers
    BufferNode                     m_busyNodeList;                ///< Head of the list that tracks busy buffers
};

#endif // EGLWAYLANDWLWINDOWSURFACE_H
