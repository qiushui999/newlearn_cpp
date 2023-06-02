#include<iostream>
#include<string>
using namespace std;

class CPU
{
public:
    //������㺯��
    virtual void calculate()=0;
};
class VideoCard//�Կ�
{
public:
    //������ʾ����
    virtual void display()=0;
};
class Memory//�ڴ�
{
public:
    //���󴢴溯��
    virtual void storage()=0;
};
class Computer
{
public:

    Computer(CPU *cpu,VideoCard *vc,Memory *mem)//���캯��
    {
        m_cpu=cpu;
        m_vc=vc;
        m_mem=mem;
    }
    void work()
    {
        //�������������
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

private:
    CPU *m_cpu;
    VideoCard *m_vc;
    Memory *m_mem;
};

//���峧��
class InterCPU:public CPU
{
public:
    virtual void calculate()
    {
        cout<<"intelcpu����"<<endl; 
    };
};
class InterVideoCard:public VideoCard
{
public:
    virtual void display()
    {
        cout<<"Inter�Կ���ʾ"<<endl; 
    };
};
class InterMemory:public Memory
{
public:
    virtual void storage()
    {
        cout<<"Inter�ڴ�洢"<<endl; 
    };
};

class LECPU:public CPU
{
public:
    virtual void calculate()
    {
        cout<<"LEcpu����"<<endl; 
    };
};
class LEVideoCard:public VideoCard
{
public:
    virtual void display()
    {
        cout<<"LE�Կ���ʾ"<<endl; 
    };
};
class LEMemory:public Memory
{
public:
    virtual void storage()
    {
        cout<<"LE�ڴ�洢"<<endl; 
    };
};

void test1()
{       
    //��һ̨����
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
