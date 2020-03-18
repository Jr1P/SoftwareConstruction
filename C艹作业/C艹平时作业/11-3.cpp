#include <iostream>
#define eps 1e-6
#define PI 3.14159      //����pi

using namespace std;

class Shape
{
public:
	virtual void GetArea() = 0;
	virtual void GetPerim() = 0;
};

class Rectangle: public Shape
{
public:
	Rectangle(double length, double width)
	{
		_length = length;
		_width = width;
	}
	void GetArea();		//�������Ĺ��캯������ ���� ����
	void GetPerim();
private:
    double _length, _width;    //���Ϳ�
};

class Circle: public Shape
{
public:
	Circle(double radius)
	{
		_radius = radius;
	}
	void GetArea();	//�������Ĺ��캯������ ���� ����
	void GetPerim();
private:
    double _radius;    //Բ�İ뾶
};

void Rectangle:: GetArea()      //����������
{
    cout<<"���ε�����ǣ�"<<_length * _width<<endl;
}

void Rectangle:: GetPerim()     //��������ܳ�
{
    cout<<"���ε��ܳ��ǣ�"<<(_length + _width) * 2<<endl;
}

void Circle:: GetArea()     //����Բ�����
{
    cout<<"Բ�ε�����ǣ�"<<PI* _radius * _radius<<endl;
}

void Circle:: GetPerim()        //����Բ���ܳ�
{
    cout<<"Բ�ε��ܳ��ǣ�"<<2 * PI * _radius<<endl;
}

void result(Shape &cs)
{
	cs.GetArea();
	cs.GetPerim();
}

int main()
{
	double len, wid, r;
	cout<<"������εĳ���";
	cin >> len;
	cout<<"������εĿ�";
	cin >> wid;
	cout<<"����Բ�İ뾶��";
	cin >> r;
	if (len < -eps || wid < -eps || r < -eps)
		cout<<"������������"<<endl;//
	else
	{
		Rectangle R(len, wid);
		Circle C(r);
		Shape* ptr = &R;
		result(*ptr);
		ptr = &C;
		result(*ptr);
	}
    return 0;
}
