// DiaTSC.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaTSC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// DiaTSC dialog


DiaTSC::DiaTSC(CWnd* pParent /*=NULL*/)
	: CDialog(DiaTSC::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaTSC)
	m_ListTts = _T("");
	//}}AFX_DATA_INIT
}


void DiaTSC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaTSC)
	DDX_LBString(pDX, IDC_LISTTTS, m_ListTts);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaTSC, CDialog)
	//{{AFX_MSG_MAP(DiaTSC)
	ON_BN_CLICKED(IDC_SeekCIF, OnSeekCIF)
	ON_BN_CLICKED(IDC_TEXCUTE, OnTexcute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaTSC message handlers

void DiaTSC::OnOK() 
{
	// TODO: Add extra validation here

	CDialog::OnOK();
}

//��ȡ�γ���Ϣ
void DiaTSC::OnSeekCIF() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
	//MessageBox(m_ListTts,NULL,MB_OK);

	//�������ݿ�
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//�ÿγ�����ѯ���ݿ�
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_ListTts);
	cr.Open(CRecordset::snapshot,sql);

	//��ȡ�ÿγ̵ĸ�����Ϣ
	CString m0,m1,m2,m3,m4,m5;

	//������˳��!!!!!!!!!!!!!!!!!!!!
	cr.GetFieldValue("course_ID",m0);
	cr.GetFieldValue("professor_ID",m2);
	cr.GetFieldValue("course_name",m1);
	cr.GetFieldValue("course_type",m3);
	cr.GetFieldValue("stu_number",m4);
	cr.GetFieldValue("selected",m5);

	char* cs= (LPSTR)(LPCTSTR)m0;
	SendDlgItemMessage(IDC_TSCID,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m1;
	SendDlgItemMessage(IDC_TSCNM,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m2;
	SendDlgItemMessage(IDC_TSCT,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m3;
	SendDlgItemMessage(IDC_TSCTY,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m4;
	SendDlgItemMessage(IDC_TSSLTED,WM_SETTEXT,10,(LPARAM)cs);

	cs= (LPSTR)(LPCTSTR)m5;//���ܻ�������

	//���״̬
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(false);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(false);

	//����radio
	if (cs[0]=='y')
	{
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(true);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(true);
	}

	cr.Close();
	db.Close();
}

//ѡ�λ���ѡ
void DiaTSC::OnTexcuteX(CString m_dts_id)
{
	//�������ݿ�
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);

	//MessageBox(m_ListTts,"OnTexcuteX",MB_OK);

	//�ж��Ƿ���ѡ

	//�ÿγ�����ѯ���ݿ�
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_ListTts);
	cr.Open(CRecordset::snapshot,sql);

	CString selectornot;
	cr.GetFieldValue("selected",selectornot);

	if(selectornot[0]=='y')//��ѡ
	{
		if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
		{
			MessageBox("����ѡ","��ʾ",MB_OK);
		}
		else
		{
			MessageBox("��ѡ","��ʾ",MB_OK);

			//��ѡ
			sql.Format("update xkxt.dbo.course set professor_ID=\'\' where course_name=\'%s\'",m_ListTts);
			db.ExecuteSQL(sql);

			sql.Format("update xkxt.dbo.course set selected=\'%s\' where course_name=\'%s\'","n",m_ListTts);
			db.ExecuteSQL(sql);
		}

	}
	else//δѡ
	{
		if(((CButton *)GetDlgItem(IDC_RADIO1))->GetCheck())
		{
			//ѡ��
			MessageBox("ѡ��","��ʾ",MB_OK);

			sql.Format("update xkxt.dbo.course set professor_ID=\'%s\' where course_name=\'%s\'",m_dts_id,m_ListTts);
			db.ExecuteSQL(sql);

			sql.Format("update xkxt.dbo.course set selected=\'%s\' where course_name=\'%s\'","y",m_ListTts);
			db.ExecuteSQL(sql);
		}
		else
		{
			MessageBox("�㲢δѡ�˿�","��ʾ",MB_OK);
		}
	}

	cr.Close();

	//�������
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTTHS);
	pListC->ResetContent();

	//������ѡ�γ�
	sql.Format("select * from xkxt.dbo.course where selected=\'y\'");
	cr.Open(CRecordset::snapshot,sql);

	int iB=0;
	CString b[20];//��ѡ

	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}

	CString c;
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("professor_ID",c);
		if(c==m_dts_id)
		{
			cr.GetFieldValue("course_name",b[iB]);
			iB++;
		}
		cr.MoveNext();
	}

	for(int j=0;j<iB;j++)
	{
		pListC->AddString(b[j]);
	}

	UpdateData(FALSE);

	cr.Close();
	db.Close();
}
