#if !defined(AFX_DIAMPASSWORD_H__DFFEBCED_B76F_4735_8F42_9F0AFB311167__INCLUDED_)
#define AFX_DIAMPASSWORD_H__DFFEBCED_B76F_4735_8F42_9F0AFB311167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaMPassWord.h : header file
//

#include "Global.h"

/////////////////////////////////////////////////////////////////////////////
// DiaMPassWord dialog

class DiaMPassWord : public CDialog
{
// Construction
public:
	DiaMPassWord(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaMPassWord)
	enum { IDD = IDD_MPassWord };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaMPassWord)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaMPassWord)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAMPASSWORD_H__DFFEBCED_B76F_4735_8F42_9F0AFB311167__INCLUDED_)
