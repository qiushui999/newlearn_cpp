#include"circle.h"

void Circle::setr(int r)
{
    m_r = r;
}
int Circle::getr()
{
    return m_r;
}
void Circle::setcenter(Point center)
{
    m_center = center;
}
Point Circle::getcenter()
{
    return m_center;
}