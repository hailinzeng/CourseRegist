#if !defined(AFX_DIAGRADE_H__D869CC80_3D74_4D67_A232_96012EC9CC64__INCLUDED_)
#define AFX_DIAGRADE_H__D869CC80_3D74_4D67_A232_96012EC9CC64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaGrade.h : header file
//

#include "Global.h"
/////////////////////////////////////////////////////////////////////////////
// DiaGrade dialog

class DiaGrade : public CDialog
{
// Construction
public:
	DiaGrade(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaGrade)
	enum { IDD = IDD_Grade };
	CString	m_listmc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaGrade)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaGrade)
	afx_msg void OnLoadStu();
	virtual BOOL OnInitDialog();
	afx_msg void OnDenfen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAGRADE_H__D869CC80_3D74_4D67_A232_96012EC9CC64__INCLUDED_)
