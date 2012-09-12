// DiaMCS.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaMCS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaMCS dialog


DiaMCS::DiaMCS(CWnd* pParent /*=NULL*/)
	: CDialog(DiaMCS::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaMCS)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaMCS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaMCS)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaMCS, CDialog)
	//{{AFX_MSG_MAP(DiaMCS)
	ON_BN_CLICKED(IDC_MGetInfo, OnMGetInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaMCS message handlers



