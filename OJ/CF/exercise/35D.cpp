#include <cstdio>
#define X 10010
#define N 110

int dp[X], c[N];
int n, food;

inline int max(int x, int y)
{
    return x > y? x: y;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &food);
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        c[i] = x*(n-i+1);
    }
    for(int i = 1; i <= n; i++)
        for(int v = food; v >= c[i]; v--)
            dp[v] = max(dp[v], dp[v-c[i]]+1);
    printf("%d\n", dp[food]);
    return 0;
}
