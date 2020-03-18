#include <cstdio>
#define N 105

int n, l[N], r[N];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &l[i], &r[i]);
    int p;
    scanf("%d", &p);
    int i;
    for(i = 1; (l[i]-p)*(r[i]-p) > 0; i++)
    {}
    printf("%d\n", n-i+1);
    return 0;
}
