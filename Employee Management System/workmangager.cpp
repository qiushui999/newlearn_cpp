#include"workmanager.h"
#include"employer.h"
#include"jingli.h"
#include"boss.h"
#include"worker.h"
//WorkerManager�������µĺ���ʵ��
WorkerManager::WorkerManager()//���캯��
{
	//��ʼ������
	/*this->m_empnum = 0;
	this->m_empnum = NULL;����ÿ�ζ���ʼ��Ϊ0*/
	//�÷��������
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		this->m_empnum = 0;
		this->m_empnum = NULL;//����ÿ�ζ���ʼ��Ϊ0
		this->m_fileis_empty = true;
		ifs.close();
		return;
	}
	//2.�ļ����ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->m_empnum = 0;
		this->m_empnum = NULL;
		this->m_fileis_empty = true;
		ifs.close();
		return;
	}
	//3.�ļ����ڣ�����������
	int num = this->get_emp_num();
	cout << "��ǰְ��������" << num << endl;
	//���³�ʼ����
	this->m_empnum = num;
	this->m_emparry = new Worker *[this->m_empnum];
	this->init_emp();
	ifs.close();
	////���Դ���
	////���ٿռ䣬�������ݴ���������
	
	//for (int i = 0; i < this->m_empnum; i++)
	//{
	//	cout << "ְ�����:" << this->m_emparry[i]->m_id 
	//		 << "\tְ������:" << this->m_emparry[i]->m_name
	//		 << "\tְ�����ű��:"<< this->m_emparry[i]->m_deptid
	//		 << endl;
	//}

}
void WorkerManager::init_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	//��Դ�ļ����ﶫ��������ȥ
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employer(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Jingli(id, name, did);
		}
		else
		{
			worker = new Boss(id, name, did);
		}
		this->m_emparry[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::show_menu()
{

	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//1.���ְ������
void WorkerManager::add_emp()
{
	cout << "���������ְ������:>" ;
	int addnum = 0;//����������������
	cin >> addnum;
	if (addnum > 0)
	{
		//���
		//��������¿ռ��С
		int newsize = this->m_empnum + addnum;//������=ԭ������+��������
		Worker**newspace= new Worker* [newsize];//����newsize�������С�¿ռ� 
		//��ԭ���ռ�ְ�����ݿ������¿ռ�
		if (this->m_emparry != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				//Worker** m_emparry;
				newspace[i] = this->m_emparry[i];
			}
		}
		//���������ְ��
		for (int i = 0; i < addnum; i++)
		{
			int id;//ְ�����
			string name;//����
			int bmselcet;//����ѡ��
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "������ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> bmselcet;
			Worker* worker = NULL;
			switch (bmselcet)
			{
			case 1:
				worker = new Employer(id, name, 1);
				break;
			case 2:
				worker = new Jingli(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��workerָ�����������
			newspace[this->m_empnum + i] = worker;
		}
		//�ͷ�ԭ���ռ�
		delete[]this->m_emparry;
		//�����¿ռ�ָ��
		this->m_emparry = newspace;
		//�����µ�ְ������
		this->m_empnum = newsize;
		//����ְ����Ϊ��
		this->m_fileis_empty = false;
		cout << "���Ѿ������" << addnum << "��ְ��" << endl;
		//��������
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	//�����������
	system("pause");
	system("cls");


}
void WorkerManager::save()
{
	ofstream ofs;//�����
	ofs.open(FILENAME, ios::out);//���뷽ʽ���ļ���д�ļ�
	//��ÿ���˱��������ļ�
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparry[i]->m_id << "\t"
			<< this->m_emparry[i]->m_name << "\t"
			<< this->m_emparry[i]->m_deptid <<endl;
	}
	ofs.close();
}
//�õ�ְ������
int WorkerManager::get_emp_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;//����

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;

}
void WorkerManager::exit_system()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");//���������
	exit(0);
}
//2.��ʾ��Ա
void WorkerManager::show_emp()
{
	
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileis_empty)
	{
		cout << "�ļ������ڻ�ռ�¼" << endl;
	}
	else
	{ 
		for (int i = 0; i < this->m_empnum; i++)
		{
			this->m_emparry[i]->show_info();
		}
	}
	/*system("pause");
	system("cls");*/
}
//3.ɾ��ְ��
void WorkerManager::del_emp()
{
	if (this->m_fileis_empty)
	{
		cout << "�ļ������ڻ�ռ�¼" << endl;
	}
	else
	{
		int id = 0;
		//����ְ�����ɾ��
		cout << "������Ҫɾ��ְ�����:>" ;
		cin >> id;
		int index = this->id_exist(id);//�ж�����id�Ƿ����
		if (index != -1)//˵��ְ������
		{
			//��indexλ������ǰ��
			for (int i = index; i < this->m_empnum-1; i++)
			{
				this->m_emparry[i] = this->m_emparry[i + 1];
			}
			this->m_empnum--;//������Ա����
			//����ͬ�������ļ���
			this->save();	
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ���ְ��������" << endl; 
		}
	}
	//�����������
	system("pause");
	system("cls");
}
//�ж�Ա���Ƿ����
//���ڷ��ر�ţ������ڷ���-1
int WorkerManager::id_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparry[i]->m_id== id)
		{
			//cout << "��ְ�������ڣ����������" << endl;

			index = i;
			break;
		}
		else
		{
			//cout << "��ְ��������" << endl;
		}
		return index;
	}
}
//��������
WorkerManager::~WorkerManager()
{
	if (this->m_emparry != NULL)
	{
		delete[]this->m_emparry;
		this->m_emparry = NULL;
	}
}