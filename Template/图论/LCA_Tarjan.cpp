// tarjan
#include <cstdio>
using namespace std;
#define N 500050

struct Edge {
    int v, next;
}e[N<<1];

struct Query {
    int id, p, next;
}query[N<<1];

int qhead[N], head[N], fa[N], ans[N];
int n, m, s, a, b, cnt, cnt2;
bool vis[N], arr[N];

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9') {
        x = (x<<3)+(x<<1)+(c^48);
        c = getchar();
    }
    return x;
}

inline void init() {
    for(int i = 1; i <= n; i++) {
        head[i] = qhead[i] = -1;
        fa[i] = i;
        vis[i] = arr[i] = false;
        ans[i] = 0;
    }
}

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void addq(int u, int v) {
    query[++cnt2].p = v;
    query[cnt2].next = qhead[u];
    qhead[u] = cnt2;
}

inline int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 == f2)
        return ;
    fa[f2] = f1;
}

void tarjan(int u) {
    arr[u] = true;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v] && !arr[v]) {
            tarjan(v);
            _union(u, v);
            vis[v] = true;
        }
    }
    vis[u] = true;
    for(int i = qhead[u]; i != -1; i = query[i].next) {
        int v = query[i].p;
        if(vis[v]) 
            ans[query[i].id] = find(v);
    }
}

int main() {
    n = read(); m = read(); s = read();
    init();
    for(int i = 1; i < n; i++) {
        int u, v;
        u = read(); v = read();
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        a = read(); b = read();
        addq(a, b);
        query[cnt2].id = i;
        addq(b, a);
        query[cnt2].id = i;
    }
    tarjan(s);
    for(int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}