#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 2000
#define INF 0x7fffffff

struct Edge {
    int u, v, w, next;
}e[N<<1], e2[N<<1];

int n, m, cnt, ecnt, ans;
int s1, s2, t1, t2;
int head[N], dis1[N], dis2[N], dis[N];
bool exist[N];

inline void add(int u, int v, int w) {
    e[++cnt].v = v;
    e[cnt].u = u;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void add2(int u, int v, int w) {
    e2[++ecnt].v = v;
    e2[ecnt].u = u;
    e2[ecnt].w = w;
    e2[ecnt].next = head[u];
    head[u] = ecnt;
}

queue<int > q;

void spfa(int s, int dis[]) {
    while(!q.empty()) q.pop();
    q.push(s);
    exist[s] = true;
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(dis[u]+e[i].w < dis[v]) {
                dis[v] = dis[u]+e[i].w;
                if(!exist[v]) {
                    q.push(v);
                    exist[v] = true;
                }
            }
        }
        q.pop();
        exist[u] = false;
    }
}

void spfa2(int s) {
    while(!q.empty()) q.pop();
    q.push(s);
    exist[s] = true;
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        for(int i = head[u]; i != -1; i = e2[i].next) {
            int v = e2[i].v;
            if(dis[u]+e2[i].w > dis[v]) {
                dis[v] = dis[u]+e2[i].w;
                if(dis[v] > ans) ans = dis[v];
                if(!exist[v]) {
                    q.push(v);
                    exist[v] = true;
                }
            }
        }
        q.pop();
        exist[u] = false;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
    for(int i = 1; i <= n; i++) {
        head[i] = -1;
        dis1[i] = dis2[i] = INF;
    }
    for(int i = 1; i <= n; i++) {
        int  u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    spfa(s1, dis1);
    memset(exist, false, sizeof exist);
    spfa(s2, dis2);
    for(int i = 1; i <= n; i++)
        head[i] = -1;
    for(int i = 1; i <= cnt; i++) {
        int u = e[i].u, v = e[i].v;
        if(dis1[u]+e[i].w == dis2[v]) {
            add(u, v, e[i].w);
            add(v, u, e[i].w);
        }
    }
    int s = e2[ecnt].v;
    spfa2(s);
    printf("%d\n", ans);
    return 0;
}