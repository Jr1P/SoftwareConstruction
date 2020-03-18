#include <cstdio>
#define N 205

int n, m, t;
int time[N], cost[N], dp[N][N];

inline int max(int x, int y)
{
    return (x > y)? x: y;
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", cost+i, time+i);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= cost[i]; j--)
            for(int k = t; k >= time[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j-cost[i]][k-time[i]]+1);
    printf("%d\n", dp[m][t]);
    return 0;
}