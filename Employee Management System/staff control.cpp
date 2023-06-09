#include"workmanager.h"
#include"employer.h"
#include"jingli.h"
#include"boss.h"
#include"worker.h"



int main()
{
     int choice=0;//记录用户的选择
     WorkerManager worktest;
    // 测试代码
    //Worker* worker = NULL;
    //worker=new Employer(1, "张三", 1);//父类指向子类对象
    //worker->show_info();
    //worker=new Jingli(2,"李四",2);
    //worker->show_info();
    //delete worker;
    //worker=new Boss(3,"王五",3);
    //worker->show_info();
    //delete worker;
     do
     {
         worktest.show_menu();//展示菜单
         cout<<"请输入你的选择：>";
         cin>>choice;
        	switch (choice)
     	{
     	    case 0: //退出系统
                worktest.exit_system();
     		    break;
         	case 1: //添加职工
                worktest.add_emp();
     		    break;
         	case 2: //显示职工
                worktest.show_emp();
     		    break;
     	    case 3: //删除职工
                worktest.del_emp();
     		    break;
     	    case 4: //修改职工
<<<<<<< HEAD
                worktest.modify_emp();
     		    break;
         	case 5: //查找职工
                worktest.search_emp();
     		    break;
     	    case 6: //排序职工
                worktest.sort_emp();
     		    break;
     	    case 7: //清空文件
                worktest.cleanall();
=======
     		    break;
         	case 5: //查找职工
     		    break;
     	    case 6: //排序职工
     		    break;
     	    case 7: //清空文件
>>>>>>> 56af272e7968aa4aadcd7dca3cca9dfcc0b051eb
     		    break;
     	    default:
                 system("cls");
     		    break;
     	}

     } while (choice);

    system("pause");
    return 0;
};