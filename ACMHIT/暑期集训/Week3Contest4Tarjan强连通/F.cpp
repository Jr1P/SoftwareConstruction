#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define N 5050

vector<int > G[N];
set<int > S[N];
int dfn[N], low[N], color[N], du[N], stack[N<<1], ans[N];
bool instack[N];
int tim, n, m, sum, top, tot;

inline void init() {
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        S[i].clear();
        dfn[i] = low[i] = 0;
        du[i] = ans[i] = 0;
    }
    tim = sum = top = tot = 0;
    memset(stack, 0, sizeof(stack));
}

inline int min(int x, int y) {
    return x<y?x:y;
}

int tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    instack[u] = true;
    stack[++top] = u;
    int sz = G[u].size();
    for(int i = 0; i < sz; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        S[sum].insert(u);
        instack[u] = false;
        while(stack[top] != u) {
            S[sum].insert(stack[top]);
            color[stack[top]] = sum;
            instack[stack[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        init();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i);
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < G[i].size(); j++) {
                int v = G[i][j];
                if(color[i] != color[v]) {
                    du[color[i]]++;
                }
            }
        }
        for(int i = 1; i <= sum; i++) {
            if(du[i] == 0) {
                for(set<int>::iterator it = S[i].begin(); it != S[i].end(); it++) {
                    ans[++tot] = *it;
                }
            }
        }
        sort(ans+1, ans+tot+1);
        for(int i = 1; i < tot; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[tot]);
    }
    return 0;
}