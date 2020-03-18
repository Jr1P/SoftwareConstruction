#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

#define N 10250
#define M 120050
#define INF 0x7fffffff
//最坏情况下时间复杂度O(m*n^2)

struct Edge {
    int v, w, next;
}e[M<<1];

int n, m, cnt = -1, s, t;
int head[N], depth[N], cur[N];

inline int min(int x, int y) {
    return (x < y)? x: y;
}

inline int read() {
    int x = 0;
    char c = getchar();
    bool flag = 0;
    while(c < '0' || c > '9') {
   		if(c == '-')
   			flag = 1;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9') {
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return flag ? -x : x;
}


inline void add(int u, int v, int w) {
    e[++cnt].w = w;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool bfs(int s, int t) {
    for(int i = 0; i <= n; i++) depth[i] = -1;
    std::queue<int > q;
    q.push(s);
    depth[s] = 0;
    while(!q.empty()) {
        int now = q.front(), v;
        q.pop();
        for(int i = head[now]; i != -1; i = e[i].next) {
            v = e[i].v;
            if(depth[v] == -1 && e[i].w) {
                q.push(v);
                depth[v] = depth[now] + 1;
            }
        }
    }
    if(depth[t] == -1) return false;
    else return true;
}

int dfs(int u, int flow) {
    if(u == t) return flow;
    int v, nowflow, sumflow = 0; //nowflow为当前流的流量, sumflow为流量之和
    for(int& i = cur[u]; i != -1; i = e[i].next) {
        v = e[i].v;
        if(depth[v] == depth[u] + 1 && e[i].w) {
            nowflow = dfs(v, min(flow, e[i].w));
            flow -= nowflow;
            e[i].w -= nowflow;
            e[i ^ 1].w += nowflow;
            sumflow += nowflow;
            if(!flow) break;
        }
    }
    if(sumflow == 0) depth[u] = -1;
    return sumflow;
}

void Dinic() {
    int maxflow = 0;
    while(bfs(s, t)) {
        for(int i = 1; i <= n; i++)
            cur[i] = head[i];
        maxflow += dfs(s, INF);
    }
    printf("%d\n", maxflow);
}

int main() {
    memset(head, -1, sizeof(head));
    n = read(), m = read(), s = read(), t = read();
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, 0);
    }
    Dinic();
    return 0;
}
