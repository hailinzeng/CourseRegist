// DiaGrade.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaGrade.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaGrade dialog


DiaGrade::DiaGrade(CWnd* pParent /*=NULL*/)
	: CDialog(DiaGrade::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaGrade)
	m_listmc = _T("");
	//}}AFX_DATA_INIT
}


void DiaGrade::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaGrade)
	DDX_LBString(pDX, IDC_LISTMC, m_listmc);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaGrade, CDialog)
	//{{AFX_MSG_MAP(DiaGrade)
	ON_BN_CLICKED(IDC_LoadStu, OnLoadStu)
	ON_BN_CLICKED(IDC_DENFEN, OnDenfen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaGrade message handlers

//载入学生
void DiaGrade::OnLoadStu() 
{
	// TODO: Add your control notification handler code here

	UpdateData();

	char*cs;
	cs= (LPSTR)(LPCTSTR)m_listmc;
//	MessageBox(m_listmc,"OnLoadStu",MB_OK);
	SendDlgItemMessage(IDC_GCurC,WM_SETTEXT,0,(LPARAM)cs);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	CString cid,cname,sid;

	//课程名-->课程号
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_listmc);
	cr.Open(CRecordset::snapshot,sql);
	cr.GetFieldValue("course_ID",cid);
	cr.Close();

	sql.Format("select * from xkxt.dbo.score where course_ID=\'%s\'",cid);
	cr.Open(CRecordset::snapshot,sql);

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}

	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTGH);
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTNG);

	pListB->ResetContent();
	pListC->ResetContent();

	CString temp;
	CString Nname[20];
	CString Yname[20];
	int iN=0,iY=0;

	while(!cr.IsEOF())
	{
//		cr.GetFieldValue("course_ID",cc);
//		if(c==cc)
//		{
			cr.GetFieldValue("student_ID",sid);
			cr.GetFieldValue("score",temp);
			if(temp=="")
			{
//				cr.GetFieldValue("student_ID",Nname[iN]);
				Nname[iN]=sid;
				pListC->AddString(Nname[iN]);
				iN++;
			}
			else
			{
//				cr.GetFieldValue("student_ID",Yname[iY]);
				Yname[iY]=sid;
				pListB->AddString(Yname[iY]);
				iY++;
			}
			cr.MoveNext();
//		}
	}

	cr.Close();
	db.Close();
}

void DiaGrade::OnDenfen() 
{
	// TODO: Add your control notification handler code here
	char c1[10],c2[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_GSID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_GSSC,WM_GETTEXT,10,(LPARAM)c2);

	//MessageBox(c1,NULL,MB_OK);
	//MessageBox(c2,NULL,MB_OK);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	CString cid,cname,sid;

	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_listmc);
	cr.Open(CRecordset::snapshot,sql);
	cr.GetFieldValue("course_ID",cid);
	cr.Close();

	//判断学号是否此课学生
	CString sgid;
	bool flag=false;

	sql.Format("select * from xkxt.dbo.score where course_ID=\'%s\'",cid);
	cr.Open(CRecordset::snapshot,sql);
	if (!cr.IsBOF())
	{
		cr.MoveFirst();
	}
	while (!cr.IsEOF())
	{
		cr.GetFieldValue("student_ID",sgid);

		if (sgid==c1)
		{
			flag=true;
			break;
		}
		cr.MoveNext();
	}

	if (flag)
	{
		sql.Format("update xkxt.dbo.score set score=\'%s\' where course_ID=\'%s\' and student_ID=\'%s\' ",c2,cid,c1);
	//	MessageBox(sql,NULL,MB_OK);
		db.ExecuteSQL(sql);
	}
	else
	{
		MessageBox("不是该课学生","提示",MB_OK);
	}
	cr.Close();


	//课程名-->课程号
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_listmc);
	cr.Open(CRecordset::snapshot,sql);
	cr.GetFieldValue("course_ID",cid);
	cr.Close();

	sql.Format("select * from xkxt.dbo.score where course_ID=\'%s\'",cid);
	cr.Open(CRecordset::snapshot,sql);

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}

	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTGH);
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTNG);

	pListB->ResetContent();
	pListC->ResetContent();

	CString temp;
	CString Nname[20];
	CString Yname[20];
	int iN=0,iY=0;

	while(!cr.IsEOF())
	{
//		cr.GetFieldValue("course_ID",cc);
//		if(c==cc)
//		{
			cr.GetFieldValue("student_ID",sid);
			cr.GetFieldValue("score",temp);
			if(temp=="")
			{
//				cr.GetFieldValue("student_ID",Nname[iN]);
				Nname[iN]=sid;
				pListC->AddString(Nname[iN]);
				iN++;
			}
			else
			{
//				cr.GetFieldValue("student_ID",Yname[iY]);
				Yname[iY]=sid;
				pListB->AddString(Yname[iY]);
				iY++;
			}
			cr.MoveNext();
//		}
	}

	cr.Close();

	db.Close();
}
