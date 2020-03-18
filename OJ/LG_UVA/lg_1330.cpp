#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 10050
#define M 100050

vector<int > g[N];
bool vis[N];
int color[N];
int n, m, ans[2];

inline int min(int x, int y)
{
    return x<y?x:y;
}

void bfs(int s)
{
    queue<int > q;
    q.push(s);
    color[s] = 0;
    vis[s] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i = 0; i < g[now].size(); i++)
        {
            int v = g[now][i];
            if (color[now] == color[v])
            {
                printf("Impossible\n");
                exit(0);
            }
            if (!vis[v])
            {
                q.push(v);
                vis[v] = 1;
                color[v] = color[now]^1;
                ans[color[v]]++;
            }
        }
    }
}

int main()
{
    int _ans = 0;
    scanf("%d%d", &n, &m);
    memset(color, -1, sizeof color);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans[0] = 1; ans[1] = 0;
            color[i] = 0;
            bfs(i);
            _ans += min(ans[0], ans[1]);
        }
    }
    printf("%d\n", _ans);
    return 0;
}
