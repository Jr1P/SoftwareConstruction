#include <cstdio>
#include <queue>
const int INF = 0x3fffffff;
const int N = 1000;
const int M = 5000;

int n, m, Q, cnt;
int head[N], dis[N], num[N];
bool exist[N];

struct Edge {
    int v, nxt, w;
}e[M<<1];

inline void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

void init() {
    for(int i = 0; i <= n; i++) {
        dis[i] = INF;
        head[i] = -1;
        exist[i] = false;
        num[i] = 0;
    }
    cnt = 0;
}

std::queue<int >q;

bool spfa(int s) {
    while(!q.empty()) q.pop();
    dis[s] = 0; exist[s] = true;
    q.push(s);
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i = head[now]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(dis[now]+e[i].w < dis[v]) {
                dis[v] = dis[now]+e[i].w;
                if(!exist[v]) {
					q.push(v);
					exist[v] = true;
					if(++num[v] >= n) return true;
				}
            }
        }
        exist[now] = false;
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &Q);
        init();
        int u, v, w;
        bool f = false;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        for(int i = 1; i <= Q; i++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, -w);
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                exist[j] = false;
                dis[j] = INF; num[j] = 0;
            }
            if(spfa(i)) {
                f = true;
                puts("YES");
                break;
            }
        }
        if(!f) puts("NO");
    }
    return 0;
}