// DiaMpro.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaMpro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaMpro dialog


DiaMpro::DiaMpro(CWnd* pParent /*=NULL*/)
	: CDialog(DiaMpro::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaMpro)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaMpro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaMpro)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaMpro, CDialog)
	//{{AFX_MSG_MAP(DiaMpro)
	ON_BN_CLICKED(IDC_MGetInfo, OnMGetInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaMpro message handlers

