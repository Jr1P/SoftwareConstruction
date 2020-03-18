#include <iostream>
#include <string>
using namespace std;
const int MAXN = 35;

struct student
{
    long num;
    string name;
    float sco;
}score[MAXN];

int Input(struct student score[])
{
    int cnt = 1;
    score[1].sco = 0;
    cout <<"Enter the student number,name and the score:"<<endl;
    while (cnt <= 30 && score[cnt-1].sco >= 0 )
    {
        cin >> score[cnt].num >> score[cnt].name >> score[cnt].sco;
        cnt++;
    }
    if (score[cnt-1].sco < 0)
        cnt--;
    return --cnt;
}

void Total1(struct student score[], int n)
{
    int total = 0;
    for(int i = 1; i <= n; i++)
        if (score[i].sco < 60)
            total++;
    cout<<"The number of fail is:"<<total<<endl;
    cout<<"Num\tName\tScore"<<endl;
    for(int i = 1; i <= n; i++)
        if (score[i].sco < 60)
            cout << score[i].num << '\t' << score[i].name << '\t' << score[i].sco << '\n';
}

//函数说明：统计成绩在全班平均分及平均分之上的学生人数及打印这些学生的名单
//参数说明：参数说明：数组score存放学生的学号、姓名和成绩，n班级实际人数.
//返回值：无
void Total2(struct student score[],int n)
{
    float average = 0.0f;
    int total = 0;
    for(int i = 1; i <= n; i++)
        average += score[i].sco;
    if (n != 0)
        average /= n;
    else
        average = 0.0;
    cout<<"The average score is "<<average<<endl;
    for(int i = 1; i <= n; i++)
        if (average <= score[i].sco)
            total++;
    cout<<"The number above average score is:"<<total<<endl;
    cout<<"Num\tName\tScore"<<'\n';
    for(int i = 1; i <= n; i++)
        if (average <= score[i].sco)
            cout << score[i].num << '\t' << score[i].name << '\t' << score[i].sco << '\n';
}

//主函数
int main()
{
    int n;
    n = Input(score);
    Total1(score, n);
    Total2(score, n);
    return 0;
}