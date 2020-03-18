#include <cstdio>
#include <algorithm>
#define N 200050

int m, n, k, t, cnt;
int a[N], head[N];

struct Edge {
    int nxt, v, w;
}e[N];

inline bool cmp(int a, int b) { return a > b; }
inline int max(int x, int y) { return x > y ? x : y; }

inline void add(int u, int v, int w) {
    e[++cnt].w = w;
    e[cnt].v = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

int main() {
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for(int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    std::sort(a+1, a+m+1, cmp);
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 1; i <= k; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    int left = 0, right = m, rs = 0;
    while(left < right) {
        int mid = (left+right) >> 1;
        int mi = a[mid], time = 0, now = 0;
        rs = 0;
        for(int i = 1; i <= n; i++) {
            now = i;
            for(int u = head[i]; u != -1; u = e[u].nxt) {
                int v = e[u].v;
                if(v > rs && mi < e[u].w)
                    now = max(now, v);
            }
            time += (now - i) << 1;
            time++;
            rs = max(now, rs);
        }
        time++;
        if(time <= t) left = mid;
        else right = mid - 1;
        if(left == right - 1)
            break;
    }
    int mi = a[right];
    int time = 0, now = 0;
    rs = 0;
    for(int i = 1; i <= n; i++) {
        now = i;
        for(int u = head[i]; u != -1; u = e[u].nxt) {
            int v = e[u].v;
            if(v > rs && mi < e[u].w)
                now = max(now, v);
        }
        time += (now - i) << 1;
        time++;
        rs = max(now, rs);
    }
    time++;

    if(time <= t) printf("%d\n", right);
    else printf("%d\n", left);
    return 0;
}