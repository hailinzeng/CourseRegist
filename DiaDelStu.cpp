// DiaDelStu.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaDelStu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaDelStu dialog


DiaDelStu::DiaDelStu(CWnd* pParent /*=NULL*/)
	: CDialog(DiaDelStu::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaDelStu)
	m_dstid = _T("");
	//}}AFX_DATA_INIT
}


void DiaDelStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaDelStu)
	DDX_Text(pDX, IDC_EDIT1, m_dstid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaDelStu, CDialog)
	//{{AFX_MSG_MAP(DiaDelStu)
	ON_BN_CLICKED(IDOK, OnDelStu)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaDelStu message handlers

