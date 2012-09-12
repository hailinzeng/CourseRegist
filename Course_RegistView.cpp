// Course_RegistView.cpp : implementation of the CCourse_RegistView class
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "Course_RegistDoc.h"
#include "Course_RegistView.h"

/*#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif*/


/*========================
名称:	2008 Software Engineering Practice Project

作者:	第13组成员

日期:	2008年9月10日-2008年9月13日
==========================*/

//CString-->char*
//cs= (LPSTR)(LPCTSTR)ps;
//string-->char*
//const char* c2= m_ID.c_str();
//string-->cstring
//temp.Format("%s", m_ID.c_str()); 

//头文件

#include "sys.h"
#include "Global.h"
#include "DiaLogin.h"
#include "DiaMPassWord.h"
#include "DiaAddStu.h"
#include "DiaDelStu.h"
#include "DiaMStu.h"
#include "DiaAddPro.h"
#include "DiaDelPro.h"
#include "DiaMPro.h"
#include "DiaAddCS.h"
#include "DiaDelCS.h"
#include "DiaMCS.h"
#include "DiaTSC.h"
#include "DiaSSC.h"
#include "DiaGrade.h"
#include "DiaMScore.h"

DiaTSC dltsc;
CString m_dts_id;//ID传参数

//开启菜单
bool GrayLogin;
bool GrayLogout;
bool GrayAddStu;
bool GrayDelStu;
bool GrayMStu;
bool GrayAddPro;
bool GrayDelPro;
bool GrayMPro;
bool GrayAddCS;
bool GrayDelCS;
bool GrayMCS;
bool GrayMPS;
bool GraySHIF;
bool GrayTSC;
bool GraySSC;
bool GrayRScore;//登分
bool GrayCScore;//查分
bool GrayNextStep;

//全局变量
int MX,MY;//屏幕大小

CString		infomation;//提示信息
/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView

IMPLEMENT_DYNCREATE(CCourse_RegistView, CView)

BEGIN_MESSAGE_MAP(CCourse_RegistView, CView)
	//{{AFX_MSG_MAP(CCourse_RegistView)
	ON_COMMAND(IDM_LOGIN,		OnLogin)
	ON_COMMAND(IDM_MPassWord,	OnMPassWord)
	ON_COMMAND(IDM_AddStu,		OnAddStu)
	ON_COMMAND(IDM_LOGOUT,		OnLogout)
	ON_COMMAND(IDM_DelStu,		OnDelStu)
	ON_COMMAND(IDM_MStu,		OnMStu)
	ON_COMMAND(IDM_AddPro,		OnAddPro)
	ON_COMMAND(IDM_DelPro,		OnDelPro)
	ON_COMMAND(IDM_MPro,		OnMPro)
	ON_COMMAND(IDM_AddCS,		OnAddCS)
	ON_COMMAND(IDM_DelCS,		OnDelCS)
	ON_COMMAND(IDM_MCS,			OnMcs)
	ON_UPDATE_COMMAND_UI(IDM_LOGIN,		OnUpdateLogin)
	ON_UPDATE_COMMAND_UI(IDM_LOGOUT,	OnUpdateLogout)
	ON_UPDATE_COMMAND_UI(IDM_AddStu,	OnUpdateAddStu)
	ON_UPDATE_COMMAND_UI(IDM_AddPro,	OnUpdateAddPro)
	ON_UPDATE_COMMAND_UI(IDM_AddCS,		OnUpdateAddCS)
	ON_UPDATE_COMMAND_UI(IDM_DelCS,		OnUpdateDelCS)
	ON_UPDATE_COMMAND_UI(IDM_DelPro,	OnUpdateDelPro)
	ON_UPDATE_COMMAND_UI(IDM_DelStu,	OnUpdateDelStu)
	ON_UPDATE_COMMAND_UI(IDM_MCS,		OnUpdateMcs)
	ON_UPDATE_COMMAND_UI(IDM_MPro,		OnUpdateMPro)
	ON_UPDATE_COMMAND_UI(IDM_MStu,		OnUpdateMStu)
	ON_UPDATE_COMMAND_UI(IDM_MPassWord, OnUpdateMPassWord)
	ON_UPDATE_COMMAND_UI(IDM_INFORMATION, OnUpdateInformation)
	ON_COMMAND(IDM_TSC,		OnTsc)
	ON_UPDATE_COMMAND_UI(IDM_TSC, OnUpdateTsc)
	ON_COMMAND(IDM_SSC,		OnSsc)
	ON_UPDATE_COMMAND_UI(IDM_SSC, OnUpdateSsc)
	ON_COMMAND(IDM_GRADE,	OnGrade)
	ON_UPDATE_COMMAND_UI(IDM_GRADE,		OnUpdateGrade)
	ON_COMMAND(IDM_MSCORE,	OnMscore)
	ON_UPDATE_COMMAND_UI(IDM_MSCORE,	OnUpdateMscore)
	ON_COMMAND(IDM_NextStep,OnNextStep)
	ON_UPDATE_COMMAND_UI(IDM_NextStep,	OnUpdateNextStep)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT,			CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT,	CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW,	CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView construction/destruction

CCourse_RegistView::CCourse_RegistView()
{
	// TODO: add construction code here

	//获取屏幕大小
	MX=GetSystemMetrics(SM_CXSCREEN)/2;
	MY=GetSystemMetrics(SM_CYSCREEN)/2;

	GrayLogin	=true;
	GrayLogout	=false;

	GrayAddStu	=false;
	GrayDelStu	=false;
	GrayMStu	=false;
	GrayAddPro	=false;
	GrayDelPro	=false;
	GrayMPro	=false;
	GrayAddCS	=false;
	GrayDelCS	=false;
	GrayMCS		=false;
	GrayMPS		=false;
	GraySHIF	=false;
	GrayTSC		=false;
	GraySSC		=false;
	GrayRScore	=false;
	GrayCScore	=false;
	GrayNextStep=false;

	s.Time=_T("");
}

CCourse_RegistView::~CCourse_RegistView()
{
}

BOOL CCourse_RegistView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView drawing

void CCourse_RegistView::OnDraw(CDC* pDC)
{
	CCourse_RegistDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	//CString与string
	CString n_name(m_ID.data());

	switch(DrawMode) 
	{
	//未登录
	case ModeULogin:

		infomation=_T("请登录...");

		break;

	//登录成功	
	case ModeLogin:

		pDC->SetTextColor(RGB(255,102,0));
		pDC->TextOut(MX+250,MY-350,_T("欢迎使用选课系统......"));

		pDC->SetTextColor(RGB(65,180,65));
		pDC->TextOut(MX/4-20,MY-250,n_name);

		if (s.A_R[0]=='s')
		{
			pDC->TextOut(MX/4+50,MY-250,"同学");
		}
		else
		{
			if(s.A_R[0]=='p')
			{
				pDC->TextOut(MX/4+50,MY-250,"老师");
			}
			else
			{
				pDC->TextOut(MX/4+50,MY-250,"管理员");
			}
		}

		pDC->SetTextColor(RGB(255,0,0));
		pDC->TextOut(MX/4+100,MY-250,"已登陆...");

		
		//pDC->TextOut(MX/4+200,MY-250,s.Time);

		infomation=s.Time;

		break;

	//登录失败
	case ModeFLogin:

		infomation=_T(MX-50,MY-50,_T("用户名密码错误..."));

		break;
	//default:
	}

	pDC->SetTextColor(RGB(255,0,0));
	pDC->TextOut(MX-150,MY-150,infomation);

	if (s.Time=="选课前")
	{
		GrayTSC		=false;
		GraySSC		=false;
		GrayRScore	=false;
		GrayCScore	=false;
		GrayAddCS	=false;
		GrayDelCS	=false;
		GrayMCS		=false;
	}
	else if (s.Time=="管理员添加课程")
	{
		GrayTSC		=false;
		GraySSC		=false;
		GrayRScore	=false;
		GrayCScore	=false;

		if (s.A_R[0]=='a')
		{
			GrayAddCS	=true;
			GrayDelCS	=true;
			GrayMCS		=true;
		}
	}
	else if(s.Time=="教师选课阶段")
	{
		GraySSC		=false;
		GrayRScore	=false;
		GrayCScore	=false;
		GrayAddCS	=false;
		GrayDelCS	=false;
		GrayMCS		=false;

		if (s.A_R[0]=='p')
		{
			GrayTSC		=true;
		}
	}
	else if (s.Time=="管理员筛选课程")
	{
		if (s.A_R[0]=='a')
		{
			GrayAddCS	=true;
			GrayDelCS	=true;
			GrayMCS		=true;
		}
		GrayTSC		=false;
		GraySSC		=false;
		GrayRScore	=false;
		GrayCScore	=false;
	}
	else if (s.Time=="学生选课阶段")
	{
		if (s.A_R[0]=='s')
		{
			GraySSC	=true;
		}
		GrayCScore	=false;
		GrayRScore	=false;
		GrayAddCS	=false;
		GrayDelCS	=false;
		GrayMCS		=false;
	}
	else if (s.Time=="管理员关闭选课")
	{
		GrayTSC		=false;
		GraySSC		=false;
		GrayRScore	=false;
		GrayCScore	=false;
		GrayAddCS	=false;
		GrayDelCS	=false;
		GrayMCS		=false;
	}
	else if (s.Time=="教师登记分数")
	{
		GrayTSC		=false;
		GraySSC		=false;
		GrayAddCS	=false;
		GrayDelCS	=false;
		GrayMCS		=false;

		if (s.A_R[0]=='p')
		{
			GrayRScore=true;
			GrayCScore=false;
		}else if (s.A_R=="s")
		{
			GrayRScore=false;
			GrayCScore=true;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView printing

BOOL CCourse_RegistView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCourse_RegistView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCourse_RegistView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView diagnostics

#ifdef _DEBUG
void CCourse_RegistView::AssertValid() const
{
	CView::AssertValid();
}

void CCourse_RegistView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCourse_RegistDoc* CCourse_RegistView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCourse_RegistDoc)));
	return (CCourse_RegistDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCourse_RegistView message handlers

/*========================

  登录系统

==========================*/
//菜单调用登录对话框
void CCourse_RegistView::OnLogin()
{
	// TODO: Add your command handler code here
	DiaLogin dlogin;
	dlogin.DoModal();

	Invalidate(TRUE);
}

//登录对话框处理
void DiaLogin::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_NAME,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_PASSWORD,WM_GETTEXT,10,(LPARAM)c2);

	m_ID=string(c1);
	m_password=string(c2);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//查询数据库
	sql.Format("select * from xkxt.dbo.login where ID=\'%s\'",c1);
	cr.Open(CRecordset::snapshot,sql);

	//对应的密码
	CString ps;
	cr.GetFieldValue("password",ps);

	//输入的密码
	CString ss=(LPCSTR)c2;

	//验证是否一致
	if(ps!=ss)
	{
		MessageBox("登录错误","用户名密码错误",MB_OK);

		cr.Close();
		db.Close();
	}
	else
	{
		DrawMode=ModeLogin;

		GrayLogin	=false;
		GrayLogout	=true;
		GrayMPS		=true;//?

		//该ID的权限
		cr.GetFieldValue("aut_right",ps);
		cr.Close();

		//选课阶段
		sql.Format("select * from xkxt.dbo.time");
		cr.Open(CRecordset::snapshot,sql);
		cr.GetFieldValue("T",s.Time);
		cr.Close();

		//char str1[10];
		sprintf(s.A_R,"%s",ps);

		//根据身份开启相关功能
		switch(s.A_R[0])
		{
		case 'a':
			GrayAddStu	=true;
			GrayDelStu	=true;
			GrayMStu	=true;
			GrayAddPro	=true;
			GrayDelPro	=true;
			GrayMPro	=true;
			GrayAddCS	=true;
			GrayDelCS	=true;
			GrayMCS		=true;
			GrayNextStep=true;
			break;

		case 'p':
			GrayTSC		=true;
			GrayRScore	=true;//登分
			break;

		case 's':
			GraySSC		=true;
			GrayCScore	=true;//查分
			break;

		default:
		    break;
		}

	
		db.Close();

		EndDialog(true);
	}
	
	
	CDialog::OnOK();
}

/*========================

  菜单管理

==========================*/

void CCourse_RegistView::OnUpdateLogin(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayLogin);
}

void CCourse_RegistView::OnUpdateLogout(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayLogout);
}

void CCourse_RegistView::OnUpdateAddStu(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayAddStu);
}

void CCourse_RegistView::OnUpdateAddPro(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayDelPro);
}

void CCourse_RegistView::OnUpdateAddCS(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayAddCS);
}

void CCourse_RegistView::OnUpdateDelCS(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayDelCS);
}

void CCourse_RegistView::OnUpdateDelPro(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayDelPro);
}

void CCourse_RegistView::OnUpdateDelStu(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayDelStu);
}

void CCourse_RegistView::OnUpdateMcs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayMCS);
}

void CCourse_RegistView::OnUpdateMPro(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayMPro);
}

void CCourse_RegistView::OnUpdateMStu(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayMStu);
}

void CCourse_RegistView::OnUpdateMPassWord(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayMPS);
}

void CCourse_RegistView::OnUpdateInformation(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GraySHIF);
}

void CCourse_RegistView::OnUpdateTsc(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(GrayTSC);
	// TODO: Add your command update UI handler code here
	
}

void CCourse_RegistView::OnUpdateSsc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GraySSC);
}

void CCourse_RegistView::OnUpdateGrade(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayRScore);
}
void CCourse_RegistView::OnUpdateMscore(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayCScore);
}
void CCourse_RegistView::OnUpdateNextStep(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(GrayNextStep);
}


/*========================

  学生管理

==========================*/
//菜单调用添加学生
void CCourse_RegistView::OnAddStu() 
{
	// TODO: Add your command handler code here
	DiaAddStu dlastu;
	dlastu.DoModal();

	Invalidate(TRUE);
}

//添加学生对话框处理
void DiaAddStu::OnOK() 
{
	// TODO: Add extra validation here
	
	char c1[10],c2[10],c3[10],c4[10],c5[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_ASID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_ASNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_ASBD,WM_GETTEXT,10,(LPARAM)c3);
	SendDlgItemMessage(IDC_ASGD,WM_GETTEXT,10,(LPARAM)c5);
	SendDlgItemMessage(IDC_ASST,WM_GETTEXT,10,(LPARAM)c4);
	
	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("insert into xkxt.dbo.students values(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\')",c1,c2,c3,c4,c5);
	db.ExecuteSQL(sql);

	sql.Format("insert into xkxt.dbo.login values(\'%s\',\'%s\',\'student\')",c1,c1);
	db.ExecuteSQL(sql);

	infomation="添加学生成功!";

	db.Close();

	CDialog::OnOK();
}

//菜单调用删除学生
void CCourse_RegistView::OnDelStu() 
{
	// TODO: Add your command handler code here
	DiaDelStu dlds;
	dlds.DoModal();
	
	Invalidate(TRUE);
}

//删除学生对话框处理
void DiaDelStu::OnDelStu() 
{
	// TODO: Add your control notification handler code here
	char c1[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_DelStu,WM_GETTEXT,10,(LPARAM)c1);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("delete from xkxt.dbo.students where student_ID=\'%s\'",c1);
	db.ExecuteSQL(sql);

	sql.Format("delete from xkxt.dbo.login where ID=\'%s\'",c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="删除学生成功!";

	EndDialog(true);/////////////////!!!!!!!!!!!!!!!
}

//菜单调用修改学生
void CCourse_RegistView::OnMStu() 
{
	// TODO: Add your command handler code here
	DiaMStu dlmstu;
	dlmstu.DoModal();
	
	Invalidate(TRUE);
}

//获取学生信息
void DiaMStu::OnMGetInfo() 
{
	// TODO: Add your control notification handler code here
	char c0[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_MStuSC,WM_GETTEXT,10,(LPARAM)c0);

	//连接到数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//查询数据库
	sql.Format("select * from xkxt.dbo.students where student_ID=\'%s\'",c0);
	cr.Open(CRecordset::snapshot,sql);

	//更新到对话框
	CString ps;
	char* cs;

	SendDlgItemMessage(IDC_MStuID,WM_SETTEXT,0,(LPARAM)c0);

	cr.GetFieldValue("student_name",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MStuNM,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("birthdate",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MStuBD,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("status",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MStuST,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("grade",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MStuGD,WM_SETTEXT,0,(LPARAM)cs);

	cr.Close();
	db.Close();
}

//提交修改学生信息
void DiaMStu::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10],c3[10],c4[10],c5[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_MStuID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_MStuNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_MStuBD,WM_GETTEXT,10,(LPARAM)c3);
	SendDlgItemMessage(IDC_MStuGD,WM_GETTEXT,10,(LPARAM)c4);
	SendDlgItemMessage(IDC_MStuST,WM_GETTEXT,10,(LPARAM)c5);
	
	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	char c0[10];
	SendDlgItemMessage(IDC_MStuSC,WM_GETTEXT,10,(LPARAM)c0);

	//修改数据库
	sql.Format("update xkxt.dbo.students set student_ID=\'%s\' where student_ID=\'%s\'",c1,c0);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.students set student_name=\'%s\' where student_ID=\'%s\'",c2,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.students set birthdate=\'%s\' where student_ID=\'%s\'",c3,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.students set grade=\'%s\' where student_ID=\'%s\'",c4,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.students set status=\'%s\' where student_ID=\'%s\'",c5,c1);
	db.ExecuteSQL(sql);

	//账号
	sql.Format("update xkxt.dbo.login set ID=\'%s\' where ID=\'%s\'",c1,c0);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="修改学生成功!";

	CDialog::OnOK();//
}

/*========================

  教师管理

==========================*/
//菜单调用添加教师
void CCourse_RegistView::OnAddPro() 
{
	// TODO: Add your command handler code here
	DiaAddPro dladdpro;
	dladdpro.DoModal();
	
	Invalidate(TRUE);
}

//添加教师对话框
void DiaAddPro::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10],c3[10],c4[10],c5[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_APID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_APNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_APBD,WM_GETTEXT,10,(LPARAM)c3);
	SendDlgItemMessage(IDC_APDP,WM_GETTEXT,10,(LPARAM)c5);
	SendDlgItemMessage(IDC_APST,WM_GETTEXT,10,(LPARAM)c4);

	//连接到数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("insert into xkxt.dbo.professor values(\'%s\',\'%s\',\'%s\',\'%s\',\'%s\')",c1,c2,c3,c4,c5);
	db.ExecuteSQL(sql);

	//修改数据库
	sql.Format("insert into xkxt.dbo.login values(\'%s\',\'%s\',\'professor\')",c1,c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="添加教师成功!";

	CDialog::OnOK();
}

//菜单调用删除教师
void CCourse_RegistView::OnDelPro() 
{
	// TODO: Add your command handler code here
	DiaDelPro dldelpro;
	dldelpro.DoModal();

	Invalidate(TRUE);
}

//删除教师对话框处理
void DiaDelPro::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_DelPro,WM_GETTEXT,10,(LPARAM)c1);

	//连接到数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("delete from xkxt.dbo.professor where professor_ID=\'%s\'",c1);
	db.ExecuteSQL(sql);

	sql.Format("delete from xkxt.dbo.login where ID=\'%s\'",c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="删除教师成功!";

	EndDialog(true);

	CDialog::OnOK();
}

//菜单调用修改教师
void CCourse_RegistView::OnMPro() 
{
	// TODO: Add your command handler code here
	DiaMpro dlmpro;
	dlmpro.DoModal();
		
	Invalidate(TRUE);
}

//获取教师信息
void DiaMpro::OnMGetInfo() 
{
	// TODO: Add your control notification handler code here
	char c0[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_MProSC,WM_GETTEXT,10,(LPARAM)c0);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//查询数据库
	sql.Format("select * from xkxt.dbo.professor where professor_ID=\'%s\'",c0);
	cr.Open(CRecordset::snapshot,sql);

	//更新到对话框
	CString ps;
	char* cs;

	SendDlgItemMessage(IDC_MProID,WM_SETTEXT,0,(LPARAM)c0);

	cr.GetFieldValue("professor_name",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MProNM,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("birthdate",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MProBD,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("professor_status",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MProST,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("department",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MProDP,WM_SETTEXT,0,(LPARAM)cs);

	cr.Close();
	db.Close();
}

//提交修改教师信息
void DiaMpro::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10],c3[10],c4[10],c5[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_MProID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_MProNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_MProBD,WM_GETTEXT,10,(LPARAM)c3);
	SendDlgItemMessage(IDC_MProDP,WM_GETTEXT,10,(LPARAM)c4);
	SendDlgItemMessage(IDC_MProST,WM_GETTEXT,10,(LPARAM)c5);
	
	//连接到数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	char c0[10];
	SendDlgItemMessage(IDC_MProSC,WM_GETTEXT,10,(LPARAM)c0);//原

	//账号
	sql.Format("update xkxt.dbo.login set ID=\'%s\' where ID=\'%s\'",c1,c0);
	db.ExecuteSQL(sql);

	//
	sql.Format("update xkxt.dbo.professor set professor_ID=\'%s\' where professor_ID=\'%s\'",c1,c0);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.professor set professor_name=\'%s\' where professor_ID=\'%s\'",c2,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.professor set birthdate=\'%s\' where professor_ID=\'%s\'",c3,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.professor set department=\'%s\' where professor_ID=\'%s\'",c4,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.professor set professor_status=\'%s\' where professor_ID=\'%s\'",c5,c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="修改教师成功!";

	CDialog::OnOK();
}

/*========================

  课程管理

==========================*/
//菜单调用添加课程
void CCourse_RegistView::OnAddCS() 
{
	// TODO: Add your command handler code here
	DiaAddCS dladdcs;
	dladdcs.DoModal();

	Invalidate(TRUE);
}

//添加课程对话框处理
void DiaAddCS::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10],c3[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_ACSID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_ACSNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_ACSTY,WM_GETTEXT,10,(LPARAM)c3);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("insert into xkxt.dbo.course (course_ID,course_name,course_type)values(\'%s\',\'%s\',\'%s\')",c1,c2,c3);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="添加课程成功!";

	CDialog::OnOK();
}

//菜单调用删除课程
void CCourse_RegistView::OnDelCS() 
{
	// TODO: Add your command handler code here
	DiaDelCS dldelcs;
	dldelcs.DoModal();
	
	Invalidate(TRUE);
}

//删除课程对话框处理
void DiaDelCS::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10];

	//获取对话框信息
	SendDlgItemMessage(IDC_DelCS,WM_GETTEXT,10,(LPARAM)c1);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("delete from xkxt.dbo.course where course_ID=\'%s\'",c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="删除课程成功!";

	EndDialog(true);

	CDialog::OnOK();
}

//菜单调用修改课程信息
void CCourse_RegistView::OnMcs() 
{
	// TODO: Add your command handler code here
	DiaMCS dlmcs;
	dlmcs.DoModal();

	Invalidate(TRUE);
}

//获取课程信息
void DiaMCS::OnMGetInfo() 
{
	// TODO: Add your control notification handler code here
	char c0[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_MCSSC,WM_GETTEXT,10,(LPARAM)c0);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//查询数据库
	sql.Format("select * from xkxt.dbo.course where course_ID=\'%s\'",c0);
	cr.Open(CRecordset::snapshot,sql);

	//更新到对话框
	CString ps;
	char* cs;

	SendDlgItemMessage(IDC_MCSID,WM_SETTEXT,0,(LPARAM)c0);

	cr.GetFieldValue("course_name",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MCSNM,WM_SETTEXT,0,(LPARAM)cs);

	cr.GetFieldValue("course_type",ps);
	cs= (LPSTR)(LPCTSTR)ps;
	SendDlgItemMessage(IDC_MCSTY,WM_SETTEXT,0,(LPARAM)cs);

	cr.Close();
	db.Close();
}

//修改课程信息对话框处理
void DiaMCS::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10],c2[10],c3[10];
	
	//获取对话框信息
	SendDlgItemMessage(IDC_MCSID,WM_GETTEXT,10,(LPARAM)c1);
	SendDlgItemMessage(IDC_MCSNM,WM_GETTEXT,10,(LPARAM)c2);
	SendDlgItemMessage(IDC_MCSTY,WM_GETTEXT,10,(LPARAM)c3);
	
	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	char c0[10];
	SendDlgItemMessage(IDC_MCSSC,WM_GETTEXT,10,(LPARAM)c0);

	sql.Format("update xkxt.dbo.course set course_ID=\'%s\' where course_ID=\'%s\'",c1,c0);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.course set course_name=\'%s\' where course_ID=\'%s\'",c2,c1);
	db.ExecuteSQL(sql);

	sql.Format("update xkxt.dbo.course set course_type=\'%s\' where course_ID=\'%s\'",c3,c1);
	db.ExecuteSQL(sql);

	db.Close();

	infomation="修改课程成功!";

	CDialog::OnOK();
}


/*=============================

		显示个人信息

【此项功能作废，直接在屏幕显示】

==============================*/


/*========================

  修改密码

==========================*/
//菜单调用修改密码
void CCourse_RegistView::OnMPassWord() 
{
	// TODO: Add your command handler code here
	DiaMPassWord dlmpassword;
	dlmpassword.DoModal();
	
	Invalidate(TRUE);
}

//修改密码对话框处理
void DiaMPassWord::OnOK() 
{
	// TODO: Add extra validation here
	char c1[10];
	const char* c2= m_ID.c_str();
	
	//获取对话框信息
	SendDlgItemMessage(IDC_NewPassword,WM_GETTEXT,10,(LPARAM)c1);
	
	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//修改数据库
	sql.Format("update xkxt.dbo.login set password=\'%s\' where ID=\'%s\'",c1,c2);
	db.ExecuteSQL(sql);
	db.Close();
	
	infomation="修改密码成功!";

	CDialog::OnOK();
}
/*========================

  教授选课

==========================*/
//菜单调用显示教师选课对话框
void CCourse_RegistView::OnTsc() 
{
	// TODO: Add your command handler code here

	//m_ID正确

	DiaTSC dltsc;
	dltsc.DoModal();

	Invalidate(TRUE);
}

//初始化列表内容
BOOL DiaTSC::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//获取ID
	m_dts_id.Format("%s",m_ID.c_str());
	//MessageBox(m_dts_id,"OnInitDialog",MB_OK);
	//m_dts_id正确

	// TODO: Add extra initialization here
	
	//列表框
	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTTTS);
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTTHS);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	int j=0;

	//所有可选课程
	sql.Format("select * from xkxt.dbo.course");
	cr.Open(CRecordset::snapshot,sql);

	int iA=0;
	CString a[20];//可选

	if(!cr.IsBOF())//course_name-->a[]
	{
		cr.MoveFirst();
	}
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("course_name",a[iA]);
		iA++;
		cr.MoveNext();
	}

	for(j=0;j<iA;j++)//添加到可选列表框
	{
		pListB->AddString(a[j]);
	}
	
	cr.Close();

	//所有已选课程
	sql.Format("select * from xkxt.dbo.course where selected=\'y\'");
	cr.Open(CRecordset::snapshot,sql);

	int iB=0;
	CString b[20];//已选

	if(!cr.IsBOF())//course_name-->b[]
	{
		cr.MoveFirst();
	}

	CString temp,pid;
	temp.Format("%s", m_ID.c_str()); 

	while(!cr.IsEOF())
	{
		cr.GetFieldValue("professor_ID",pid);
		if(pid==temp)
		{
			cr.GetFieldValue("course_name",b[iB]);
			iB++;
		}
		cr.MoveNext();
	}
	for(j=0;j<iB;j++)//添加到已选列表框
	{
		pListC->AddString(b[j]);
	}

	cr.Close();
	db.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

//执行(选课或退选)
void DiaTSC::OnTexcute() 
{
	// TODO: Add your control notification handler code here
	//UpdateData();

	//m_dts_id通过
	//MessageBox(m_dts_id,"OnTexcute",MB_OK);

	OnTexcuteX(m_dts_id);
}
/*========================

  学生选课

==========================*/

//菜单调用显示对话框
void CCourse_RegistView::OnSsc() 
{
	// TODO: Add your command handler code here
	DiaSSC dlssc;
	dlssc.DoModal();

	Invalidate(TRUE);
}

//初始化对话框 列表内容
BOOL DiaSSC::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	//获取ID
	m_dts_id.Format("%s",m_ID.c_str());

	// TODO: Add extra initialization here
	
	//列表框
	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTSTS);
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTSHS);

	//打开数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	int j=0;

	int iA=0;
	CString a[20];//可选

	//列出所有课程
	sql.Format("select * from xkxt.dbo.course");
	cr.Open(CRecordset::snapshot,sql);
	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("course_name",a[iA]);
		iA++;
		cr.MoveNext();
	}
	for(j=0;j<iA;j++)//添加到可选列表框
	{
		pListB->AddString(a[j]);
	}
	cr.Close();

	int iB=0;
	CString b[6];//已选
	CString cty;
	optional=2;
	obligatory=4;

	//已选课程
	sql.Format("select * from xkxt.dbo.score where student_ID=\'%s\'",m_dts_id);
	cr.Open(CRecordset::snapshot,sql);
	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("course_ID",b[iB]);
		iB++;
		cr.MoveNext();
	}
	cr.Close();

	for(j=0;j<iB;j++)
	{
		sql.Format("select * from xkxt.dbo.course where course_ID=\'%s\'",b[j]);
		cr.Open(CRecordset::snapshot,sql);
		cr.GetFieldValue("course_name",b[j]);

		cr.GetFieldValue("course_type",cty);
		if (cty=="选修课")
		{
			obligatory--;
		}
		else
		{
			optional--;
		}

		cr.Close();
	}
	for(j=0;j<iB;j++)//添加到可选列表框
	{
		pListC->AddString(b[j]);
	}
	//cr.Close();
	db.Close();

	CString o;
	o.Format("%d",obligatory);
	char*cs;
	cs= (LPSTR)(LPCTSTR)o;
	SendDlgItemMessage(IDC_StuSLB,WM_SETTEXT,0,(LPARAM)cs);

	o.Format("%d",optional);
	cs= (LPSTR)(LPCTSTR)o;
	SendDlgItemMessage(IDC_StuSLX,WM_SETTEXT,0,(LPARAM)cs);

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//查询课程信息
void DiaSSC::OnSSeekCIF() 
{
	// TODO: Add your control notification handler code here
		// TODO: Add your control notification handler code here
	UpdateData();
	
	//MessageBox(m_dts_id,"OnSSeekCIF",MB_OK);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//用课程名查询数据库
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_ListSts);
	cr.Open(CRecordset::snapshot,sql);

	//获取该课程的各项信息
	CString m0,m1,m2,m3,m4,m5;

	//访问有顺序!!!!!!!!!!!!!!!!!!!!
	cr.GetFieldValue("course_ID",m0);
	cr.GetFieldValue("professor_ID",m2);
	cr.GetFieldValue("course_name",m1);
	cr.GetFieldValue("course_type",m3);
	cr.GetFieldValue("stu_number",m4);

	char* cs= (LPSTR)(LPCTSTR)m0;
	SendDlgItemMessage(IDC_SSCID,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m1;
	SendDlgItemMessage(IDC_SSCNM,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m2;
	SendDlgItemMessage(IDC_SSCT,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m3;
	SendDlgItemMessage(IDC_SSCTY,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m4;
	SendDlgItemMessage(IDC_SSSLTED,WM_SETTEXT,10,(LPARAM)cs);

	cr.Close();

	//m_dts_id通过
	//MessageBox(m_dts_id,"m_dts_id",MB_OK);

	//清空状态
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(false);

	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_ListSts);
	cr.Open(CRecordset::snapshot,sql);

	CString cid;
	cr.GetFieldValue("course_ID",cid);
	cr.Close();

	sql.Format("select * from xkxt.dbo.score where course_ID=\'%s\'",cid);
	cr.Open(CRecordset::snapshot,sql);

	int i=0;
	CString tid[20];

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("student_ID",tid[i]);
		i++;
		cr.MoveNext();
	}

	for(int j=0;j<i;j++)
	{
		if (tid[j]==m_dts_id)
		{
			((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(true);
			break;
		}
	}

	//设置radio
	if (!((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
	{
		((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(true);
	}
	
	cr.Close();
	db.Close();
}

//执行(选课或退选)
void DiaSSC::OnSexcute() 
{
	// TODO: Add your control notification handler code here
	OnSexcuteX(m_dts_id);
}

/*========================

	教师登分

==========================*/

//菜单调用登分
void CCourse_RegistView::OnGrade() 
{
	// TODO: Add your command handler code here
	DiaGrade dlgrade;
	dlgrade.DoModal();
	
	Invalidate(TRUE);
}

//初始化对话框内容
BOOL DiaGrade::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//获取ID
	m_dts_id.Format("%s",m_ID.c_str());
	
	//列表框
	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTMC);
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTNG);

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//列出所教课程

	//所有教的课程
	sql.Format("select * from xkxt.dbo.course where selected=\'y\' and professor_ID =\'%s\'",m_dts_id);
	cr.Open(CRecordset::snapshot,sql);

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}

	CString cname;
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("course_name",cname);
		pListB->AddString(cname);
		cr.MoveNext();
	}
	cr.Close();

	db.Close();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
/*========================

	查看成绩

==========================*/

//菜单调用显示成绩查询对话框
void CCourse_RegistView::OnMscore() 
{
	// TODO: Add your command handler code here
	DiaMScore dlmyscore;
	dlmyscore.DoModal();

	Invalidate(TRUE);
}

BOOL DiaMScore::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//获取ID
	m_dts_id.Format("%s",m_ID.c_str());

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//列出所教课程

	//所有教的课程
	sql.Format("select * from xkxt.dbo.score where student_ID=\'%s\'",m_dts_id);
	cr.Open(CRecordset::snapshot,sql);

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}

	CString cname[6],score[6];
	int coursenumber=0;

	while(!cr.IsEOF())
	{
		cr.GetFieldValue("course_ID",cname[coursenumber]);
		cr.GetFieldValue("score",score[coursenumber]);

		coursenumber++;
		cr.MoveNext();
	}
	cr.Close();

	char*cs;

	for (int j=0;j<coursenumber;j++)
	{
		sql.Format("select * from xkxt.dbo.course where course_ID=\'%s\'",cname[j]);
		cr.Open(CRecordset::snapshot,sql);

		cr.GetFieldValue("course_name",cname[j]);

		cr.Close();

		switch(j)
		{
		case 0:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME1,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE1,WM_SETTEXT,0,(LPARAM)cs);
			break;
		case 1:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME2,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE2,WM_SETTEXT,0,(LPARAM)cs);
			break;
		case 2:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME3,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE3,WM_SETTEXT,0,(LPARAM)cs);
			break;
		case 3:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME4,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE4,WM_SETTEXT,0,(LPARAM)cs);
			break;
		case 4:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME5,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE5,WM_SETTEXT,0,(LPARAM)cs);
			break;
		case 5:
			cs= (LPSTR)(LPCTSTR)cname[j];
			SendDlgItemMessage(IDC_CNAME6,WM_SETTEXT,0,(LPARAM)cs);		
			cs=(LPSTR)(LPCTSTR)score[j];
			SendDlgItemMessage(IDC_CSCORE6,WM_SETTEXT,0,(LPARAM)cs);
			break;
		default:
			break;
		}
	}

	db.Close();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*========================

	选课阶段控制(管理员)

==========================*/
void CCourse_RegistView::OnNextStep() 
{
	// TODO: Add your command handler code here

	//连接数据库
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	if (s.Time=="选课前")
	{
		s.Time="管理员添加课程";
	}
	else if (s.Time=="管理员添加课程")
	{
		s.Time="教师选课阶段";
	}
	else if(s.Time=="教师选课阶段")
	{
		//删除没有教师选的课程
		sql.Format("delete from xkxt.dbo.course where selected=\'n\'");
		db.ExecuteSQL(sql);

		s.Time="管理员筛选课程";
	}
	else if (s.Time=="管理员筛选课程")
	{
		s.Time="学生选课阶段";
	}
	else if (s.Time=="学生选课阶段")
	{
		//删除人数不足3人的课程
		CString cid[20],cnum;
		int cinum[20];
		int index=0,number=0;

		sql.Format("select * from xkxt.dbo.course");
		cr.Open(CRecordset::snapshot,sql);
		
		if (!cr.IsBOF())
		{
			cr.MoveFirst();
		}
		while (!cr.IsEOF())
		{
			cr.GetFieldValue("course_ID",cid[index]);
			cr.GetFieldValue("stu_number",cnum);
			cinum[index]=atoi(cnum);

			index++;
			cr.MoveNext();
		}

		for (int i=0;i<index;i++) 
		{
		
			if (cinum[i]<3)
			{
				sql.Format("delete from xkxt.dbo.course where course_ID=\'%s\'",cid[i]);
				db.ExecuteSQL(sql);

				sql.Format("delete from xkxt.dbo.score where course_ID=\'%s\'",cid[i]);
				db.ExecuteSQL(sql);
			}
		}

		cr.Close();

		s.Time="管理员关闭选课";
	}
	else if (s.Time=="管理员关闭选课")
	{
		s.Time="教师登记分数";
	}
	else if (s.Time=="教师登记分数")
	{
		s.Time="选课前";
	}

	sql.Format("update xkxt.dbo.time set T=\'%s\'",s.Time);
	db.ExecuteSQL(sql);

	db.Close();

	Invalidate(TRUE);
}


//菜单调用退出系统
void CCourse_RegistView::OnLogout() 
{
	// TODO: Add your command handler code here
	DrawMode=ModeULogin;
	
	GrayLogin	=true;
	GrayLogout	=false;
	
	GrayAddStu	=false;
	GrayDelStu	=false;
	GrayMStu	=false;
	GrayAddPro	=false;
	GrayDelPro	=false;
	GrayMPro	=false;
	GrayAddCS	=false;
	GrayDelCS	=false;
	GrayMCS		=false;
	GrayMPS		=false;
	GraySHIF	=false;
	GrayTSC		=false;
	GraySSC		=false;
	GrayRScore	=false;
	GrayCScore	=false;
	GrayNextStep=false;

	s.Time		=_T("");
	
	Invalidate(TRUE);
}
//////////////////////////////////////////////////////////////////////////
