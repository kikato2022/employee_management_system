#include "employee.h"



Employee::Employee(int id, string name, int dept_id) {
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

// ��ʾ������Ϣ
void Employee::showInfo() {

	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;

}

// ��ȡ��λ����
string Employee::getDeptName() {
	return string("��ͨԱ��");
}


