#pragma once
#include<iostream>
using namespace std;
#include<string>


class Identity
{
public:
	virtual void operMenu() = 0;
	//�û���
	string m_Name;

	//����
	string m_Pwd;
};