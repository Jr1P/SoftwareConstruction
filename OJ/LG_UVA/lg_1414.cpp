#include <cstdio>
#define N 10050
#define INF 1000050

int cnt[INF], k, max = 0, ans[N], n;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        cnt[a]++;
        max = (max<a)?a:max;
    }
    for(int k = 1; k <= max; k++)
    {
        int c = 0;
        for(int i = k; i <= max; i += k)
            c += cnt[i];
        ans[c] = (k>ans[c])?k:ans[c];
    }
    for(int j = n-1; j > 0; j--)
    {
        if(ans[j] == 0 || ans[j] < ans[j+1])
             ans[j] = ans[j+1];
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}
