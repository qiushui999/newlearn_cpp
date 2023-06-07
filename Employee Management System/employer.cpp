#include"employer.h"

void Employer::show_info()//显示个人信息
{
    cout << "职工编号:" << this->m_id
         << "\t职工姓名:" << this->m_name
         << "\t职工岗位:" << this->get_dept_nanme()
         << "\t岗位职责：完成基本任务" << endl;
}
string Employer::get_dept_nanme()//获取岗位名称
{
    return string("普通员工");
}

//构造函数
Employer::Employer(int id, string name, int deptid)
{ 
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}