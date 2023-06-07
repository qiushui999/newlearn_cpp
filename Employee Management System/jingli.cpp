#include"jingli.h"

void Jingli::show_info()//显示个人信息
{
    cout << "职工编号:" << this->m_id
        << "\t职工姓名:" << this->m_name
        << "\t职工岗位:" << this->get_dept_nanme()
        << "\t\t岗位职责: 布置员工基本任务" << endl;
}
string Jingli::get_dept_nanme()//获取岗位名称
{
    return string("经理");
}

//构造函数
Jingli::Jingli(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}