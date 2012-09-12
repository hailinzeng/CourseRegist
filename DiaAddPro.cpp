// DiaAddPro.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaAddPro.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaAddPro dialog


DiaAddPro::DiaAddPro(CWnd* pParent /*=NULL*/)
	: CDialog(DiaAddPro::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaAddPro)
	m_apbd = _T("");
	m_apdp = _T("");
	m_apid = _T("");
	m_apnm = _T("");
	m_apst = _T("");
	//}}AFX_DATA_INIT
}


void DiaAddPro::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaAddPro)
	DDX_Text(pDX, IDC_APBD, m_apbd);
	DDX_Text(pDX, IDC_APDP, m_apdp);
	DDX_Text(pDX, IDC_APID, m_apid);
	DDX_Text(pDX, IDC_APNM, m_apnm);
	DDX_Text(pDX, IDC_APST, m_apst);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaAddPro, CDialog)
	//{{AFX_MSG_MAP(DiaAddPro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaAddPro message handlers
