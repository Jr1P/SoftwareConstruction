#include <cstdio>
#include <unordered_map>
#include <set>
const int N = 1e5+500;
const int M = 1.4e6;
const int INF = __INT_MAX__;

struct Edge {
    int v, nxt, w;
} e[M];

int n, m, cnt = -1, s, t;
int head[N], q[N], dep[N], cur[N], cc[2000];
std::unordered_map<int , int> mp;

inline int min(int x, int y) { return x < y ? x : y; }
void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

bool bfs(int s, int t) {
    for(int i = 0; i <= n+m; i++) cur[i] = head[i], dep[i] = -1;
    cur[s] = head[s], cur[t] = head[t];
    int hd = 0, tp = 0;
    q[tp++] = s; dep[s] = 0; dep[t] = -1;
    while(hd != tp) {
        int u = q[hd++];
        for(int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(dep[v] == -1 && e[i].w) dep[q[tp++] = v] = dep[u]+1;
        }
    }
    return dep[t] != -1;
}

int dfs(int u, int flow) {
    if(u == t) return flow;
    int rem = flow;
    for(int &i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(e[i].w && dep[v] == dep[u]+1) {
            int c = dfs(v, min(rem, e[i].w));
            rem -= c;
            e[i].w -= c; e[i^1].w += c;
            if(!rem) break;
        }
    }
    if(rem == flow) dep[u] = -1;
    return flow-rem;
}

int Dinic() {
    int maxflow = 0;
    while(bfs(s, t)) maxflow += dfs(s, INF);
    return maxflow;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        mp.clear(); for(int i = 0; i <= min(n, 1999); i++) cc[i] = 0;
        cnt = -1;
        s = n+m+100, t = s+1;
        head[s] = head[t] = -1;
        int tot = 0;
        for(int j = 0; j < n; j++) {
            int id = 0;
            for(int i = 0; i < m; i++) {
                int tmp;
                scanf("%d", &tmp);
                if(tmp) id |= (1 << i);
            }
            if(!mp.count(id)) mp[id] = ++tot, cc[id] = 1;
            else cc[id]++;
        }
        for(int i = 0; i <= tot+m+1; i++) head[i] = -1;
        for(std::unordered_map<int, int >::iterator it = mp.begin(); it != mp.end(); it++) {
            int u = it->second, id = it->first, count = 1;
            int q = id;
            while(id) {
                if(id&1) add(u, tot+count, cc[q]), add(tot+count, u, 0);
                id >>= 1; count++;
            }
            add(s, u, cc[q]), add(u, s, 0);
        }  
        for(int i = 0; i < m; i++) {
            int a; scanf("%d", &a);
            add(i+1+tot, t, a); add(t, i+1+tot, a);
        }
        if(Dinic() == n) puts("YES");
        else puts("NO");
    }
    return 0;
}