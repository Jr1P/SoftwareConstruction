/**
 * @test luogu3376
 * @param 86ms
 * @result AC
 * @a n <= 200, m <= 5000
 * */
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int N = 1025;
const int M = 12005;
const int INF = __INT_MAX__;

struct Edge {
    int v, next, w;
}e[M<<1];

int n, m, cnt = -1, s, t;
int head[N], depth[N], cur[N], q[N];

inline int min(int x, int y) { return x < y ? x : y; }

inline int read() {
    int x = 0;
    char c = getchar();
    bool flag = 0;
    while(c < '0' || c > '9') {
   		if(c == '-') flag = 1;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9') {
    	x = (x<<3)+(x<<1)+(c^48);
    	c = getchar();
    }
    return flag ? -x : x;
}

inline void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

bool bfs(int s, int t) {
    for(int i = 0; i <= n; i++) depth[i] = -1, cur[i] = head[i];
    int hd = 0, tp = 0;
    q[tp++] = s;
    depth[s] = 0;
    while(hd != tp) {
        int u = q[hd++], v;
        for(int i = head[u]; i != -1; i = e[i].next) {
            v = e[i].v;
            if(depth[v] == -1 && e[i].w) {
                q[tp++] = v;
                depth[v] = depth[u]+1;
            }
        }
    }
    return depth[t] != -1;
}

int dfs(int u, int flow) {
    if(u == t) return flow;
    int rem = flow; // rem为当前剩余流量
    for(int& i = cur[u]; i != -1; i = e[i].next) { // 注意i是引用，当前弧优化
        int v = e[i].v;
        if(depth[v] == depth[u]+1 && e[i].w) {
            int c = dfs(v, min(rem, e[i].w));
            rem -= c;
            e[i].w -= c;
            e[i^1].w += c;
            if(!rem) break;
        }
    }
    if(rem == flow) depth[u] = -1; // 没有增广成功
    return flow-rem;
}

ll Dinic() {
    ll maxflow = 0;
    while(bfs(s, t)) maxflow += dfs(s, INF);
    return maxflow;
}

int main() {
    n = read(), m = read(), s = read(), t = read();
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w); add(v, u, 0);
    }
    printf("%lld\n", Dinic());
    return 0;
}
