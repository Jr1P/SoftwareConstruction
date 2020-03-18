#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define inf 0x3f3f3f3f
#define N 10050

vector<int> g[N];
bool vis[N];
int color[N], dfn[N<<1], low[N<<1], stack[N<<1], cnt[N], du[N], ru[N];
int tim = 0, top = 0, n, m, sum = 0, ans = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    vis[u] = true;
    stack[++top] = u;
    int size = g[u].size();
    for(int i = 0; i < size; i++) {
        int v = g[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else {
            if(vis[v])
                low[u] = min(low[u],low[v]);
        }
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        vis[u] = false;
        while(stack[top] != u) {
            color[stack[top]] = sum;
            vis[stack[top--]] = false;
        }
        top--;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    for(int i = 1; i <= n; i++) {
        int sz = g[i].size();
        for(int j = 0; j < sz; j++) {
            if(color[i] != color[g[i][j]]) {
                du[color[i]]++;
                //ru[color[g[i][j]]]++;
            }
        }
        cnt[color[i]]++;
    }
    int num = 0;
    for(int i = 1; i <= sum; i++)
        if(du[i] == 0) {
            num++;
            ans += cnt[i];
        }
    if(num > 1) printf("0\n");
    else printf("%d\n", ans);
    return 0;
}