#if !defined(AFX_DIASSC_H__58AD8A69_E962_4B00_8035_9DF12DFDA677__INCLUDED_)
#define AFX_DIASSC_H__58AD8A69_E962_4B00_8035_9DF12DFDA677__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaSSC.h : header file
//

#include "Global.h"
/////////////////////////////////////////////////////////////////////////////
// DiaSSC dialog

class DiaSSC : public CDialog
{
// Construction
public:
	int obligatory;
	int optional;
	void OnSexcuteX(CString m_dts_id);
	DiaSSC(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaSSC)
	enum { IDD = IDD_SSC };
	CString	m_ListSts;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaSSC)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaSSC)
	virtual BOOL OnInitDialog();
	afx_msg void OnSSeekCIF();
	afx_msg void OnSexcute();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIASSC_H__58AD8A69_E962_4B00_8035_9DF12DFDA677__INCLUDED_)
