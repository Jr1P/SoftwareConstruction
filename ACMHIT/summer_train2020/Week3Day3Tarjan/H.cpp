#include <iostream>
#include <cstdio>
const int N = 3e5+10;

int x, y, ans, val, cnt, n, m;
int l[2][N], r[2][N], dfn[2][N], head[N], len[2], a[N];
int c[2][N], di[N];
bool vis[N], atOdd[N];

struct Edge {
    int v, nxt;
}e[N<<1];

inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

inline int lowbit(int x) { return x&(-x); }
inline void modify(int x, int val, int k) {
    for(int i = x; i <= len[k]; i += lowbit(i))
        c[k][i] += val;
}
inline int sum(int x, int k) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[k][i];
    return ans;
}

void dfs(int u, int fa, int k) {
    atOdd[u] = k == 1;
    dfn[k][++len[k]] = u;
    l[k][u] = len[k];
    if(!l[k][fa]) l[k][fa] = len[k];
    di[u] = a[u]-a[dfn[k][len[k]-1]];
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v != fa) dfs(v, u, k^1);
    }
    r[k][fa] = len[k];
    r[k][u] = len[k];
}

int main() {
	scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs(1, 0, 1);
    for(int i = 1; i <= n; i++) modify(l[atOdd[i]][i], di[i], atOdd[i]);
	while (m--) {
	    int a, q;
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d%d", &a, &val);
            int d = atOdd[a];
            x = l[d][a], y = r[d][a];
            modify(x, val, d), modify(y+1, -val, d);
            x = l[d^1][a], y  = r[d^1][a];
            if(x) modify(x, -val, d^1), modify(y+1, val, d^1);
		} else {
			ans = 0;
            scanf("%d", &x);
            printf("%d\n", sum(l[atOdd[x]][x], atOdd[x]));
		}
	}
	return 0;
}
