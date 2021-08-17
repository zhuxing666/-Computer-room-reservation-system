#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"identity.h"
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity
{
	
public:
	//构造函数
	Student();

	//有参构造   学号  姓名 密码
	Student(int id, string name, string pwd);


	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_Id;

	//机房信息容器
	vector<ComputerRoom> vCom;
};