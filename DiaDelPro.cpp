// DiaDelPro.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaDelPro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaDelPro dialog


DiaDelPro::DiaDelPro(CWnd* pParent /*=NULL*/)
	: CDialog(DiaDelPro::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaDelPro)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaDelPro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaDelPro)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaDelPro, CDialog)
	//{{AFX_MSG_MAP(DiaDelPro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaDelPro message handlers
