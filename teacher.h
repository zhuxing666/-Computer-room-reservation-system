#pragma once
using namespace std;
#include"identity.h"
#include<string>
#include"orderFile.h"
#include<vector>

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ��캯��
	Teacher();

	//�вι���   ְ���� ����  ����
	Teacher(int empId, string name , string pwd);


	//�˵�

	void operMenu();

	//�鿴����ԤԼ
	void  showAllOrder();

    //���ԤԼ
	void validOrder();



	int m_EmpId;

};