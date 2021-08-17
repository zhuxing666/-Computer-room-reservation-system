#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"


//�����ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		//�����Ӳ˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;

		cin >> select;

		if (select == 1) //�鿴���е�ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2) //���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			//ע����¼
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ���Ӳ˵�����
void studentMenu(Identity* & student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();
		
		Student* stu = (Student*)student; //����ָ��תΪ����


		int select = 0;
		cin >> select; 

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if(select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) // ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			//ע����¼
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;

		}
	}
}

//�������Ա�Ӳ˵�  ����ָ��
void managerMenu(Identity*& manager)
{
	while (true)

	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ�� תΪ����ָ�룬 ���������������ӿ�

		Manager* man = (Manager*)manager;

		int select = 0;
		//����ѡ��
		cin >> select;

		if (select == 1) // ����˺�
		{
			cout << "------����˺�-------" << endl;
			man->addPerson();
		}
		else if (select == 2) // �鿴�˺�
		{
			cout << "------�鿴�˺�-------" << endl;
			man->showPerson();
		}
		else if (select == 3)  //�鿴����
		{
			cout << "------�鿴����-------" << endl;
			man->showComputer();
		}
		else if (select == 4) // ���ԤԼ
		{
		
			man->cleanFile();

		}
		else
		{
			delete manager;  // ���ٵ���������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		

		}
	}


}


//�˳�����
void ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
 }
//��¼�Ĺ���

void LoginIn(string fileName, int type)
{
	Identity* person = NULL;


	//���ļ�

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�����û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1) //ѧ�����
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if(type == 2)
	{
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}
	
	cout << "�������û�������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ�������֤
		int fId;  // ���ļ��л��Id��
		string fName;  //���ļ��л�ȡ������
		string fPwd;  //���ļ��л�ȡ������

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//���û���Ϣ�������Ϣ�Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
			
				//����ѧ���Ӳ˵�

				studentMenu(person);

				return;

			}
 		}
	
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//�����ʦ�Ӳ˵�
				teacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա�����֤
		string fName; // ���ļ��л�ȡ����
		string fPwd; // ���ļ��л�ȡ����

		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);

				//�������Ա�Ӳ˵�

				managerMenu(person);
				return;
			}
		}


	}
	cout << "��֤��½ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return ;
	

	


}

int main()
{

	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ��������������ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "���������ѡ��";
		cin >> select;

		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:        //��ʦ
			LoginIn(TEACHER_FILE, 2);
			break; 
		case 3:        //����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:       //�˳�
			ExitSystem();
			break;

		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}