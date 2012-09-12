#if !defined(AFX_DIAADDSTU_H__C5040209_0760_4C1C_8B67_F9F4E49405C5__INCLUDED_)
#define AFX_DIAADDSTU_H__C5040209_0760_4C1C_8B67_F9F4E49405C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaAddStu.h : header file
//

#include "sys.h"
/////////////////////////////////////////////////////////////////////////////
// DiaAddStu dialog

class DiaAddStu : public CDialog
{
// Construction
public:
	DiaAddStu(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DiaAddStu)
	enum { IDD = IDD_AddStu };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DiaAddStu)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DiaAddStu)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIAADDSTU_H__C5040209_0760_4C1C_8B67_F9F4E49405C5__INCLUDED_)
