#include"boss.h"

void Boss::show_info()//��ʾ������Ϣ
{
    cout << "ְ�����:" << this->m_id
        << "\tְ������:" << this->m_name
        << "\tְ����λ:" << this->get_dept_nanme()
        << "\t\t��λְ��ͳ��ȫ��" << endl;
}
string Boss::get_dept_nanme()//��ȡ��λ����
{
    return string("�ϰ�");
}

//���캯��
Boss::Boss(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}