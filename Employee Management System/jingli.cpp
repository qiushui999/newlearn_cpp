#include"jingli.h"

void Jingli::show_info()//��ʾ������Ϣ
{
    cout << "ְ�����:" << this->m_id
        << "\tְ������:" << this->m_name
        << "\tְ����λ:" << this->get_dept_nanme()
        << "\t\t��λְ��: ����Ա����������" << endl;
}
string Jingli::get_dept_nanme()//��ȡ��λ����
{
    return string("����");
}

//���캯��
Jingli::Jingli(int id, string name, int deptid)
{
    this->m_id = id;
    this->m_name = name;
    this->m_deptid = deptid;
}