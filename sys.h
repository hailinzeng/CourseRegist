#ifndef _sys_
#define _sys_

#include<string>
#include"Global.h"
using namespace std;

//学生
class Student
{
public:
	string ID;			//学号
	string name;		//姓名
	string birthdate;	//生日
	string status;		//状态(在学、休学)
	string grade;		//年级
};

//教师
class Professor
{
public:
	string ID;			//教师号
	string name;		//姓名
	string birthdate;	//生日
	string status;		//状态
	string department;	//部门
};

//管理员
class Admin
{
public:
	string ID;
};

//系统
class System
{
public:
	CString Time;
	char A_R[40];
};

static System	s;
#endif