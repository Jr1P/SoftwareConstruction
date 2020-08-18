#include <cstdio>
const int INF = 0x3f3f3f3f;
const int N = 2e5+5;

struct Edge {
    int v, nxt, odd;
}e[N<<1];

int head[N], n, cnt=-1;
int dp1[N], dp2[N];

void add(int u, int v, int odd) {
    e[++cnt] = (Edge){v, head[u], odd};
    head[u] = cnt;
}

void dfs1(int u, int fa) {
    dp1[u] = 0;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        dp1[u] += dp1[v]+e[i].odd;
    }
}

void dfs2(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa) continue;
        dp2[v] = dp1[u]-dp1[v]-e[i].odd+dp2[u]+(e[i].odd^1);
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) head[i] = -1;
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v, 0); add(v, u, 1);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int mim = INF;
    for(int i = 1; i <= n; i++) {
        dp1[i] += dp2[i];
        if(dp1[i] < mim) mim = dp1[i];
    }
    printf("%d\n", mim);
    for(int i = 1; i <= n; i++)
        if(dp1[i] == mim) printf("%d ", i);
    return 0;
}