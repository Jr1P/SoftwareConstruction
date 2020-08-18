/***
 * @author Jr1preg
 * @date 2020-8-12
 * 边双连通分量缩点
 * */
#include <cstdio>
#include <cstring>
#define M 10050
#define N 5050

struct Edge{
    int v, next;
    bool cut;
}e[M<<1];

int tim, ans, n, m, cnt, top, sum;
int dfn[N], low[N], head[N], stack[N<<1], color[N], du[N];
bool instack[N];

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
    e[cnt].cut = false;
}

inline int min(int x, int y) {
    return x < y? x: y;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    instack[u] = true;
    stack[++top] = u;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            if(instack[v]) low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        instack[u] = false;
        while(stack[top] != u) {
            color[stack[top]] = sum;
            instack[stack[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; i++) {
            head[i] = -1;
            dfn[i] = low[i] = 0;
            color[i] = du[i] = 0;
            instack[i] = false;
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
        printf("%d\n", (res+1)/2);
    }
    return 0;
}