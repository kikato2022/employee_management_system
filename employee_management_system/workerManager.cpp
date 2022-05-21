#include "workerManager.h"


WorkerManager::WorkerManager() {
	// 初始化属性

	// 1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 读文件

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;

		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->m_file_is_empty = true;
		ifs.close();
		return;
	}
	// 2、文件存在，但是数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// 文件为空
		cout << "文件为空" << endl;
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->m_file_is_empty = true;
		ifs.close();
		return;
	}
	// 3、文件存在，且数据不为空
	int num = this->getEmpNum();
	cout << "职工的人数为" << num << endl;
	this->m_emp_num = num;

	//开辟空间
	this->m_emp_array = new Worker * [this->m_emp_num];
	//将文件中的数据存到数组中
	this->initEmp();
	
	// 测试代码
	/*
	for (int i = 0; i < this->m_emp_num; i++) {
		cout << "职工编号：" << this->m_emp_array[i]->m_id
			<< " 姓名：" << this->m_emp_array[i]->m_name
			<< " 部门编号：" << this->m_emp_array[i]->m_dept_id << endl;
	}
	*/
}

void WorkerManager::showMenu() {

	cout << "**************************************" << endl;
	cout << "********欢迎使用职工管理系统！********" << endl;
	cout << "********* 0、退出管理程序 ************" << endl;
	cout << "********* 1、增加职工信息 ************" << endl;
	cout << "********* 2、显示职工信息 ************" << endl;
	cout << "********* 3、删除离职职工 ************" << endl;
	cout << "********* 4、修改职工信息 ************" << endl;
	cout << "********* 5、查找职工信息 ************" << endl;
	cout << "********* 6、按照编号排序 ************" << endl;
	cout << "********* 7、清空所有文档 ************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

// 添加职工
void WorkerManager::addEmp() {
	cout << "请输入添加职工的数量： " << endl;

	int add_num = 0; // 保存用户的输入数量
	cin >> add_num;

	if (add_num > 0) {
		// 添加
		// 计算添加新空间的大小
		int new_size = this->m_emp_num + add_num; //新的人数 = 原来记录人数 + 新增人数

		// 开辟新空间
		Worker ** new_space = new Worker* [new_size];

		// 将原来空间下的数据，拷贝到新空间下
		if (this->m_emp_array != NULL) {
			for (int i = 0; i < this->m_emp_num; i++) {
				new_space[i] = this->m_emp_array[i];
			}
		}
		// 批量添加新数据
		for (int i = 0; i < add_num; i++) {
			int id;	// 职工编号
			string name; // 职工姓名
			int dept_id; // 部门编号

			cout << "请输入第 " << i + 1 << " 个新职工编号： " << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名： " << endl;
			cin >> name;

			cout << "请选择该职工岗位： " << endl;
			cout << "1 -- 普通职工" << endl;
			cout << "2 -- 经理" << endl;
			cout << "3 -- 老板" << endl;

			cin >> dept_id;

			Worker* worker = NULL;
			switch (dept_id) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			// 将创建职工指针，保存到数组中
			new_space[this->m_emp_num + i] = worker;
			
		}

		// 释放原有的空间
		delete[] this->m_emp_array;

		// 更改新空间的指向
		this->m_emp_array = new_space;

		// 更新新的职工人数
		this->m_emp_num = new_size;

		// 更新职工为空标志
		this->m_file_is_empty = false;

		// 成功添加后保存到文件中
		this->save();
		
		// 添加成功
		cout << "成功添加" << add_num << " 名新职工" << endl;
	}
	else {
		cout << "输入数据有误" << endl;
	}
	// 按任意键后回到上级目录
	system("pause");
	system("cls");
}

// 保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出方式打开文件 -- 写文件

	// 将每个人数据写入到文件中
	for (int i = 0; i < this->m_emp_num; i++) {
		ofs << this->m_emp_array[i]->m_id << " "
			<< this->m_emp_array[i]->m_name << " "
			<< this->m_emp_array[i]->m_dept_id << endl;
	}

	// 关闭文件
	ofs.close();
}

// 统计人数
int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // 打开文件 读文件模式

	int id = 0 ;
	string name;
	int dept_id;

	// 统计人数的变量
	int num = 0;

	while (ifs >> id && ifs >> name && ifs>> dept_id) {
		num++;
	}

	return num;
}

// 初始化员工
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dept_id) {
		Worker* worker = NULL;
		if (dept_id == 1) { // 普通员工
			worker = new Employee(id,name,dept_id);
		}
		else if (dept_id == 2) {
			worker = new Manager(id, name, dept_id);

		}
		else {
			worker = new Boss(id, name, dept_id);
		}

		this->m_emp_array[index++] = worker;
	}
	ifs.close();
}

// 显示职工
void WorkerManager::showEmp() {

	// 判断文件是否为空
	if (this->m_file_is_empty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < this->m_emp_num; i++) {
			// 利用多态调用程序接口
			this->m_emp_array[i]->showInfo();
		}
	}

	// 按任意键后清屏
	system("pause");
	system("cls");

}

// 删除职工
void WorkerManager::delEmp() {
	if (this->m_file_is_empty) {
		cout << "文件不存在或记录为空!" << endl;
	}
	else {
		// 按照职工编号删除
		cout << "请输入想要职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1) { // 职工存在且要删除调要删除数组编号为index的职工
			// 数据前移
			for (int i = index; i < this->m_emp_num - 1; i++) {
				this->m_emp_array[i] = this->m_emp_array[i + 1];
			}

			this->m_emp_num--; // 更新数组中记录的人员个数

			// 同步更新到文件中
			this->save();

			cout << "删除成功!" << endl;
		}
		else {
			cout << "删除失败，未找到该职工!" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 修改职工
void WorkerManager::modifyEmp() {
	if (this->m_file_is_empty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的职工的编号 " << endl;
		int id;
		cin >> id;

		int index = isExist(id);
		if (index != -1){ // 查找到编号为id的职工
			delete this->m_emp_array[index];
			int new_id = 0;
			string new_name = "";
			int new_dept_id = 0;

			cout << "查到：" << id << " 号职工，请输入新职工号：" << endl;
			cin >> new_id;

			cout << "请输入新姓名：" << endl;
			cin >> new_name;

			cout << "请输入新的岗位" << endl;
			cout << "1 -- 普通职工" << endl;
			cout << "2 -- 经理" << endl;
			cout << "3 -- 老板" << endl;

			cin >> new_dept_id;

			Worker* worker = NULL;

			switch (new_dept_id) {
				case 1: {
					worker = new Employee(new_id, new_name, new_dept_id);
					break;
				}
				case 2: {
					worker = new Manager(new_id, new_name, new_dept_id);

					break; 
				}
				case 3: {
					worker = new Boss(new_id, new_name, new_dept_id);

					break;
				}
				default: {
					cout << "输入有误!" << endl;

					break;
				}				
			}
			
			// 更新数据到数组中
			this->m_emp_array[index] = worker;


			//保存到文件中
			this->save();
			cout << "修改成功! " << endl;

		}
		else {
			cout << "修改失败，查无此人!" << endl;
		}
	}

	// 按任意键清屏
	system("pause");
	system("cls");
}

// 判断职工是否存在，存在则返回职工在数组中的位置
int WorkerManager::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_emp_num; i++) {

		if (id == this->m_emp_array[i]->m_id) { //找到职工

			index = i;

			break;
		}
	}

	return index;
}

// 查找职工
void WorkerManager::findEmp() {
	if (this->m_file_is_empty) {
		cout << "文件不存在或者记录为空！" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1、按照职工的编号查找：" << endl;
		cout << "2、按照职工的姓名查找：" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) { //按照编号查
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int index = isExist(id);
			if (index != -1) {
				//找到职工
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_emp_array[index]->showInfo();
			}
			else {
				cout << "查找失败，查无此人" << endl;
			}

		}
		else if(select == 2) { //按照姓名查
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			// 加入判断是否查到的标志
			bool flag = false; // 默认未找到职工

			for (int i = 0; i < this->m_emp_num; i++) {
				if (this->m_emp_array[i]->m_name == name) {
					cout << "查找成功，职工编号为："
						<< this->m_emp_array[i]->m_id
						<< " 号职工信息如下：" << endl;
					flag = true;

					// 调用显示信息接口
					this->m_emp_array[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else {
			cout << "输入有误!" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

// 按照编号排序
void WorkerManager::sortEmp() {
	if (this->m_file_is_empty) {
		cout << "文件不存在或记录为空!" << endl;

		// 按任意键清屏
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序的方式：" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_emp_num; i++) {
			int min_or_max = i; //声明最小值或者最大值的下标
			for (int j = i + 1; j < this->m_emp_num; j++) {
				if (select == 1) {// 升序
					if (this->m_emp_array[min_or_max]->m_id >
						this->m_emp_array[j]->m_id) {
						min_or_max = j;
					}
				}
				else { // 降序
					if (this->m_emp_array[min_or_max]->m_id <
						this->m_emp_array[j]->m_id) {
						min_or_max = j;
					}
				}
			}
			// 判断一开始认定 最小值或最大值，是不是计算的最小值或者最大值
			if (i != min_or_max) {
				Worker* temp = this->m_emp_array[i];
				this->m_emp_array[i] = this->m_emp_array[min_or_max];
				this->m_emp_array[min_or_max] = temp;
			}
		}

		cout << "排序成功！排序后的结果为：" << endl;
		this->save(); // 排序后结果保存到文件中
		this->showEmp(); // 展示所有职工
	}
}

// 清空文件
void WorkerManager::cleanFile() {
	cout << "确认清空? " << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select;
	cin >> select;
	if (select == 1) {

	}

	if (select == 1) {
		// 清空文件
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重建
		ofs.close();

		if (this->m_emp_array != NULL) {
			// 删除堆区的每个职工对象
			for (int i = 0; i < this->m_emp_num; i++) {
				delete this->m_emp_array[i];
				this->m_emp_array[i] = NULL;
			}

			// 删除堆区数组指针
			delete[] this->m_emp_array;
			this->m_emp_array = NULL;
			this->m_emp_num = 0;
			this->m_file_is_empty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

// 析构函数
WorkerManager::~WorkerManager() {

	if (this->m_emp_array != NULL) {

		for (int i = 0; i < this->m_emp_num; i++) {
			if (this->m_emp_array[i] != NULL) {
				delete this->m_emp_array[i];
			}
		}

		delete[] this->m_emp_array;
		this->m_emp_array = NULL;
	}

}


