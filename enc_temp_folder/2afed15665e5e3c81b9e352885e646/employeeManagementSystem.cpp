#include<iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	/*
	// ���Դ��룺
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
	*/

	
	WorkerManager wm;

	int choice = 0;
	
	while (true) {

		wm.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice) {
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ���ְ��
			wm.addEmp();
			break;
		case 2: // ��ʾְ��
			wm.showEmp();
			break;
		case 3: {// ɾ��ְ��
			/*int ret = wm.isExist(2);
			if (ret != -1) {
				cout << "ְ������ " << endl;
			}
			else {
				cout << "ְ��������" << endl;
			}*/
			cout << "ɾ��ְ��" << endl;
			wm.delEmp();
			break; 
		}
		case 4: // �޸�ְ��
			wm.modifyEmp();
			break;
		case 5: // ����ְ��
			wm.findEmp();
			break;
		case 6: // ���������
			wm.sortEmp();
			break;
		case 7: // ����ĵ�
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}

	}
	

	system("pause");

	return 0;
}