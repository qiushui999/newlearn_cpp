#pragma once 
#include"all.h"
#include"worker.h"

//ͷ�ļ�����
class WorkerManager
{

public:
    WorkerManager();//���캯��

    //չʾ�˵�
    void show_menu(); //չʾ�˵�

    void exit_system();//�˳�����

    //��¼ְ������
    int m_empnum;
    //ְ������ָ��
    //��һ��worker*���鱣�游��ָ��
    //����ָ����Դ���������
    //��ͬ����û�취ͳһ����
    //�����ø���ָ�����鱣��
    //Ȼ����worker**ָ�������
    Worker** m_emparry;

    //1.���ְ��
    void add_emp(); 
    
    //�����ļ�
    void save();
    //�ж��ļ��Ƿ�Ϊ��
    bool m_fileis_empty;
    //��ȡְ������
    int get_emp_num();
    //��ʼ��ְ��
    void init_emp();
    //2.��ʾְ��
    void show_emp();
    //3.ɾ��ְ��
    void del_emp();
    //�ж�Ա���Ƿ����
    //���ڷ��ر�ţ������ڷ���-1
    int id_exist(int id);



    ~WorkerManager();//��������
};
