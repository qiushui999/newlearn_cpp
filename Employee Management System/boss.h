//�ϰ��ļ�
#pragma once
#include"all.h"
#include"worker.h"

class Boss :public Worker
{
public:
    //������д
    //���캯��
    Boss(int id, string name, int deptid);//Ա��id��������Ա����λ//work�����
    virtual void show_info();//��ʾ������Ϣ
    virtual string get_dept_nanme();//��ȡ��λ����


};