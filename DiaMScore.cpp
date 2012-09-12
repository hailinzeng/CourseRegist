// DiaMScore.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaMScore.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaMScore dialog


DiaMScore::DiaMScore(CWnd* pParent /*=NULL*/)
	: CDialog(DiaMScore::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaMScore)
	m_cname1 = _T("");
	m_cname2 = _T("");
	m_cname3 = _T("");
	m_cname4 = _T("");
	m_cname5 = _T("");
	m_cname6 = _T("");
	m_cscore1 = _T("");
	m_cscore2 = _T("");
	m_cscore3 = _T("");
	m_cscore4 = _T("");
	m_cscore5 = _T("");
	m_cscore6 = _T("");
	//}}AFX_DATA_INIT
}


void DiaMScore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaMScore)
	DDX_Text(pDX, IDC_CNAME1, m_cname1);
	DDX_Text(pDX, IDC_CNAME2, m_cname2);
	DDX_Text(pDX, IDC_CNAME3, m_cname3);
	DDX_Text(pDX, IDC_CNAME4, m_cname4);
	DDX_Text(pDX, IDC_CNAME5, m_cname5);
	DDX_Text(pDX, IDC_CNAME6, m_cname6);
	DDX_Text(pDX, IDC_CSCORE1, m_cscore1);
	DDX_Text(pDX, IDC_CSCORE2, m_cscore2);
	DDX_Text(pDX, IDC_CSCORE3, m_cscore3);
	DDX_Text(pDX, IDC_CSCORE4, m_cscore4);
	DDX_Text(pDX, IDC_CSCORE5, m_cscore5);
	DDX_Text(pDX, IDC_CSCORE6, m_cscore6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaMScore, CDialog)
	//{{AFX_MSG_MAP(DiaMScore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaMScore message handlers

