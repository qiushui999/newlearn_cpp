#include"workmanager.h"
#include"employer.h"
#include"jingli.h"
#include"boss.h"
#include"worker.h"
//WorkerManager类声明下的函数实现
WorkerManager::WorkerManager()//构造函数
{
	//初始化属性
	/*this->m_empnum = 0;
	this->m_empnum = NULL;不能每次都初始化为0*/
	//得分三种情况
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_empnum = 0;
		this->m_empnum = NULL;//不能每次都初始化为0
		this->m_fileis_empty = true;
		ifs.close();
		return;
	}
	//2.文件存在，且没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_empnum = 0;
		this->m_empnum = NULL;
		this->m_fileis_empty = true;
		ifs.close();
		return;
	}
	//3.文件存在，且已有数据
	int num = this->get_emp_num();
	cout << "当前职工人数：" << num << endl;
	//更新初始人数
	this->m_empnum = num;
	this->m_emparry = new Worker *[this->m_empnum];
	this->init_emp();
	ifs.close();
	////测试代码
	////开辟空间，并将数据存在数组中
	
	//for (int i = 0; i < this->m_empnum; i++)
	//{
	//	cout << "职工编号:" << this->m_emparry[i]->m_id 
	//		 << "\t职工姓名:" << this->m_emparry[i]->m_name
	//		 << "\t职工部门编号:"<< this->m_emparry[i]->m_deptid
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
	//把源文件的里东西都读进去
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
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//1.添加职工函数
void WorkerManager::add_emp()
{
	cout << "请输入添加职工数量:>" ;
	int addnum = 0;//保存新增人数数量
	cin >> addnum;
	if (addnum > 0)
	{
		//添加
		//计算添加新空间大小
		int newsize = this->m_empnum + addnum;//新人数=原来人数+新增人数
		Worker**newspace= new Worker* [newsize];//开辟newsize个数组大小新空间 
		//将原来空间职工数据拷贝到新空间
		if (this->m_emparry != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				//Worker** m_emparry;
				newspace[i] = this->m_emparry[i];
			}
		}
		//批量添加新职工
		for (int i = 0; i < addnum; i++)
		{
			int id;//职工编号
			string name;//名字
			int bmselect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工名字" << endl;
			cin >> name;
			cout << "请输入职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			cin >> bmselect;
			Worker* worker = NULL;
			switch (bmselect)
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
			//将worker指针放入数组中
			newspace[this->m_empnum + i] = worker;
		}
		//释放原来空间
		delete[]this->m_emparry;
		//更改新空间指向
		this->m_emparry = newspace;
		//更新新的职工人数
		this->m_empnum = newsize;
		//更新职工不为空
		this->m_fileis_empty = false;
		cout << "你已经添加了" << addnum << "名职工" << endl;
		//保存数据
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");


}
void WorkerManager::save()
{
	ofstream ofs;//输出流
	ofs.open(FILENAME, ios::out);//输入方式打开文件，写文件
	//将每个人保存数据文件
	for (int i = 0; i < this->m_empnum; i++)
	{
		ofs << this->m_emparry[i]->m_id << "\t"
			<< this->m_emparry[i]->m_name << "\t"
			<< this->m_emparry[i]->m_deptid <<endl;
	}
	ofs.close();
}
//得到职工人数
int WorkerManager::get_emp_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;//人数

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;

}
void WorkerManager::exit_system()//退出系统
{
	cout << "欢迎下次使用" << endl;
	system("pause");//任意键继续
	exit(0);
}
//2.显示成员
void WorkerManager::show_emp()
{
	
	//判断文件是否为空
	if (this->m_fileis_empty)
	{
		cout << "文件不存在或空记录" << endl;
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
//3.删除职工
void WorkerManager::del_emp()
{
	if (this->m_fileis_empty)
	{
		cout << "文件不存在或空记录" << endl;
	}
	else
	{
		int id = 0;
		//按照职工编号删除
		cout << "请输入要删除职工编号:>" ;
		cin >> id;
		int index = this->id_exist(id);//判断输入id是否存在
		if (index != -1)//说明职工存在
		{
			//从index位置数据前移
			for (int i = index; i < this->m_empnum-1; i++)
			{
				this->m_emparry[i] = this->m_emparry[i + 1];
			}
			this->m_empnum--;//更新人员个数
			//数据同步更新文件中
			this->save();	
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，该职工不存在" << endl; 
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//判断员工是否存在
//存在返回数组号，不存在返回-1
//存在返回编号，不存在返回-1
int WorkerManager::id_exist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{

		if (this->m_emparry[i]->m_id==id)
		{
			//cout << "该职工工存在，请继续操作" << endl;

			index = i;
			break;
		}
	}
	return index;
}
//修改职工
void WorkerManager::modify_emp()
{
	if (this->m_fileis_empty)
	{
		cout << "文件不存在或空记录" << endl;
	}
	else
	{
		int id = 0;
		//按照职工编号修改
		cout << "请输入要修改职工编号:>";
		cin >> id;
		int index = this->id_exist(id);//判断输入id是否存在,并返回数组号
		if (index != -1)//说明职工存在
		{

			delete this->m_emparry[index];
			int newid=0;
			string newname="";
			int newdid=0;
			cout << "查到了id为" << id << "的职工" << endl;
			
			cout << "请输入新职工编号：" ;
			cin >> newid;
			cout << "请输入新职工姓名：";
			cin >> newname;
			//
			int bmselect = 0;
			cout << "请更新职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> bmselect;
			Worker* worker = NULL;
			switch (bmselect)
			{
			case 1:
				worker = new Employer(newid, newname, 1);
				break;
			case 2:
				worker = new Jingli(newid, newname, 2);
				break;
			case 3:
				worker = new Boss(newid, newname, 3);
				break;
			default:
				break;
			}
			this->m_emparry[index] = worker;
			//数据同步更新文件中
			this->save();
			cout << "修改成功" << endl;	
		}
		else
		{
			cout << "该职工不存在" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
void WorkerManager::search_emp()
{
	if (this->m_fileis_empty)
	{
		cout << "文件不存在或空记录" << endl;
	}
	else
	{
		int select = 0;
		do
		{
			cout << "请输入查找方式" << endl;
			cout << "1.按照编号查找" << endl;
			cout << "2.按照姓名查找" << endl;
			cout << "0.退出查找" << endl;
			cin >> select;
			if (select == 1)
			{
				int id = 0;
				//按照职工编号查找
				cout << "请输入要查找职工编号:>";
				cin >> id;
				int index = this->id_exist(id);//判断输入id是否存在,并返回数组号
				if (index != -1)//说明职工存在
				{

					cout << "该职工信息如下" << endl;
					this->m_emparry[index]->show_info();
				}
				else
				{
					cout << "该职工不存在" << endl;
				}
			}
			else if (select == 2)
			{
				string name;
				cout << "请输入要查找的姓名：";
				cin >> name;
				bool flag = false;//是否查找到标志
				for (int i = 0; i < this->m_empnum; i++)
				{
					if (this->m_emparry[i]->m_name == name)
					{
						cout << "该职工信息如下：" << endl;
						this->m_emparry[i]->show_info();
						flag = true;
					}
				}
				if (flag == false)
				{
					cout << "该职工不存在" << endl;
				}
			}
			else if(select == 0)
			{
				cout << "退出，返回菜单 " << endl;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
			}

		} 
		while (select);
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
void WorkerManager::sort_emp()
{
	if (this->m_fileis_empty)
	{
		cout << "文件不存在或空记录" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工号升序" << endl;
		cout << "2.按职工号降序" << endl;
		int select = 0;
		cin >> select;
		//选择排序
		for (int i = 0; i < this->m_empnum; i++)
		{
			int minormax = i;//最小值或最大值
			for (int j = i + 1; j < this->m_empnum; j++)
			{
				if (select == 1)
				{
					if (this->m_emparry[minormax]->m_id > this->m_emparry[j]->m_id)
					{
						minormax = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_emparry[minormax]->m_id < this->m_emparry[j]->m_id)
					{
						minormax = j;
					}
				}
				else
				{
					cout << "输入错误，请重新输入" << endl;
					break;
				}

			}
			//判断一开始认定最小或最小是不是计算最小或最大
			if (i != minormax)
			{
				Worker* temp = this->m_emparry[i];
				this->m_emparry[i]=this->m_emparry[minormax];
				this->m_emparry[minormax] = temp;
			}
		}
		cout << "排序成功！排序结果为:" << endl;
		this->save();
		this->show_emp();
	}
}
void WorkerManager::cleanall()
{
	cout << "确定清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_emparry != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparry[i] != NULL)
				{
					delete this->m_emparry[i];//数组中每个职工对象
				}
			}
			//删除数组指针
			delete[]this->m_emparry;
			this->m_emparry = NULL;
			this->m_empnum = 0;
			this->m_fileis_empty = true;
			
		}
		cout << "清空成功" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}
//析构代码
WorkerManager::~WorkerManager()
{
	if (this->m_emparry != NULL)
	{

		for (int i = 0; i < this->m_empnum; i++)
		{
			if (this->m_emparry[i] != NULL)
			{
				delete this->m_emparry[i];//数组中每个元素
			}
		}
		delete[]this->m_emparry;
		this->m_emparry = NULL;
	}
}