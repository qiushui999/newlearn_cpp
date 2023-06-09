#pragma once 
#include"all.h"
#include"worker.h"

//头文件声明
class WorkerManager
{

public:
    WorkerManager();//构造函数

    //展示菜单
    void show_menu(); //展示菜单

    void exit_system();//退出程序

    //记录职工人数
    int m_empnum;
    //职工数组指针
    //用一个worker*数组保存父类指针
    //父类指针可以存放子类对象
    //不同子类没办法统一保存
    //所以用父类指针数组保存
    //然后用worker**指向该数组
    Worker** m_emparry;

    //1.添加职工
    void add_emp(); 
    
    //保存文件
    void save();
    //判断文件是否为空
    bool m_fileis_empty;
    //获取职工人数
    int get_emp_num();
    //初始化职工
    void init_emp();
    //2.显示职工
    void show_emp();
    //3.删除职工
    void del_emp();
    //判断员工是否存在
    //存在返回编号，不存在返回-1
    int id_exist(int id);
<<<<<<< HEAD
    //4.修改职工
    void modify_emp();
    //5.查找职工
    void search_emp();
    //6.排序员工
    void sort_emp();//这里用选择排序
    //7.清空数据
    void cleanall();

=======
>>>>>>> 56af272e7968aa4aadcd7dca3cca9dfcc0b051eb



    ~WorkerManager();//析构函数
};
