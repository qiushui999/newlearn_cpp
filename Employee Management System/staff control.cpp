#include"workmanager.h"
#include"employer.h"
#include"jingli.h"
#include"boss.h"
#include"worker.h"



int main()
{
     int choice=0;//��¼�û���ѡ��
     WorkerManager worktest;
    // ���Դ���
    //Worker* worker = NULL;
    //worker=new Employer(1, "����", 1);//����ָ���������
    //worker->show_info();
    //worker=new Jingli(2,"����",2);
    //worker->show_info();
    //delete worker;
    //worker=new Boss(3,"����",3);
    //worker->show_info();
    //delete worker;
     do
     {
         worktest.show_menu();//չʾ�˵�
         cout<<"���������ѡ��>";
         cin>>choice;
        	switch (choice)
     	{
     	    case 0: //�˳�ϵͳ
                worktest.exit_system();
     		    break;
         	case 1: //���ְ��
                worktest.add_emp();
     		    break;
         	case 2: //��ʾְ��
                worktest.show_emp();
     		    break;
     	    case 3: //ɾ��ְ��
                worktest.del_emp();
     		    break;
     	    case 4: //�޸�ְ��
     		    break;
         	case 5: //����ְ��
     		    break;
     	    case 6: //����ְ��
     		    break;
     	    case 7: //����ļ�
     		    break;
     	    default:
                 system("cls");
     		    break;
     	}

     } while (choice);

    system("pause");
    return 0;
};