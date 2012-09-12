// DiaMStu.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaMStu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaMStu dialog


DiaMStu::DiaMStu(CWnd* pParent /*=NULL*/)
	: CDialog(DiaMStu::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaMStu)
	m_mstusc = _T("");
	m_mstuid = _T("");
	m_mstunm = _T("");
	m_mstubd = _T("");
	m_mstugd = _T("");
	m_mstust = _T("");
	//}}AFX_DATA_INIT
}


void DiaMStu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaMStu)
	DDX_Text(pDX, IDC_MStuSC, m_mstusc);
	DDX_Text(pDX, IDC_MStuID, m_mstuid);
	DDX_Text(pDX, IDC_MStuNM, m_mstunm);
	DDX_Text(pDX, IDC_MStuBD, m_mstubd);
	DDX_Text(pDX, IDC_MStuGD, m_mstugd);
	DDX_Text(pDX, IDC_MStuST, m_mstust);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaMStu, CDialog)
	//{{AFX_MSG_MAP(DiaMStu)
	ON_BN_CLICKED(IDC_MGetInfo, OnMGetInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaMStu message handlers
