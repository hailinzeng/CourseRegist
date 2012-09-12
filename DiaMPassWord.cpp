// DiaMPassWord.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaMPassWord.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaMPassWord dialog


DiaMPassWord::DiaMPassWord(CWnd* pParent /*=NULL*/)
	: CDialog(DiaMPassWord::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaMPassWord)

	m_npassword=_T("");

		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DiaMPassWord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaMPassWord)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaMPassWord, CDialog)
	//{{AFX_MSG_MAP(DiaMPassWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaMPassWord message handlers
