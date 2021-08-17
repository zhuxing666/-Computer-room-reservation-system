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
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�

	void showPerson();

	//�鿴������Ϣ
	void showComputer();
    
	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//ȥ�ز���
	bool checkRepeat(int id, int type);


	//��������
	vector<ComputerRoom>vCom;


};