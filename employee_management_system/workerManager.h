#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include<fstream>
#define FILENAME "emp_file.txt"



class WorkerManager
{
public:

	// ���캯��
	WorkerManager();

	// չʾ����
	void showMenu();

	// �˳�ϵͳ
	void exitSystem();

	// ��¼ְ������
	int m_emp_num;

	// ְ�������ָ��
	Worker** m_emp_array;

	// ���ְ��
	void addEmp();

	// �����ļ�
	void save();

	// �ļ��Ƿ�Ϊ�ձ�־
	bool m_file_is_empty;

	// ͳ������
	int getEmpNum();

	// ��ʼ��Ա��
	void initEmp();

	// ��ʾְ��
	void showEmp();

	// ɾ��ְ��
	void delEmp();

	// �ж�ְ���Ƿ���ڣ������򷵻�ְ���������е�λ��
	int isExist(int id);

	// �޸�ְ��
	void modifyEmp();

	// ����ְ��
	void findEmp();

	// ���ձ������
	void sortEmp();

	// ����ļ�
	void cleanFile();

	// ��������
	~WorkerManager();

};

