#include <cstdio>
#include <cmath>
#define T 105
#define M 205
#define eps 1e-6
int n, t, ans;

inline bool check(int a, int b, int c)
{
    double f = sqrt(n-a*a-b*b-c*c);
    double y = f-floor(f);
    if (y < eps && y > -eps && floor(f) <= c)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &n);
        for(int i = floor(sqrt(n))/2; i <= floor(sqrt(n)); i++)
            for(int j = sqrt((n-i*i)/3); j <= i; j++)
                for(int k = 0; k <= j; k++)
                    if (check(i, j, k))
                        ans++;
        printf("%d\n", ans);
    }
    return 0;
}
