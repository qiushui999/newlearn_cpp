#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
    //抽象计算函数
    virtual void calculate()=0;
};
class VideoCard//显卡
{
public:
    //抽象显示函数
    virtual void display()=0;
};
class Memory//内存
{
public:
    //抽象储存函数
    virtual void storage()=0;
};
class Computer
{
public:

    Computer(CPU *cpu,VideoCard *vc,Memory *mem)//构造函数
    {
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    void work()
    {
        //让零件工作起来
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

//具体厂商
class InterCPU:public CPU
{
public:
    virtual void calculate()
    {
        cout<<"intelcpu计算"<<endl; 
    };
};
class InterVideoCard:public VideoCard
{
public:
    virtual void display()
    {
        cout<<"Inter显卡显示"<<endl; 
    };
};
class InterMemory:public Memory
{
public:
    virtual void storage()
    {
        cout<<"Inter内存存储"<<endl; 
    };
};

class LECPU:public CPU
{
public:
    virtual void calculate()
    {
        cout<<"LEcpu计算"<<endl; 
    };
};
class LEVideoCard:public VideoCard
{
public:
    virtual void display()
    {
        cout<<"LE显卡显示"<<endl; 
    };
};
class LEMemory:public Memory
{
public:
    virtual void storage()
    {
        cout<<"LE内存存储"<<endl; 
    };
};

void test1()
{       
    //第一台电脑
    CPU *intelcpu =new InterCPU;
    VideoCard *videocard=new InterVideoCard;
    Memory *menory=new InterMemory;
    Computer *computer1=new Computer(intelcpu,videocard,menory);
    computer1->work();
    delete computer1;

};

int main()
{
    test1();

    system("pause");
} // namespace std;
