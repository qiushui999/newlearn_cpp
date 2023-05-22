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
    Point m_center;//Ô²ÐÄ
    int m_r;//°ë¾¶

};