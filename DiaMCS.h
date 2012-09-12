#if !defined(AFX_DIAMCS_H__77897AB7_2B64_4F72_9F73_552EEA929775__INCLUDED_)
#define AFX_DIAMCS_H__77897AB7_2B64_4F72_9F73_552EEA929775__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaMCS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaMCS dialog

class DiaMCS : public CDialog
{
// Construction
public:
	DiaMCS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaMCS)
	enum { IDD = IDD_MCS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaMCS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaMCS)
	afx_msg void OnMGetInfo();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAMCS_H__77897AB7_2B64_4F72_9F73_552EEA929775__INCLUDED_)
