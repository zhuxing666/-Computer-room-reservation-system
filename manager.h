#pragma once
using namespace std;
#include"identity.h"
#include<string>
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerRoom.h"

class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单界面
	void operMenu();

	//添加账号
	void addPerson();

	//查看账号

	void showPerson();

	//查看机房信息
	void showComputer();
    
	//清空预约记录
	void cleanFile();

	//初始化容器
	void initVector();

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;

	//去重操作
	bool checkRepeat(int id, int type);


	//机房容器
	vector<ComputerRoom>vCom;


};