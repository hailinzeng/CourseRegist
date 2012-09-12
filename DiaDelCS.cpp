// DiaDelCS.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaDelCS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaDelCS dialog


DiaDelCS::DiaDelCS(CWnd* pParent /*=NULL*/)
	: CDialog(DiaDelCS::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaDelCS)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaDelCS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaDelCS)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaDelCS, CDialog)
	//{{AFX_MSG_MAP(DiaDelCS)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaDelCS message handlers
