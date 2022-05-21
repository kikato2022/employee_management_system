#include<iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	/*
	// 测试代码：
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
	*/

	
	WorkerManager wm;

	int choice = 0;
	
	while (true) {

		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1: // 添加职工
			wm.addEmp();
			break;
		case 2: // 显示职工
			wm.showEmp();
			break;
		case 3: {// 删除职工
			/*int ret = wm.isExist(2);
			if (ret != -1) {
				cout << "职工存在 " << endl;
			}
			else {
				cout << "职工不存在" << endl;
			}*/
			cout << "删除职工" << endl;
			wm.delEmp();
			break; 
		}
		case 4: // 修改职工
			wm.modifyEmp();
			break;
		case 5: // 查找职工
			wm.findEmp();
			break;
		case 6: // 按编号排序
			wm.sortEmp();
			break;
		case 7: // 清空文档
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