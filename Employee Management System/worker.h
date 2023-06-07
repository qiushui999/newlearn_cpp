#pragma once
#include"all.h"

//职工抽象类，多态
class Worker
{

public:
    //纯虚函数只做声明，以便多态使用
    virtual void show_info() = 0;//显示个人信息
    virtual string get_dept_nanme() = 0;//获取岗位名称

    int m_id;//职工编号
    string m_name;//职工姓名
    int m_deptid;//职工所在部门名称编号
};