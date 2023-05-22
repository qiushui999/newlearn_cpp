#include"common.h"
#include"point.h"
#include"circle.h"

//�������
//���Բ�Ĺ�ϵ
void is_incircle(Circle& c, Point& p)
{
	int distance = (c.getcenter().getx() - p.getx()) * (c.getcenter().getx() - p.getx()) +
		(c.getcenter().gety() - p.gety()) * (c.getcenter().gety() - p.gety());//�����������
	int rdistance = c.getr() * c.getr();//�뾶ƽ��
	if (rdistance > distance)
	{
		cout << "1" << endl;
	}
	else if (rdistance < distance)
	{
		cout << "2" << endl;
	}
	else
	{
		cout << "0" << endl;
	}
}

int main()
{
	//�������
	Point o;
	o.setx(0);
	o.sety(0);//Բ��
	Point p;
	p.setx(1);
	p.sety(1);

	Circle c;
	c.setcenter(o);
	c.setr(10);

	is_incircle(c, p);

	system("pause");
	return 0;
}