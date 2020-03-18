#include <cstdio>
#include <cstring>
using namespace std;
#define N 200050
#define INF 0x7fffffff

int n, to[N], pre[N], ans[N], _ans = INF;

inline int min(int x, int y)
{
    return x<y?x:y;
}

void dfs(int u, int tim)
{
    if(ans[u])
        return ;
    if(pre[u] != -1)
    {
        _ans = min(_ans, tim-pre[u]);
        return ;
    }
    pre[u] = tim;
    dfs(to[u], tim+1);
    ans[u] = _ans;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1 ; i <= n; i++)
        scanf("%d", &to[i]);
    memset(pre, -1, sizeof(pre));
    for(int i = 1; i <= n; i++)
        if(pre[i] == -1)
            dfs(i, 0);
    printf("%d\n", _ans);
    return 0;
}
