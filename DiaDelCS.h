#if !defined(AFX_DIADELCS_H__3714A823_A7C8_44BA_AD28_17E952329FE6__INCLUDED_)
#define AFX_DIADELCS_H__3714A823_A7C8_44BA_AD28_17E952329FE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaDelCS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaDelCS dialog

class DiaDelCS : public CDialog
{
// Construction
public:
	DiaDelCS(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaDelCS)
	enum { IDD = IDD_DelCS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaDelCS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaDelCS)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIADELCS_H__3714A823_A7C8_44BA_AD28_17E952329FE6__INCLUDED_)
