//******************************************************************************************************************************
// Copyright (c) 2017, 2019 Qualcomm Technologies, Inc.
// All Rights Reserved.
// Confidential and Proprietary - Qualcomm Technologies, Inc.
//******************************************************************************************************************************

/**
********************************************************************************************************************************
* @file  eglwaylandupdater.h
* @brief Wayland WL Surface Updater class. This class is used by the wayland surface
********************************************************************************************************************************
*/

#ifndef EGLWAYLANDUPDATER_H
#define EGLWAYLANDUPDATER_H

#include "egltypes.h"

enum UpdaterStatus
{
    UpdaterStatusRunning   = 0, ///< Running
    UpdaterStatusTerminate = 1, ///< Terminate
};

typedef EGLVOID (*PFNEGL_UPDATERFUNC)(EGLVOID* pSurface, EGLUINT bufferIndex);
class EglWaylandUpdater final
{
public:
    static EglWaylandUpdater* Create(EGLVOID*           pSurface,
                                     EGLUINT            bufQueueLength,
                                     EGLBOOL            createWorkThread,
                                     PFNEGL_UPDATERFUNC pFnUpdaterFunc);
    EGLVOID   UpdateBuffer(EGLUINT bufferIndex);
    EGLVOID   Destroy();

    /// Lock m_mutex only if we have an updater thread
    EGL_INLINE EGLVOID LockMutex()
    {
        if (EGL_TRUE == m_threadEnabled)
        {
            pthread_mutex_lock(&m_mutex);
        }
    }

    /// Unlock m_mutex only if we have an updater thread
    EGL_INLINE EGLVOID UnlockMutex()
    {
        if (EGL_TRUE == m_threadEnabled)
        {
            pthread_mutex_unlock(&m_mutex);
        }
    }

private:
    static EGLVOID UpdaterThreadEntry(EGLVOID* data) {(reinterpret_cast<EglWaylandUpdater*>(data))->UpdaterThread();}
    explicit EglWaylandUpdater(EGLVOID* pSurface, EGLUINT bufQueueLength, PFNEGL_UPDATERFUNC pFnUpdaterFunc);
    ~EglWaylandUpdater();
    EglWaylandUpdater(const EglWaylandUpdater& other);
    EglWaylandUpdater& operator=(const EglWaylandUpdater& other);
    EGLBOOL                     InitQueue();
    EGLVOID                     DeInitQueue();
    EGLVOID                     EnqueueUpdaterBuffer(EGLUINT bufferIndex);
    EGLUINT                     DequeueUpdaterBuffer();
    EGLVOID                     UpdaterThread();

    EGLVOID*                    m_pSurface;           ///< Update buffer for this surface
    PFNEGL_UPDATERFUNC          m_pFnUpdaterFunc;     ///< Pointer to update function
    EGLUINT                     m_inPos;              ///< Enqueue buffer to m_pBufIndexQueue[m_inPos]
    EGLUINT                     m_outPos;             ///< Dequeue buffer from m_pBufIndexQueue[m_outPos]
    EGLUINT                     m_bufQueueLength;     ///< The length of m_pBufIndexQueue
    EGLUINT*                    m_pBufIndexQueue;     ///< Queue for buffer indexes
    EGLBOOL                     m_threadEnabled;      ///< Indicate m_hThread is valid
    pthread_t                   m_hThread;            ///< Handle to update thread
    pthread_mutex_t             m_mutex;              ///< Mutex protect for members of this object
    pthread_cond_t              m_condVar;            ///< Condition variable signal when members of this object changed
    volatile EGLUINT            m_threadStatus;       ///< Status for update thread
};
#endif // EGLWAYLANDUPDATER_H
