#include<iostream>
using namespace std;

class BookOrder{
    string BookID;
    int Quantity;
    //数量
public:
    double price;
    inline void BookInit(string s, int num, double p){
    	BookID = s;
    	Quantity = num;
    	price = p;
    }
    inline void BookInfo(){

        cout<<"图书编号：" << BookID << '\n';
        //在此处添加代码输出图书编号，然后换行
        cout<<"数量：" << Quantity << '\n';
        //在此处添加代码输出图书数量，然后换行
        cout<<"单价：" << price << '\n';
        //在此处添加代码输出图书单价，然后换行
    }
    inline void priceModify(double count)
    {
    	price *= count;
    }
};
int main()
{
	ios::sync_with_stdio(false);
    //在此处添加代码  声明类对象 bkorder
    string s;
    int num;
    double p;

    cout<<"输入图书编号：";
    cin >> s;
    cout<<"输入数量和单价：";
    cin >> num >> p;
    BookOrder bkorder;
    bkorder.BookInit(s, num, p);
    bkorder.BookInfo();//在此处添加代码调用成员函数BookInfo输出图书信息

    float count;
    cout<<"输入该编号图书折扣(0-1之间)：";
    cin>>count;
    bkorder.priceModify(count);
    cout<<"单价调整后："<<endl;
    bkorder.BookInfo();
    return 0;
}