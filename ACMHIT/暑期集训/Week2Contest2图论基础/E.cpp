#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff;
const int MAXN = 5000;
const int MAXM = 10050;
int n, m, p, t, cnt;
int head[MAXN], dis[MAXN], num[MAXN];
bool exist[MAXN], f = false;

struct EDGE {
	int w, next, v;
}e[MAXM];

queue<int> q;

inline void init() {
	cnt = 0; f = false;
	for(int i = 1; i <= n; i++)
		head[i] = -1;
}

inline void add(int u, int v, int w) {
	e[++cnt].w = w;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

bool SPFA(int s) {
	while(!q.empty()) q.pop();
    dis[s] = 0;
	exist[s] = true;
	q.push(s);
	int u;
	while(!q.empty()) {
		u = q.front();
		for(int i = head[u]; i != -1; i = e[i].next) {
			if(dis[e[i].v] > dis[u]+e[i].w) {
				dis[e[i].v] = dis[u] + e[i].w;
				if(!exist[e[i].v]) {
					q.push(e[i].v);
					exist[e[i].v] = true;
					if(++num[e[i].v] > n)
						return true;
				}
			}
		}
		exist[u] = false;
		q.pop();
	}
	return false;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &p);
		init();
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		} //有向图的输入
		for(int i = 1; i <= p; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, -w);
		} //有向图的输入
		for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                exist[j] = false;
                dis[j] = INF;
                num[j] = 0;
            }
            if(SPFA(i)) {
                f = true;
			    puts("YES");
                break;
            }
        }
        if(!f)
		    puts("NO");
	}
	return 0;
}