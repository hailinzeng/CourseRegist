#if !defined(AFX_DIADELSTU_H__3FEB1F03_6491_4AF3_92C4_C339EAD402FF__INCLUDED_)
#define AFX_DIADELSTU_H__3FEB1F03_6491_4AF3_92C4_C339EAD402FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaDelStu.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaDelStu dialog

class DiaDelStu : public CDialog
{
// Construction
public:
	DiaDelStu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaDelStu)
	enum { IDD = IDD_DelStu };
	CString	m_dstid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaDelStu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaDelStu)
	afx_msg void OnDelStu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIADELSTU_H__3FEB1F03_6491_4AF3_92C4_C339EAD402FF__INCLUDED_)
