#include <iostream>
//#include <algorithm>
using namespace std;
//Jr_P

class array
{
public:
    array();
    void input();
    void output();
    int max();
    float average(); //返回数组中数据的平均值。
    void sort(); 
    void remove_duplicated();

private:
     int N; // size of array
     int a[10];
};

array::array()
{
    N = 10;
}

void array::input()
{
    cout << "please input ten integers: " << endl;
    for(int i = 0; i < N; ++i)
    {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
}

void array::output()
{
     cout << "array a is: " << endl;
     for(int i = 0; i < N; ++i)
     {
         if(i == 0)
            cout << a[i];
         else
            cout << " " << a[i];
     }
     cout << '\n';
}
/*
implement function max
*/
int array::max()
{
    int max = 0;
    for(int i = 0; i < N; ++i)
        if (a[i] > max)
            max = a[i];
    return max;
}

float array::average()
{
    int sum = 0;
    for(int i = 0; i < N; ++i)
        sum += a[i];
    float ans = ((float)sum)/N;
    return ans;
}

void array::sort()
{
    int i, j, k;
    for(i = 0; i < N-1; ++i)
    {
        k = i;
        for(j = i+1; j < N; ++j)
            if (a[j] > a[k])
                k = j;
        int tmp = a[i];
        a[i] = a[k];
        a[k] = tmp;
    }
}
//implement function remove_duplicated
void array::remove_duplicated()
{
    int newarray[10], cnt = 0;
    bool pp[10];
    for(int i = 0; i < N; ++i)
        pp[i] = false;
    for(int i = 0; i < N; ++i)
        if(pp[a[i]] == false)
        {
            pp[a[i]] = true;
            newarray[cnt++] = a[i];
        }
    N = cnt;
    for(int i = 0; i < N; ++i)
        a[i] = newarray[i];
}

int main()
{
    array a;
    a.input();
    a.output();
    cout<<"The max number is "<< a.max() <<endl;
    cout<<"The average number is "<< a.average() <<endl;
    a.remove_duplicated();
    cout<<"after remove duplicated ";
    a.output();
    a.sort();
    cout<<"after sort ";
    a.output();
    return 0;
}