#if !defined(AFX_DIATSC_H__8544F311_5F65_48CD_A698_BE1F0723508B__INCLUDED_)
#define AFX_DIATSC_H__8544F311_5F65_48CD_A698_BE1F0723508B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaTSC.h : header file
//

#include "Global.h"

/////////////////////////////////////////////////////////////////////////////
// DiaTSC dialog

class DiaTSC : public CDialog
//class DiaTSC:public CView
{
// Construction
public:
	void OnTexcuteX(CString m_dts_id);
	DiaTSC(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaTSC)
	enum { IDD = IDD_SC };
	CString	m_ListTts;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaTSC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaTSC)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSeekCIF();
	afx_msg void OnTexcute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIATSC_H__8544F311_5F65_48CD_A698_BE1F0723508B__INCLUDED_)
