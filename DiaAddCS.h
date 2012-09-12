#if !defined(AFX_DIAADDCS_H__CC3BAF82_7975_41D5_87A0_C3AA722420D8__INCLUDED_)
#define AFX_DIAADDCS_H__CC3BAF82_7975_41D5_87A0_C3AA722420D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaAddCS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaAddCS dialog

class DiaAddCS : public CDialog
{
// Construction
public:
	DiaAddCS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaAddCS)
	enum { IDD = IDD_AddCS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaAddCS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaAddCS)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAADDCS_H__CC3BAF82_7975_41D5_87A0_C3AA722420D8__INCLUDED_)
