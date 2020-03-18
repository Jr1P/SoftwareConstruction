#include <cstdio>
#include <vector>
const int N = 2e6 + 5;

std::vector<int > g[N];

int n, m, tim, num, top;
int low[N], dfn[N], color[N], stk[N];
bool instk[N];

inline int min(int x, int y) { return x < y ? x : y; }

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    stk[++top] = u; instk[u] = true;
    for(int v : g[u]) {
        if(!dfn[v])
            tarjan(v), low[u] = min(low[u], low[v]);
        else if(instk[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        ++num;
        do {
            color[u] = num;
            u = stk[top--];
            instk[u] = false;
        } while(dfn[u] != low[u]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    while(m--) {
        int a, b, va, vb;
        scanf("%d%d%d%d", &a, &va, &b, &vb);
        g[a + n * (va & 1)].push_back(b + n * (vb ^ 1));
        g[b + n * (vb & 1)].push_back(a + n * (va ^ 1));
    }
    for(int i = 1; i <= (n << 1); i++)
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; i++)
        if(color[i] == color[i + n]) {
            puts("IMPOSSIBLE");
            return 0;
        }
    puts("POSSIBLE");
    for(int i = 1; i <= n; i++)
        printf("%d ", color[i] < color[i + n]);
    return 0;
}