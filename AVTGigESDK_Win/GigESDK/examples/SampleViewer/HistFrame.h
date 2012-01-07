/*
| ==============================================================================
| Copyright (C) 2006-2011 Allied Vision Technologies.  All Rights Reserved.
|
| This code may be used in part, or in whole for your application development.
|
|==============================================================================
|
| File:	        HistFrame.h		
|
| Project/lib:  SampleViewer	
|
| Target:		
|
| Description:  Define the Histogram window
|
| Notes:
|
|==============================================================================
|
| THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
| WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF TITLE,
| NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE ARE
| DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
| INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
| LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
| OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  AND ON ANY THEORY OF
| LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
| NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
| EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
|
|==============================================================================
*/

#ifndef _HISTFRAME_INCLUDED_
#define _HISTFRAME_INCLUDED_

#include "ChildFrame.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//===== CLASS DEFINITION ======================================================

/*
 * Class:    CHistFrame
 * Purpose:  Derive our MDI child class for the Histogram window
 * Comments: none
 */
class CHistFrame : public CChildFrame
{
	DECLARE_DYNCREATE(CHistFrame)

    public:

        /*
         * Method:    CHistFrame()
         * Purpose:   class constructor
         * Arguments: none
         * Return:    none
         * Comments:  none
         */
	    CHistFrame();

        /*
         * Method:    ~CHistFrame()
         * Purpose:   class destructor
         * Arguments: none
         * Return:    none
         * Comments:  none
         */        
        virtual ~CHistFrame();

        /*
         * Method:    Create()
         * Purpose:   create the window
         * Arguments: 
         *
         * [i] tPvCameraInfoEx* pInfo, pointer to the camera's info
         *
         * Return:    FALSE if failed
         * Comments:  none
         */ 
        BOOL Create(tPvCameraInfoEx* pInfo);

        /*
         * Method:    Update()
         * Purpose:   update the histogram with a given frame
         * Arguments: 
         *
         * [i] tPvFrame* pFrame, frame 
         * 
         * Return:    none
         * Comments:  none
         */ 
        void Update(tPvFrame* pFrame);

    public: // from CMDIChildWnd

        /*
         * Method:    PreCreateWindow()
         * Purpose:   called by the framework prior to the creation of
         *            the window. 
         * Arguments:
         *
         * [b] CREATESTRUCT& cs, creation parameters
         *
         * Return:    FALSE if an error occured
         * Comments:  Can be used to alter to window size and position
         */
	    BOOL PreCreateWindow(CREATESTRUCT& cs);

        /*
         * Method:    OnPaint()
         * Purpose:   called by the framework when the client area of
         *            the window must be redraw
         * Arguments: none
         * Return:    none
         * Comments:  none
         */
        afx_msg void OnPaint();

        /*
         * Method:    OnEraseBkgnd()
         * Purpose:   called by the framework when the client area of
         *            the window should be erased
         * Arguments: 
         *
         * [i] CDC* pDC, device-context object
         *
         * Return:    TRUE if the background was erased
         * Comments:  none
         */
        afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    protected:

        // message map
	    DECLARE_MESSAGE_MAP()

    private: // data

        // histogram data
        ULONG*           m_Data;
        // lock for drawing
        CRITICAL_SECTION m_Lock;
};

#endif // _HISTFRAME_INCLUDED_
