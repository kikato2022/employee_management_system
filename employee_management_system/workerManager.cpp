#include "workerManager.h"


WorkerManager::WorkerManager() {
	// ��ʼ������

	// 1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ�

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;

		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->m_file_is_empty = true;
		ifs.close();
		return;
	}
	// 2���ļ����ڣ���������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		// �ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_emp_num = 0;
		this->m_emp_array = NULL;
		this->m_file_is_empty = true;
		ifs.close();
		return;
	}
	// 3���ļ����ڣ������ݲ�Ϊ��
	int num = this->getEmpNum();
	cout << "ְ��������Ϊ" << num << endl;
	this->m_emp_num = num;

	//���ٿռ�
	this->m_emp_array = new Worker * [this->m_emp_num];
	//���ļ��е����ݴ浽������
	this->initEmp();
	
	// ���Դ���
	/*
	for (int i = 0; i < this->m_emp_num; i++) {
		cout << "ְ����ţ�" << this->m_emp_array[i]->m_id
			<< " ������" << this->m_emp_array[i]->m_name
			<< " ���ű�ţ�" << this->m_emp_array[i]->m_dept_id << endl;
	}
	*/
}

void WorkerManager::showMenu() {

	cout << "**************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ��********" << endl;
	cout << "********* 0���˳�������� ************" << endl;
	cout << "********* 1������ְ����Ϣ ************" << endl;
	cout << "********* 2����ʾְ����Ϣ ************" << endl;
	cout << "********* 3��ɾ����ְְ�� ************" << endl;
	cout << "********* 4���޸�ְ����Ϣ ************" << endl;
	cout << "********* 5������ְ����Ϣ ************" << endl;
	cout << "********* 6�����ձ������ ************" << endl;
	cout << "********* 7����������ĵ� ************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

// ���ְ��
void WorkerManager::addEmp() {
	cout << "���������ְ���������� " << endl;

	int add_num = 0; // �����û�����������
	cin >> add_num;

	if (add_num > 0) {
		// ���
		// ��������¿ռ�Ĵ�С
		int new_size = this->m_emp_num + add_num; //�µ����� = ԭ����¼���� + ��������

		// �����¿ռ�
		Worker ** new_space = new Worker* [new_size];

		// ��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_emp_array != NULL) {
			for (int i = 0; i < this->m_emp_num; i++) {
				new_space[i] = this->m_emp_array[i];
			}
		}
		// �������������
		for (int i = 0; i < add_num; i++) {
			int id;	// ְ�����
			string name; // ְ������
			int dept_id; // ���ű��

			cout << "������� " << i + 1 << " ����ְ����ţ� " << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����ְ�������� " << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ�� " << endl;
			cout << "1 -- ��ְͨ��" << endl;
			cout << "2 -- ����" << endl;
			cout << "3 -- �ϰ�" << endl;

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
			// ������ְ��ָ�룬���浽������
			new_space[this->m_emp_num + i] = worker;
			
		}

		// �ͷ�ԭ�еĿռ�
		delete[] this->m_emp_array;

		// �����¿ռ��ָ��
		this->m_emp_array = new_space;

		// �����µ�ְ������
		this->m_emp_num = new_size;

		// ����ְ��Ϊ�ձ�־
		this->m_file_is_empty = false;

		// �ɹ���Ӻ󱣴浽�ļ���
		this->save();
		
		// ��ӳɹ�
		cout << "�ɹ����" << add_num << " ����ְ��" << endl;
	}
	else {
		cout << "������������" << endl;
	}
	// ���������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

// �����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //�������ʽ���ļ� -- д�ļ�

	// ��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_emp_num; i++) {
		ofs << this->m_emp_array[i]->m_id << " "
			<< this->m_emp_array[i]->m_name << " "
			<< this->m_emp_array[i]->m_dept_id << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// ͳ������
int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); // ���ļ� ���ļ�ģʽ

	int id = 0 ;
	string name;
	int dept_id;

	// ͳ�������ı���
	int num = 0;

	while (ifs >> id && ifs >> name && ifs>> dept_id) {
		num++;
	}

	return num;
}

// ��ʼ��Ա��
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dept_id) {
		Worker* worker = NULL;
		if (dept_id == 1) { // ��ͨԱ��
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

// ��ʾְ��
void WorkerManager::showEmp() {

	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_file_is_empty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_emp_num; i++) {
			// ���ö�̬���ó���ӿ�
			this->m_emp_array[i]->showInfo();
		}
	}

	// �������������
	system("pause");
	system("cls");

}

// ɾ��ְ��
void WorkerManager::delEmp() {
	if (this->m_file_is_empty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
	}
	else {
		// ����ְ�����ɾ��
		cout << "��������Ҫְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->isExist(id);

		if (index != -1) { // ְ��������Ҫɾ����Ҫɾ��������Ϊindex��ְ��
			// ����ǰ��
			for (int i = index; i < this->m_emp_num - 1; i++) {
				this->m_emp_array[i] = this->m_emp_array[i + 1];
			}

			this->m_emp_num--; // ���������м�¼����Ա����

			// ͬ�����µ��ļ���
			this->save();

			cout << "ɾ���ɹ�!" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��!" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// �޸�ְ��
void WorkerManager::modifyEmp() {
	if (this->m_file_is_empty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫɾ����ְ���ı�� " << endl;
		int id;
		cin >> id;

		int index = isExist(id);
		if (index != -1){ // ���ҵ����Ϊid��ְ��
			delete this->m_emp_array[index];
			int new_id = 0;
			string new_name = "";
			int new_dept_id = 0;

			cout << "�鵽��" << id << " ��ְ������������ְ���ţ�" << endl;
			cin >> new_id;

			cout << "��������������" << endl;
			cin >> new_name;

			cout << "�������µĸ�λ" << endl;
			cout << "1 -- ��ְͨ��" << endl;
			cout << "2 -- ����" << endl;
			cout << "3 -- �ϰ�" << endl;

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
					cout << "��������!" << endl;

					break;
				}				
			}
			
			// �������ݵ�������
			this->m_emp_array[index] = worker;


			//���浽�ļ���
			this->save();
			cout << "�޸ĳɹ�! " << endl;

		}
		else {
			cout << "�޸�ʧ�ܣ����޴���!" << endl;
		}
	}

	// �����������
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ���ڣ������򷵻�ְ���������е�λ��
int WorkerManager::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_emp_num; i++) {

		if (id == this->m_emp_array[i]->m_id) { //�ҵ�ְ��

			index = i;

			break;
		}
	}

	return index;
}

// ����ְ��
void WorkerManager::findEmp() {
	if (this->m_file_is_empty) {
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ���ı�Ų��ң�" << endl;
		cout << "2������ְ�����������ң�" << endl;

		int select = 0;
		cin >> select;

		if (select == 1) { //���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int index = isExist(id);
			if (index != -1) {
				//�ҵ�ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_emp_array[index]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}

		}
		else if(select == 2) { //����������
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			// �����ж��Ƿ�鵽�ı�־
			bool flag = false; // Ĭ��δ�ҵ�ְ��

			for (int i = 0; i < this->m_emp_num; i++) {
				if (this->m_emp_array[i]->m_name == name) {
					cout << "���ҳɹ���ְ�����Ϊ��"
						<< this->m_emp_array[i]->m_id
						<< " ��ְ����Ϣ���£�" << endl;
					flag = true;

					// ������ʾ��Ϣ�ӿ�
					this->m_emp_array[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}
		}
		else {
			cout << "��������!" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

// ���ձ������
void WorkerManager::sortEmp() {
	if (this->m_file_is_empty) {
		cout << "�ļ������ڻ��¼Ϊ��!" << endl;

		// �����������
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_emp_num; i++) {
			int min_or_max = i; //������Сֵ�������ֵ���±�
			for (int j = i + 1; j < this->m_emp_num; j++) {
				if (select == 1) {// ����
					if (this->m_emp_array[min_or_max]->m_id >
						this->m_emp_array[j]->m_id) {
						min_or_max = j;
					}
				}
				else { // ����
					if (this->m_emp_array[min_or_max]->m_id <
						this->m_emp_array[j]->m_id) {
						min_or_max = j;
					}
				}
			}
			// �ж�һ��ʼ�϶� ��Сֵ�����ֵ���ǲ��Ǽ������Сֵ�������ֵ
			if (i != min_or_max) {
				Worker* temp = this->m_emp_array[i];
				this->m_emp_array[i] = this->m_emp_array[min_or_max];
				this->m_emp_array[min_or_max] = temp;
			}
		}

		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save(); // ����������浽�ļ���
		this->showEmp(); // չʾ����ְ��
	}
}

// ����ļ�
void WorkerManager::cleanFile() {
	cout << "ȷ�����? " << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select;
	cin >> select;
	if (select == 1) {

	}

	if (select == 1) {
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ����ؽ�
		ofs.close();

		if (this->m_emp_array != NULL) {
			// ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_emp_num; i++) {
				delete this->m_emp_array[i];
				this->m_emp_array[i] = NULL;
			}

			// ɾ����������ָ��
			delete[] this->m_emp_array;
			this->m_emp_array = NULL;
			this->m_emp_num = 0;
			this->m_file_is_empty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

// ��������
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


