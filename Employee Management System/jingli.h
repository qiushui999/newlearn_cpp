//经理文件
#pragma once
#include"all.h"
#include"worker.h"

class Jingli :public Worker
{
public:
    //子类重写
    //构造函数
    Jingli(int id, string name, int deptid);//员工id，姓名，员工岗位//work类里的
    virtual void show_info();//显示个人信息
    virtual string get_dept_nanme();//获取岗位名称


};