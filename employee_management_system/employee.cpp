#include "employee.h"



Employee::Employee(int id, string name, int dept_id) {
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

// 显示个人信息
void Employee::showInfo() {

	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;

}

// 获取岗位名称
string Employee::getDeptName() {
	return string("普通员工");
}


