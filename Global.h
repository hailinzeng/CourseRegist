#include<string>
#include <afxdb.h>
using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

//�˲������ڿ�����ʾ
static	int DrawMode;

const	int ModeULogin=0;
const	int ModeLogin =1;
const   int ModeFLogin=2;

static CString		sql;	//SQL���
static CDatabase	db;
static CRecordset	cr(&db);

static char HostName[30]="DELLPC\\SQLEXPRESS";//������
static char HostUID [20]="sa";
static char HostPSW [20]="sa";

//�û����������Ȩ�޵ȼ�
static string	m_ID;
static string	m_password;

//�޸�����
static string	m_npassword;

#endif