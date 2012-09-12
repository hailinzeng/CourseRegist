// Course_Regist.h : main header file for the COURSE_REGIST application
//

#if !defined(AFX_COURSE_REGIST_H__D3D10D07_F1D2_4BF2_B079_EC00F0A4EABB__INCLUDED_)
#define AFX_COURSE_REGIST_H__D3D10D07_F1D2_4BF2_B079_EC00F0A4EABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistApp:
// See Course_Regist.cpp for the implementation of this class
//

class CCourse_RegistApp : public CWinApp
{
public:
	CCourse_RegistApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourse_RegistApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCourse_RegistApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSE_REGIST_H__D3D10D07_F1D2_4BF2_B079_EC00F0A4EABB__INCLUDED_)
