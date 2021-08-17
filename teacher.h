#pragma once
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher :public Identity
{
public:
	//默认构造函数
	Teacher();

	//有参构造   职工号 名字  密码
	Teacher(int empId, string name , string pwd);


	//菜单

	void operMenu();

	//查看所有预约
	void  showAllOrder();

    //审核预约
	void validOrder();



	int m_EmpId;

};