#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#define INF 0x3fffffff
const int N = 10050 * 2;
using namespace std;

struct Edge {
    int v, w;
    Edge() {}
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n, m, cnt;
int dis[N];
bool vis[N];
map<string, int> mm;
vector<Edge > g[N];

struct NODE {
	int u, dis;
	bool operator < (const NODE &a) const {
		return dis > a.dis;
	}
    NODE() {}
    NODE(int _u, int _dis) : u(_u), dis(_dis) {}
};

inline void init() {
    mm.clear();
    cnt = 1;
    for(int i = 0; i <= 2 * n; i++) {
        vis[i] = false;
        dis[i] = INF;
        g[i].clear();
    }
    dis[1] = 0;
}

void dijkstra() {
	priority_queue<NODE> q;
	while(!q.empty()) q.pop();
	q.push(NODE(1, 0));
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if(!vis[v] && dis[v] > dis[u] + g[u][i].w) {
				dis[v] = dis[u] + g[u][i].w;
				q.push(NODE(v, dis[v]));
			}
		}
	}
}

int main() {
    while(~scanf("%d", &n)) {
        int flag = 0;
        string str1, str2;
        init();
        if(n == -1) break;
        cin >> str1 >> str2;
        if(str1 == str2) {
            flag = 1;
        } else {
            mm.insert(make_pair(str1, 1));
            mm.insert(make_pair(str2, 2 * n));
        }
        for(int i = 1; i <= n; i++) {
            string ust, vst;
            int w;
            cin >> ust >> vst >> w;
            if(!mm.count(ust))
                mm.insert(make_pair(ust, ++cnt));
            if(!mm.count(vst))
                mm.insert(make_pair(vst, ++cnt));
            g[mm[ust]].push_back(Edge(mm[vst], w));
        }
        if(flag) {
            puts("0");
            continue;
        }
        dijkstra();
        if(dis[2 * n] == INF) puts("-1");
        else printf("%d\n", dis[2 * n]);
    }
    return 0;
}