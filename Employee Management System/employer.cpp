#include"employer.h"

void Employer::show_info()//��ʾ������Ϣ
{
    cout << "ְ�����:" << this->m_id
         << "\tְ������:" << this->m_name
         << "\tְ����λ:" << this->get_dept_nanme()
         << "\t��λְ����ɻ�������" << endl;
}
string Employer::get_dept_nanme()//��ȡ��λ����
{
    return string("��ͨԱ��");
}

//���캯��
Employer::Employer(int id, string name, int deptid)
{ 
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}