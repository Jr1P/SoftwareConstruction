#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+1;

int a[MAXN], d[MAXN];

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n; i++)
            scanf("%d", &a[i]);
        if (n == 0)  //特判一下 
        {
            printf("0\n");
            return 0;
        }
        d[1] = a[1];  //初始化 
        int len = 1;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] > d[len])
                d[++len]=a[i];  //如果可以接在len后面就接上，如果是最长上升子序列，这里变成> 
            else  //否则就找一个最该替换的替换掉 
            {
                int j = lower_bound(d+1,d+len+1,a[i])-d;  //找到第一个大于它的d的下标，如果是最长上升子序列，这里变成lower_bound 
                d[j] = a[i]; 
            }
        }
        printf("%d\n",len);
    }  
    return 0;
}
