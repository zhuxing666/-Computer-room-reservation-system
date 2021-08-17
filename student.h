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
	//���캯��
	Student();

	//�вι���   ѧ��  ���� ����
	Student(int id, string name, string pwd);


	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;

	//������Ϣ����
	vector<ComputerRoom> vCom;
};