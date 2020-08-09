#include <cstdio>
#include <cstring>
const int SZ = 32;
const int N = 1e5+5;

int n, cnt, head[N], tot;
int xo[N], trie[N*64][2];
bool vis[N];

struct Edge {
    int v, nxt, w;
    Edge() {}
    Edge(int v, int nxt, int w) : v(v), nxt(nxt), w(w) {}
}e[N << 1];

inline int max(int x, int y) { return x > y ? x : y; }

void init() {
    for(int i = 0; i <= n; i++)
        head[i] = -1, vis[i] = false;
    cnt = tot = 0;
}

inline void add(int u, int v, int w) {
    e[++cnt] = Edge(v, head[u], w);
    head[u] = cnt;
}

void dfs(int u, int x) {
    xo[u] = x;
    vis[u] = true;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v])
            dfs(v, x ^ e[i].w);
    }
}

void insert(int a, int root = 0) {
	for(int i = 31; i >= 0; i--) {
		int v = (a >> i) & 1;
		if(!trie[root][v]) {
			trie[root][v] = ++tot;
            trie[tot][0] = 0;
            trie[tot][1] = 0;
        }
		root = trie[root][v];
	}
}

int query(int x, int root = 0) {
    int num = 0;
	for(int i = 31; i >= 0; i--) {
		int v = (x >> i) & 1;
		if(trie[root][v ^ 1])
			root = trie[root][v ^ 1],
            num |= (1 << i);
		else root = trie[root][v];
	}
	return num;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        dfs(0, 0);
        trie[0][0] = trie[0][1] = 0;
        // for(int i = 0; i < n; i++) printf("%d\n", xo[i]);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, query(xo[i]));
            insert(xo[i]);
        }
        printf("%d\n", ans);
    }

    return 0;
}