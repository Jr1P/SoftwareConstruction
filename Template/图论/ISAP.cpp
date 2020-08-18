// AC
#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
typedef long long ll;
const int N = 1e4+5;
const int M = 1.2e5+5;
const int INF = 0x3fffffff;

int read() {
    int x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-') f = -1;
    for (; isdigit(c); c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return x*f;
}

inline int min(int x, int y) { return x < y ? x : y; }

struct Edge {
    int v, w, nxt;
} e[M << 1];
int tot = -1, n, m, s, t;
int h[N], gap[N], cur[N], d[N], q[N];
std::vector<int> inv[N];

void add(int u, int v, int w) {
    e[++tot] = (Edge){v, w, h[u]};
    h[u] = tot;
    e[++tot] = (Edge){u, 0, h[v]};
    h[v] = tot;
}

void init() {
    for(int i = 1; i <= n; ++i) cur[i] = h[i], gap[i] = d[i] = 0;
    ++gap[d[t] = 1];
    int hd = 0, tp = 0;
    q[tp++] = t;
    while (hd != tp) {
        int x = q[hd++];
        for (int i = h[x], v = e[i].v; i != -1; i = e[i].nxt, v = e[i].v)
            if (!d[v]) ++gap[d[v] = d[x]+1], q[tp++] = v;
    }
}
int aug(int u, int mi) {
    if (u == t) return mi;
    int flow = 0;
    for (int &i = cur[u], v = e[i].v; i != -1; i = e[i].nxt, v = e[i].v)
        if (d[u] == d[v] + 1) {
            int tmp = aug(v, min(mi, e[i].w));
            flow += tmp, mi -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
            if (!mi) return flow;
        }
    if (!(--gap[d[u]])) d[s] = n + 1;
    ++gap[++d[u]], cur[u] = h[u];
    return flow;
}

ll ISAP() {
    init();
    ll ret = aug(s, INF);
    while (d[s] <= n) ret += aug(s, INF);
    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    tot = 1;
    for(int i = 1; i <= n; i++) h[i] = -1;
    for (int i = 1; i <= n; ++i) inv[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        inv[v].push_back(u);
    }
    ll ans = ISAP();
    printf("%lld\n", ans);
    return 0;
}