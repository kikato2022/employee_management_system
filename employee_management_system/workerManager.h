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

	// 构造函数
	WorkerManager();

	// 展示函数
	void showMenu();

	// 退出系统
	void exitSystem();

	// 记录职工人数
	int m_emp_num;

	// 职工数组的指针
	Worker** m_emp_array;

	// 添加职工
	void addEmp();

	// 保存文件
	void save();

	// 文件是否为空标志
	bool m_file_is_empty;

	// 统计人数
	int getEmpNum();

	// 初始化员工
	void initEmp();

	// 显示职工
	void showEmp();

	// 删除职工
	void delEmp();

	// 判断职工是否存在，存在则返回职工在数组中的位置
	int isExist(int id);

	// 修改职工
	void modifyEmp();

	// 查找职工
	void findEmp();

	// 按照编号排序
	void sortEmp();

	// 清空文件
	void cleanFile();

	// 析构函数
	~WorkerManager();

};

