//��ͨԱ���ļ�
#pragma once
#include"all.h"
#include"worker.h"

class Employer :public Worker
{
public:
    //������д
    //���캯��
    Employer(int id, string name, int deptid);//Ա��id��������Ա����λ//work�����
    virtual void show_info();//��ʾ������Ϣ
    virtual string get_dept_nanme();//��ȡ��λ����


}; 