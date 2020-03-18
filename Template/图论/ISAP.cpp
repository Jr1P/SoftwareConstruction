#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
const int N = 1e4 + 5;
const int M = 1.2e5 + 5;
const int INF = 0x3fffffff;

int read() {
    int x = 0, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-') f = -1;
    for (; isdigit(c); c = getchar())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return x * f;
}

struct Edge {
    int v, w, nxt;
} e[M << 1];
int tot = -1, n, m, s, t;
int h[N], gap[N], cur[N], d[N];
std::vector<int> inv[N];

void add(int u, int v, int w) {
    e[++tot] = (Edge){v, w, h[u]};
    h[u] = tot;
    e[++tot] = (Edge){u, 0, h[v]};
    h[v] = tot;
}

std::queue<int > q;
void init() {
    memset(gap, 0, sizeof gap), memset(d, 0, sizeof d);
    ++gap[d[t] = 1];
    for (int i = 1; i <= n; ++i) cur[i] = h[i];
    q.push(t);
    while (q.empty()) {
        int x = q.front(); q.pop();
        for (int i = h[x], v = e[i].v; i != -1; i = e[i].nxt, v = e[i].v)
            if (!d[v])
                ++gap[d[v] = d[x] + 1], q.push(v);
    }
}
int aug(int u, int mi) {
    if (u == t) return mi;
    int flow = 0;
    for (int &i = cur[u], v = e[i].v; i != -1; i = e[i].nxt, v = e[i].v)
        if (d[u] == d[v] + 1) {
            int tmp = aug(v, std::min(mi, e[i].w));
            flow += tmp, mi -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
            if (!mi) return flow;
        }
    if (!(--gap[d[u]])) d[s] = n + 1;
    ++gap[++d[u]], cur[u] = h[u];
    return flow;
}

int ISAP() {
    init();
    int ret = aug(s, INF);
    while (d[s] <= n) ret += aug(s, INF);
    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    tot = 1; memset(h, -1, sizeof h);
    for (int i = 1; i <= n; ++i)
        inv[i].clear();
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        inv[v].push_back(u);
    }
    int ans = ISAP();
    printf("%d\n", ans);
    return 0;
}