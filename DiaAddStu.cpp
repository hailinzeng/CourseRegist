// DiaAddStu.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaAddStu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaAddStu dialog


DiaAddStu::DiaAddStu(CWnd* pParent /*=NULL*/)
	: CDialog(DiaAddStu::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaAddStu)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaAddStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaAddStu)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaAddStu, CDialog)
	//{{AFX_MSG_MAP(DiaAddStu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaAddStu message handlers

