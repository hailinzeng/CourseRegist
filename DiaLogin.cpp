// DiaLogin.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaLogin dialog

DiaLogin::DiaLogin(CWnd* pParent /*=NULL*/)
	: CDialog(DiaLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaLogin)

	m_ID=_T("");
	m_password=_T("");

	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void DiaLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaLogin)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(DiaLogin, CDialog)
	//{{AFX_MSG_MAP(DiaLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaLogin message handlers

