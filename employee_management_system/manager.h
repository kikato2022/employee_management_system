#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include<string>



class Manager: public Worker{
public:

	// ���캯��
	Manager(int id, string name, int dept_id);

	// ��ʾ������Ϣ
	virtual void showInfo();

	// ��ȡ��λ����
	virtual string getDeptName();

};
