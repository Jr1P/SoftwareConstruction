#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 100010
using namespace std;
typedef long long LL;

struct node
{
    int to, next, val;
} mp[MAXN << 1];

int n, tol, ans;
int val[MAXN * 32];
int ch[MAXN * 32][2];
int cnt, head[MAXN];

inline void init()
{
    ans = cnt = 0;
    tol = 1;
    ch[0][0] = ch[0][1] = 0;
    memset(head, -1, sizeof(head));
}

inline void add(int u, int v, int w)
{
    mp[cnt].to = v;
    mp[cnt].val = w;
    mp[cnt].next = head[u];
    head[u] = cnt++;
}

void insert(int x)
{
    int root = 0;
    for (int i = 31; i >= 0; i--)
    {
        int id = (x >> i) & 1;
        if (!ch[root][id])
        {
            ch[tol][0] = ch[tol][1] = 0;
            val[tol] = 0;
            ch[root][id] = tol++;
        }
        root = ch[root][id];
    }
    val[root] = x;
}

int query(int x)
{
    int root = 0;
    for (int i = 31; i >= 0; i--)
    {
        int id = (x >> i) & 1;
        if (ch[root][id ^ 1])
            root = ch[root][id ^ 1];
        else
            root = ch[root][id];
    }
    return x ^ val[root];
}

void dfs(int u, int pre, int val)
{
    int i, v;
    insert(val);
    for (i = head[u]; i != -1; i = mp[i].next)
    {
        v = mp[i].to;
        if (v == pre) continue;
        ans = max(ans, query(val ^ mp[i].val));
        dfs(v, u, val ^ mp[i].val);
    }
}

int main()
{
    int i, u, v, w;
    while (~scanf("%d", &n))
    {
        init();
        for (i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        dfs(0, -1, 0);
        printf("%d\n", ans);
    }
    return 0;
}