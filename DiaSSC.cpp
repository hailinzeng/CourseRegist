// DiaSSC.cpp : implementation file
//

#include "stdafx.h"
#include "Course_Regist.h"
#include "DiaSSC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiaSSC dialog


DiaSSC::DiaSSC(CWnd* pParent /*=NULL*/)
	: CDialog(DiaSSC::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiaSSC)
	//obligatory=4;//����
	//optional=2;//ѡ��
	m_ListSts = _T("");
	//}}AFX_DATA_INIT
}


void DiaSSC::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiaSSC)
	DDX_LBString(pDX, IDC_LISTSTS, m_ListSts);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiaSSC, CDialog)
	//{{AFX_MSG_MAP(DiaSSC)
	ON_BN_CLICKED(IDC_SSeekCIF, OnSSeekCIF)
	ON_BN_CLICKED(IDC_SEXCUTE, OnSexcute)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DiaSSC message handlers

//ִ��
void DiaSSC::OnSexcuteX(CString m_dts_id)
{
	//�������ݿ�
	sql.Format("DRIVER={SQL Server};Server=%s;DATABASE=xkxt;UID=%s;PWD=%s;",HostName,HostUID,HostPSW);
	db.OpenEx(sql);
	
	//����
	//MessageBox(m_dts_id,"OnSexcuteX",MB_OK);
	//MessageBox(m_ListSts,"OnSexcuteX",MB_OK);

	CListBox* pListB=(CListBox*)GetDlgItem(IDC_LISTSHS);
	
	//�ж��Ƿ���ѡ
	bool selected=false;
	
	//�ÿγ�����ѯ���ݿ�

	//��ѯ�γ�ID
	sql.Format("select * from xkxt.dbo.course where course_name=\'%s\'",m_ListSts);
	cr.Open(CRecordset::snapshot,sql);

	CString cid,ctype;
	cr.GetFieldValue("course_ID",cid);

	cr.GetFieldValue("course_type",ctype);

	CString scn;
	//��numת�������Ȼ���10�Ƚ�	
	cr.GetFieldValue("stu_number",scn);
	int snum=atoi(scn);

	cr.Close();

	//��ѯѧ��ID
	sql.Format("select * from xkxt.dbo.score where course_ID=\'%s\'",cid);
	cr.Open(CRecordset::snapshot,sql);

	int iA=0,j=0;
	CString a[20];//��ѡ

	//����
	if(!cr.IsBOF())
	{
		cr.MoveFirst();
	}
	while(!cr.IsEOF())
	{
		cr.GetFieldValue("student_ID",a[iA]);
		iA++;
		cr.MoveNext();
	}

	for(j=0;j<iA;j++)
	{
		if (a[j]==m_dts_id)
		{
			selected=true;//�Ƿ���ѡ�˿�
			break;
		}
	}

	cr.Close();

	/*char* aaa;
	aaa=selected?"��ѡ":"δѡ";
	MessageBox(aaa,"?",MB_OK);*/
	
	if(selected)//��ѡ
	{
		if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
		{
			MessageBox("����ѡ","��ʾ",MB_OK);
		}
		else
		{
			//MessageBox("��ѡ","��ʾ",MB_OK);
			
			if(ctype=="ѡ�޿�")
			{
				optional++;
			}
			else
			{
				obligatory++;
			}

			snum=snum-1;
			scn.Format("%d",snum);
			sql.Format("update xkxt.dbo.course set stu_number=\'%s\' where course_ID=\'%s\'",scn,cid);
			db.ExecuteSQL(sql);
				
			//��ѡ
			sql.Format("delete from xkxt.dbo.score where course_ID=\'%s\' and student_ID=\'%s\'",cid,m_dts_id);
			db.ExecuteSQL(sql);

		//	sql.Format("update xkxt.dbo.course set stu_num=\'%s\' where course_ID=\'%s\'",num,cid);
		//	db.ExecuteSQL(sql);
		}
		
	}
	else//δѡ
	{
		if(((CButton *)GetDlgItem(IDC_RADIO3))->GetCheck())
		{
			//ѡ��
			//MessageBox("ѡ��","��ʾ",MB_OK);

			if(snum<10)
			{
				if(ctype=="ѡ�޿�")
				{
					if(optional==0)
					{
						MessageBox("����ѡ��2��ѡ�޿�","��ʾ",MB_OK);
					}
					else
					{
						optional--;
						sql.Format("insert into xkxt.dbo.score (course_ID,student_ID)values (\'%s\',\'%s\')",cid,m_dts_id);
						db.ExecuteSQL(sql);

						snum=snum+1;
						scn.Format("%d",snum);
						sql.Format("update xkxt.dbo.course set stu_number=\'%s\' where course_ID=\'%s\'",scn,cid);
						db.ExecuteSQL(sql);
					}
				}
				else
				{
					if(obligatory==0)
					{
						MessageBox("����ѡ��4�ű��޿�","��ʾ",MB_OK);
					}
					else
					{
						obligatory--;
						sql.Format("insert into xkxt.dbo.score (course_ID,student_ID)values (\'%s\',\'%s\')",cid,m_dts_id);
						db.ExecuteSQL(sql);

						snum=snum+1;
						scn.Format("%d",snum);
						sql.Format("update xkxt.dbo.course set stu_number=\'%s\' where course_ID=\'%s\'",scn,cid);
						db.ExecuteSQL(sql);
					}
				}
			}
			else
			{
				MessageBox("��������","��ʾ",MB_OK);
			}
		}
		else
		{
			MessageBox("�㲢δѡ�˿�","��ʾ",MB_OK);
		}
	}
	
	cr.Close();
	
	//�������
	CListBox* pListC=(CListBox*)GetDlgItem(IDC_LISTSHS);
	pListC->ResetContent();
	
	//������ѡ�γ�
	sql.Format("select * from xkxt.dbo.score where student_ID=\'%s\'",m_dts_id);
	cr.Open(CRecordset::snapshot,sql);
	
	int iB=0;
	CString b[20];//��ѡ�γ�ID

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
	

	CString cname;

	for(j=0;j<iB;j++)
	{
		sql.Format("select * from xkxt.dbo.course where course_ID=\'%s\'",b[j]);
		cr.Open(CRecordset::snapshot,sql);

		cr.GetFieldValue("course_name",cname);

		pListC->AddString(cname);

		cr.Close();
	}

	//////!!!!!!!!!!!!!!
	CString o;
	char*cs;

	o.Format("%d",obligatory);
	cs= (LPSTR)(LPCTSTR)o;
	SendDlgItemMessage(IDC_StuSLB,WM_SETTEXT,0,(LPARAM)cs);

	o.Format("%d",optional);
	cs= (LPSTR)(LPCTSTR)o;
	SendDlgItemMessage(IDC_StuSLX,WM_SETTEXT,0,(LPARAM)cs);
	
	UpdateData(FALSE);
	
	db.Close();

}
