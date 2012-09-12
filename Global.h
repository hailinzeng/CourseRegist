#include<string>
#include <afxdb.h>
using namespace std;

#ifndef GLOBAL_H
#define GLOBAL_H

//此部分用于控制显示
static	int DrawMode;

const	int ModeULogin=0;
const	int ModeLogin =1;
const   int ModeFLogin=2;

static CString		sql;	//SQL语句
static CDatabase	db;
static CRecordset	cr(&db);

static char HostName[30]="DELLPC\\SQLEXPRESS";//服务器
static char HostUID [20]="sa";
static char HostPSW [20]="sa";

//用户名和密码和权限等级
static string	m_ID;
static string	m_password;

//修改密码
static string	m_npassword;

#endif