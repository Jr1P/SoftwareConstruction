#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
const int N = 1005;
const int M = 1000050;

struct Node {
    int x, y, p;
    Node() {}
    Node(int _x, int _y, int _p) : x(_x), y(_y), p(_p) {}
}node[N];

struct Edge {
    int u, v;
    double dis;
    Edge() {}
    Edge(int _u, int _v, double _dis) : u(_u), v(_v), dis(_dis){}
} e[N * N >> 1];

int n, m;
int num[N], father[N];

inline double dist(Node a, Node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

inline int find(int x) {
	if (father[x] == x) return x;
	return father[x] = find(father[x]);
}

inline bool _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2) 
		return false;
	else
		father[f2] = f1;
	return true;
}

inline bool cmp(Edge a, Edge b) {
    return a.dis < b.dis;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        double MST = 0.0;
        int cnt = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            int x, y, p;
            father[i] = i;
            scanf("%d%d%d", &x, &y, &p);
            node[i] = Node(x, y, p);
        }
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                e[++cnt] = Edge(i, j, dist(node[i], node[j]));
        std::sort(e + 1, e + cnt + 1, cmp);
        int cc = 0;
        for(int i = 1; i <= cnt; i++)
            if(_union(e[i].u, e[i].v)) {
                num[++cc] = i;
                MST += e[i].dis;
                if(cc == n - 2) break;
            }
        for(int i = 1; i <= n; i++)
            father[i] = find(i);
        double ma = 0.0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++) {
                if(father[i] != father[j])
                    ma = std::max(ma, (double)(node[i].p + node[j].p) / MST);
            }
        printf("%.2f\n", ma);
    }
    return 0;
}