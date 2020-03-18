/***
 * dfs序+线段树
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
typedef long long ll;
const int N = 1e5 + 5;
const ll INF = 1e18;

inline ll max(ll x, ll y) { return x > y ? x : y; }

struct Node {
    int l, r;
    ll ma, lazy;
    Node() {}
    Node(int l, int r, ll ma=0L, ll lazy=0L) : l(l), r(r), ma(ma), lazy(lazy) {}
}node[N << 2];

struct Edge {
    int v, nxt;
}e[N << 1];

int n, m, x, y, len, cnt;
int dfn[N], left[N], right[N], head[N];
ll sum[N], num[N], val, ans;
bool vis[N];

inline void init() {
    for(int i = 0; i < n; i++)
        head[i] = -1, vis[i] = 0;
    len = -1;
    cnt = val = 0;
}

inline void add(int u, int v) {
    e[cnt] = Edge{v, head[u]};
    head[u] = cnt++;
}

void dfs(int u) {
    vis[u] = 1;
    int x = len + 1;
    dfn[++len] = u;
    left[u] = len;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v]) {
            sum[v] += sum[u];
            dfs(v);
        }
    }
    right[u] = len;
}

inline void update(int k) {
    node[k].ma = max(node[ls].ma, node[rs].ma);
}

inline void push(int k) {
    if(node[k].lazy) {
        node[ls].lazy += node[k].lazy;
        node[rs].lazy += node[k].lazy;
        node[ls].ma += node[k].lazy;
        node[rs].ma += node[k].lazy;
        node[k].lazy = 0;
    }
}

void build(int l, int r, int k) {
    node[k] = Node(l, r);
    if(l == r) {
        node[k].ma = sum[dfn[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void change(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        node[k].lazy += val;
        node[k].ma += val;
        return ;
    }
    push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) change(ls);
    if(y > mid) change(rs);
    update(k);
}

void query(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        ans = max(ans, node[k].ma);
        return ;
    }
    push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        for(int i = 0; i < n; i++) 
            scanf("%lld", &sum[i]), num[i] = sum[i];
        dfs(0);
        build(0, n - 1, 1);
        printf("Case #%d:\n", ++kase);
        while(m--) {
            int type, a;
            scanf("%d%d", &type, &a);
            x = left[a]; y = right[a];
            if(type) {
                ans = -INF;
                query(1);
                printf("%lld\n", ans);
            }
            else {
                ll val1;
                scanf("%lld", &val1);
                val = val1 - num[a];
                change(1);
                num[a] = val1;
            }
        }
    }
    return 0;
}