#pragma once
#include "worker.h"

//��ͨԱ��
class Employee: public Worker{
public:

	Employee(int id, string name, int dept_id);

	// ��ʾ������Ϣ
	virtual void showInfo();

	// ��ȡ��λ����
	virtual string getDeptName();
};

