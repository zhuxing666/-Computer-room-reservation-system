#pragma once
#include<iostream>
using namespace std;
#include<string>


class Identity
{
public:
	virtual void operMenu() = 0;
	//ÓÃ»§Ãû
	string m_Name;

	//ÃÜÂë
	string m_Pwd;
};