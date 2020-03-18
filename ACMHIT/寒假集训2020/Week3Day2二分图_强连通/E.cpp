#include <cstdio>
#include <cstring>

const int M = 10050, N = 5050;

struct Edge{
    int v, next;
}e[M << 1];

int tim, ans, n, m, cnt, top, sum;
int dfn[N], low[N], head[N], stack[N << 1], color[N], du[N];
bool exist[N];

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline int min(int x, int y) { return x < y? x: y; }

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    exist[u] = true;
    stack[++top] = u;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if(exist[v])
                low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        exist[u] = false;
        while(stack[top] != u) {
            color[stack[top]] = sum;
            exist[stack[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            head[i] = -1;
            dfn[i] = low[i] = color[i] = du[i] = 0;
            exist[i] = false;
        }
        memset(stack, 0, sizeof(stack));
        sum = cnt = tim = top = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        for(int i = 1; i <= n; i++)
            if(!dfn[i]) tarjan(i, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = head[i]; j != -1; j = e[j].next) {
                int v = e[j].v;
                if(color[i] != color[v])
                    du[color[i]]++;
            }
        }
        int res = 0;
        for(int i = 1; i <= sum; i++)
            if(du[i] == 1) res++;
        printf("%d\n", (res + 1) / 2);
    }
    return 0;
}