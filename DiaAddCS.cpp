// DiaAddCS.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaAddCS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaAddCS dialog


DiaAddCS::DiaAddCS(CWnd* pParent /*=NULL*/)
	: CDialog(DiaAddCS::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaAddCS)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaAddCS::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaAddCS)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaAddCS, CDialog)
	//{{AFX_MSG_MAP(DiaAddCS)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaAddCS message handlers

