#include"boss.h"

void Boss::show_info()//显示个人信息
{
    cout << "职工编号:" << this->m_id
        << "\t职工姓名:" << this->m_name
        << "\t职工岗位:" << this->get_dept_nanme()
        << "\t\t岗位职责：统筹全局" << endl;
}
string Boss::get_dept_nanme()//获取岗位名称
{
    return string("老板");
}

//构造函数
Boss::Boss(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}