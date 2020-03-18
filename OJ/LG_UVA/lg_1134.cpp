#include <cstdio>
#define N 50000050
#define M 10000000

int n;
long long ans = 1;

int main()
{
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
        ans = ans*i;
        while(ans % 10 == 0)
            ans /= 10;
        ans %= M;
    }
    ans %= 10;
    printf("%d\n", ans);
    return 0;
}
