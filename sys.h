#ifndef _sys_
#define _sys_

#include<string>
#include"Global.h"
using namespace std;

//ѧ��
class Student
{
public:
	string ID;			//ѧ��
	string name;		//����
	string birthdate;	//����
	string status;		//״̬(��ѧ����ѧ)
	string grade;		//�꼶
};

//��ʦ
class Professor
{
public:
	string ID;			//��ʦ��
	string name;		//����
	string birthdate;	//����
	string status;		//״̬
	string department;	//����
};

//����Ա
class Admin
{
public:
	string ID;
};

//ϵͳ
class System
{
public:
	CString Time;
	char A_R[40];
};

static System	s;
#endif