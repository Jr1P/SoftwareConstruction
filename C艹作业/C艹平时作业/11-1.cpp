#include <iostream>

using namespace std;

class CharShape
{
public:
	CharShape()
    {
        _ch = '*';
    }
    virtual void Show() = 0;
protected:
    char _ch;       //组成图形的字符
};

class Triangle: public CharShape
{
public:
	Triangle(char ch, int row);

    void Show();

private:
    int _rows;      //行数
};

class Rectangle: public CharShape
{
public:
	Rectangle(char ch, int row, int col);

    void Show();
private:
    int _rows, _cols;        //行数和列数
};

Triangle::Triangle(char ch, int row)
{
	_ch = ch;
	_rows = row;
}

Rectangle::Rectangle(char ch, int row, int col)
{
	_ch = ch;
	_rows = row;
	_cols = col;
}

void Triangle::Show()       //输出字符组成的三角形
{
    for (int i = 1; i <= _rows; i++)
    {
        for (int j = 1; j <= 2*i-1; j++)
            cout << _ch;
        cout << endl;
    }
}

void Rectangle::Show()      //输出字符组成的矩形
{
    for (int i = 1; i <= _rows; i++)
    {
        for (int j = 1; j <= _cols; j++)
            cout << _ch;
        cout << endl;
    }
}


int main()
{
	char ch;
	int row, col;
    cout << "Please enter a character: ";
	cin >> ch;
    cout << "Please enter the number of rows: ";
	cin >> row;
	Triangle tr(ch, row);
    cout << "Please enter a character: ";
	cin >> ch;
    cout << "Please enter the number of rows: ";
	cin >> row;
    cout << "Please enter the number of cols: ";
	cin >> col;
	Rectangle rec(ch, row, col);
    tr.Show();
	rec.Show();
    return 0;

}
