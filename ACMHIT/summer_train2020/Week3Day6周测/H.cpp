#include <cstdio>
#include <cstring>
const int N = 1e5+5;

int n, m, cnt;
int head[N], du[N], rd[N], s[N];
struct Edge {
    int u, v, nxt, w;
}e[N<<1];

inline void add(int u, int v, int w) {
    e[++cnt] = (Edge){u, v, head[u], w};
    head[u] = cnt;
}

bool check(int ans) {
    int q[N], hd = 0, tp = 0, tot = 0;
    for(int i = 1; i <= n; i++) rd[i] = du[i];
    for(int i = 1; i <= cnt; i++)
        if(e[i].w <= ans)
            rd[e[i].v]--;
    for(int i = 1; i <= n; i++)
        if(!rd[i]) {
            q[tp++] = i;
            s[i] = ++tot;
        }
    while(hd != tp) {
        int u = q[hd++];
        for(int i = head[u]; i != -1; i = e[i].nxt)
            if(e[i].w > ans) {
                rd[e[i].v]--;
                if(!rd[e[i].v]) {
                    q[tp++] = e[i].v;
                    s[e[i].v] = ++tot;
                }
            }
    }
    for(int i = 1; i <= n; i++) if(rd[i]) return false;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++) head[i] = -1;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); du[v]++;
    }
    int l = 0, r = 1e9+1, ans;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(check(mid)) {
            r = mid-1;
            ans = mid;
        } else l = mid+1;
    }
    check(ans);
    int count = 0, ae[N];
    for(int i = 1; i <= cnt; i++)
        if(e[i].w <= ans && s[e[i].u] > s[e[i].v]) {
            count++;
            ae[count] = i;
        }
    printf("%d %d\n", ans, count);
    for(int i = 1; i <= count; i++)
        printf("%d ", ae[i]);
    return 0;
}