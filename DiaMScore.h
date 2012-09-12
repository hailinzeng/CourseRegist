#if !defined(AFX_DIAMSCORE_H__3E08FFBE_7965_4290_B2C6_219B9B8310A2__INCLUDED_)
#define AFX_DIAMSCORE_H__3E08FFBE_7965_4290_B2C6_219B9B8310A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaMScore.h : header file
//

#include "Global.h"
/////////////////////////////////////////////////////////////////////////////
// DiaMScore dialog

class DiaMScore : public CDialog
{
// Construction
public:
	DiaMScore(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaMScore)
	enum { IDD = IDD_MSCORE };
	CString	m_cname1;
	CString	m_cname2;
	CString	m_cname3;
	CString	m_cname4;
	CString	m_cname5;
	CString	m_cname6;
	CString	m_cscore1;
	CString	m_cscore2;
	CString	m_cscore3;
	CString	m_cscore4;
	CString	m_cscore5;
	CString	m_cscore6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaMScore)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaMScore)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAMSCORE_H__3E08FFBE_7965_4290_B2C6_219B9B8310A2__INCLUDED_)
