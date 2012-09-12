#if !defined(AFX_DIAADDPRO_H__3528FF0A_5342_4B2B_8023_9C7EB887E5AE__INCLUDED_)
#define AFX_DIAADDPRO_H__3528FF0A_5342_4B2B_8023_9C7EB887E5AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaAddPro.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DiaAddPro dialog

class DiaAddPro : public CDialog
{
// Construction
public:
	DiaAddPro(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaAddPro)
	enum { IDD = IDD_AddPro };
	CString	m_apbd;
	CString	m_apdp;
	CString	m_apid;
	CString	m_apnm;
	CString	m_apst;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaAddPro)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaAddPro)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAADDPRO_H__3528FF0A_5342_4B2B_8023_9C7EB887E5AE__INCLUDED_)
