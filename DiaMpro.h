#if !defined(AFX_DIAMPRO_H__0205A1EB_AD1C_4C9E_83F7_394015704DD3__INCLUDED_)
#define AFX_DIAMPRO_H__0205A1EB_AD1C_4C9E_83F7_394015704DD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaMpro.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaMpro dialog

class DiaMpro : public CDialog
{
// Construction
public:
	DiaMpro(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaMpro)
	enum { IDD = IDD_MPro };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaMpro)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaMpro)
	afx_msg void OnMGetInfo();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAMPRO_H__0205A1EB_AD1C_4C9E_83F7_394015704DD3__INCLUDED_)
