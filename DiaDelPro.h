#if !defined(AFX_DIADELPRO_H__E9F5FD12_722F_4D2A_80BA_AC32E6DB3E14__INCLUDED_)
#define AFX_DIADELPRO_H__E9F5FD12_722F_4D2A_80BA_AC32E6DB3E14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaDelPro.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaDelPro dialog

class DiaDelPro : public CDialog
{
// Construction
public:
	DiaDelPro(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaDelPro)
	enum { IDD = IDD_DelPro };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaDelPro)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaDelPro)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIADELPRO_H__E9F5FD12_722F_4D2A_80BA_AC32E6DB3E14__INCLUDED_)
