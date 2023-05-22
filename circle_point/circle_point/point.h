#pragma once
#include"common.h"
using namespace std;
class Point
{
public:
    void setx(int x);
    int getx();
    void sety(int y);
    int gety();
private:
    int m_x;
    int m_y;

};