#pragma once
#include"all.h"

//ְ�������࣬��̬
class Worker
{

public:
    //���麯��ֻ���������Ա��̬ʹ��
    virtual void show_info() = 0;//��ʾ������Ϣ
    virtual string get_dept_nanme() = 0;//��ȡ��λ����

    int m_id;//ְ�����
    string m_name;//ְ������
    int m_deptid;//ְ�����ڲ������Ʊ��
};