#pragma once
#include"common.h"
#include"point.h"
using namespace std;
class Circle
{
public:
    void setcenter(Point center);
    Point getcenter();
    void setr(int r);
    int getr();

private:
    Point m_center;//Բ��
    int m_r;//�뾶

};