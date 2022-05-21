&emsp;

# 1、管理系统需求

职工管理系统可以用来管理公司内所有员工的信息

利用 C++ 来实现一个基于多态的职工管理系统

公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位以及职责

普通员工职责：完成经理交给的任务
经理职责：完成老板交给的任务，并下发任务给员工
老板职责：管理公司所有事务

管理系统中需要实现的功能如下：

- 退出管理程序：退出当前管理系统
- 增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号
- 显示职工信息：显示公司内部所有职工的信息
- 删除离职职工：按照编号删除指定的职工
- 修改职工信息：按照编号修改职工个人信息
- 查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
- 按照编号排序：按照职工编号，进行排序，排序规则由用户指定
- 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）

系统界面效果图如下：
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/5a91adc320834c8cb6ff89b3b2427b4c.png)
# 2、创建项目
 
 创建项目步骤如下：
 - 创建新项目
 - 添加文件
 
 ## 2.1 创建项目
 
 打开vs2019后，点击创建新项目，创建新的C++项目


# 3、创建管理类
 
 管理类负责的内容如下
 - 与用户的沟通菜单界面
 - 对职工增删改查的操作
 - 对文件的读写交互
 
## 3.1 创建文件

## 3.2 头文件实现

## 3.3 源文件实现
在workerManager.cpp中将构造和析构函数空实现补全

# 4、菜单功能
功能描述：与用户的沟通界面

## 4.1 添加成员函数
在管理类workerManager.h中添加成员函数 `void showMenu();`


## 4.2  验证成员函数的功能

# 5、退出功能
## 5.1 提供功能接口
```cpp
class WorkerManager
{
public:


	// 退出系统
	void exitSystem();


};
```

## 5.2 实现退出功能

```cpp
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

```

## 5.3 测试

```cpp
#include<iostream>
using namespace std;
#include "workerManager.h"


int main() {

	WorkerManager wm;

	int choice = 0;
	while (true) {

		wm.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			wm.exitSystem();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			system("cls");
			break;
		}

	}

	system("pause");

	return 0;
}
```

# 6、创建职工类
## 6.1 创建职工抽象类
职工的分类为：普通员工、经理、老板

将三种职工抽象到一个类（worker）中，利用多态管理不同职工种类

职工的属性为：职工编号、职工姓名、职工所在部门编号

职工的行为为：岗位职责信息描述、获取岗位名称

头文件文件夹下 创建文件 worker.h 文件并且添加如下代码：

```cpp
#pragma once
#include<iostream>
using namespace std;
#include<string>



//职工抽象类
class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;

	//职工编号
	int m_id;

	//职工姓名
	string m_name;

	//部门编号
	int m_dept_id;
};


```

## 6.2 创建普通员工类
普通员工**继承**职工抽象类，并重写父类中纯虚函数
在头文件和源文件的文件夹下分别创建 employee.h 和 employee.cpp文件

employee.h中代码如下：

```cpp
#pragma once
#include "worker.h"

//普通员工
class Employee: public Worker{
public:

	Employee(int id, string name, int dept_id);

	// 显示个人信息
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDeptName();
};

```

```cpp
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

```

## 6.3 创建经理类

```cpp
#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include<string>



class Manager: public Worker{
public:

	// 构造函数
	Manager(int id, string name, int dept_id);

	// 显示个人信息
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDeptName();

};


```

```cpp
#include "manager.h"



// 构造函数
Manager::Manager(int id, string name, int dept_id) {
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

// 显示个人信息
void Manager::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给普通员工" << endl;

}

// 获取岗位名称
string Manager::getDeptName() {

	return string("经理");
}
```


## 6.4 创建老板类

```cpp
#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include<string>



class Boss : public Worker {
public:

	// 构造函数
	Boss(int id, string name, int dept_id);

	// 显示个人信息
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDeptName();

};



```


```cpp
#include "boss.h"



// 构造函数
Boss::Boss(int id, string name, int dept_id) {
	this->m_id = id;
	this->m_name = name;
	this->m_dept_id = dept_id;
}

// 显示个人信息
void Boss::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责：给员工安排任务" << endl;

}

// 获取岗位名称
string Boss::getDeptName() {

	return string("老板");
}

```

## 6.5 测试多态

```cpp
int main() {

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


	system("pause");

	return 0;
}
```
&emsp;
&emsp;
# 7、添加职工
功能描述：批量添加职工，并且保存到文件中

## 7.1 功能分析
分析：

用户在批量创建时，可能会创建不同种类的职工

如果想将所有不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里

如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用Worker ** 的指针维护
![在这里插入图片描述](https://img-blog.csdnimg.cn/4e81a97b1ce94402bce06a789d245b55.png)
`Worker ** = new Worker*[5];`


## 7.2 功能实现
在 `workerManager.h`头文件中添加成员属性代码：
```cpp
#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


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

	// 析构函数
	~WorkerManager();

};


```
在`workerManager.cpp` 文件中添加具体实现：

```cpp
#include "workerManager.h"


WorkerManager::WorkerManager() {
	// 初始化属性
	this->m_emp_num = 0;
	this->m_emp_array = NULL;
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

		// 成功添加后保存到文件中
		
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


WorkerManager::~WorkerManager() {

}

```


## 7.3 功能测试

```cpp
...
		case 1:
			wm.addEmp();
			break;
...
```

# 8、文件交互 - 写文件
功能描述：对文件进行读写

在上一个添加功能中，我们只是将所有的数据添加到了内存中，一旦程序结束就无法保存了

因此文件管理类中需要一个与文件进行交互的功能，对于文件进行读写操作

## 8.1 设定文件路径
首先我们将文件路径，在`workerManage.h`中添加宏常量，并且包含头文件 `fstream`

```cpp
#include <fstream>
#define FILENAME *emp_file.txt"
```

## 8.2 成员函数声明
在`workerManager.h` 中类里添加成员函数 `void save()`

```cpp
// 保存文件
void save();
```

## 8.3 保存文件功能实现
```cpp
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

```

## 8.4 保存文件功能测试
在添加职工功能中添加成功后添加保存文件函数

```cpp
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

```

# 9、文件交互 - 读文件
功能描述：将文件中的内容读取到程序中

虽然我们实现了添加职工后保存到文件的操作，但是每次开始运行程序，并没有将文件中数据读取到程序中

而我们的程序功能中还有清空文件的需求

因此构造函数初始化数据的情况分为三种

1. 第一次使用，文件来创建
2. 文件存在，但是数据被用户清空
3. 文件存在，并且保存职工的所有数据

## 9.1 文件未创建
在`workerManager.h`中添加新的成员属性`m_file_is_empty`标志文件是否为空
```cpp
// 标志文件是否为空
bool m_file_is_empty;
```
修改`workerManager.cpp` 中构造函数代码
```cpp
WorkerManager::WorkerManager(){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	// 文件不存在情况
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;

		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->m_file_is_empty = true;
		ifs.close();
		return;
	}
}
```
## 9.2 文件存在且数据为空
在 workerManager.cpp 中的构造函数中追加代码;



## 9.3 文件存在且保存职工数据
### 9.3.1 获取记录的职工人数
在`workerManager.h` 中添加成员函数 `int getEmpNum();`
```cpp
 //统计人数
 int getEmpNum();
```

workerManager.cpp 中实现

```cpp
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

```
构造函数中添加下面代码作为测试：
```cpp
	// 3、文件存在，且数据不为空
	int num = this->getEmpNum();
	cout << "职工的人数为" << num << endl;
	this->m_emp_num = num;
```

### 9.3.2 初始化数组
根据职工的数据以及职工数量，初始化`workerManager`中的`Worker ** m_emp_array` 指针

在WorkerManager.h 中添加成员函数 `void intiEmp();`
```cpp
	// 初始化员工
	void initEmp();
```

在`WorkerManager.cpp` 中实现

```cpp
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

```



# 10、显示职工
功能描述：显示当前所有职工信息

## 10.1 显示职工函数声明
在 `workerManager.h `中添加成员函数 `void showEmp();`
```cpp
 // 显示职工
 void showEmp();
```
## 10.2 显示职工函数实现
在 workerManager.cpp 中实现成员函数 `void showEmp();`
```cpp
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
```
## 10.3 测试显示职工
```cpp
case 2: // 显示职工
			wm.showEmp();
			break;
```

&emsp;
&emsp;
# 11、删除职工
功能描述：按照职工的编号进行删除职工操作

## 11.1 删除职工函数声明
在 `workerManager.h` 中添加成员函数 `void delEmp();`

```cpp
// 删除职工
void delEmp();
```

## 11.2 职工是否存在函数声明
很多功能都需要用到根据职工是否存在来进行操作如：删除职工、修改职工、查找职工
因此添加该公告函数，以便后续调用
在 `workerManager.h` 中添加成员函数 `int isExist(int id);`
```cpp
// 按照职工编号判断职工是否存在，若存在返回职工在数组中位置，不存在返回-1
int isExist(int id);
```

## 11.3 职工是否存在函数实现

```cpp
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
```

## 11.4 删除职工函数实现

```cpp
// 删除职工
void WorkerManager::delEmp(int id) {
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
```
## 11.5 测试删除职工
```cpp
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
```

&emsp;
&emsp;
# 12、修改职工
功能描述：能够按照职工的编号对职工信息进行修改并保存

## 12.1 修改职工函数声明

```cpp
	// 修改职工
	void modifyEmp();
```

## 12.2 修改职工函数实现

```cpp
/ 修改职工
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

```

## 12.3 测试修改职工

```cpp
case 4: // 修改职工
			wm.modifyEmp();
			break;
```


# 13、查找职工
功能描述：提供两种查找职工方式，一种按照职工编号，一种按照职工姓名

## 13.1 查找职工函数声明
在`workerManager.h`中添加成员函数 `void fineEmp();`
```cpp
// 查找职工
void findEmp();
```
## 13.2 查找职工函数实现
在`workerManager.cpp` 中实现成员函数 `void fineEmp();`

```cpp
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

```
## 13.3 测试查找职工

```cpp
case 5: // 查找职工
			wm.findEmp();
			break;
```
# 14、排序
功能描述：按照职工编号进行排序，排序的顺序由用户指定
## 14.1 排序函数声明
在 `workerManager.h` 中添加成员函数 `void sortEmp();`
```cpp
 // 排序职工
 void sortEmp();
```
## 14.2 排序函数实现
在workerManager.cpp中实现成员函数 `void sortEmp();`

```cpp
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

```


## 14.3 测试排序功能
```cpp
case 6: // 按编号排序
			wm.sortEmp();
			break;
```
# 15、清空文件
功能描述：将文件中记录数据清空
## 15.1 清空函数声明
在`workerManager.h` 中添加成员函数 `void cleanFile();`
```cpp
// 清空文件
	void cleanFile();
```
## 15.2 清空函数实现
在`workerManager.cpp`中实现成员函数 `void cleanFile();`

```cpp
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

```
## 15.3 测试清空文件
```cpp
case 7: // 清空文档
			wm.cleanFile();
			break;
```

