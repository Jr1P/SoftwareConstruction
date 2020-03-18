#include <cstdio>
#include <algorithm>
#define N 10050
#define M 50050
#define Q 10050
using namespace std;

int n, m, q, l, sum;
int father[N], sz[N], ans[N];
struct Edge {
    int u, v, w;
    bool operator < (const Edge& rhs) const {
        return w < rhs.w;
    }
}e[M];

struct Query {
    int id, l;
    bool operator < (const Query& rhs) const {
        return l < rhs.l;
    }
}query[Q];

inline int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(find(father[x]));
}

inline void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 == f2) return ;
    sum += sz[f1]*sz[f2];
    if(f1 > f2) {
        father[f1] = f2;
        sz[f2] += sz[f1];
    } else {
        father[f2] = f1;
        sz[f1] += sz[f2];
    }
    return ;
}

int main() {
    while(scanf("%d%d%d", &n, &m, &q) != EOF) {
        for(int i = 1; i <= n; i++) {
            father[i] = i;
            sz[i] = 1;
        }
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        for(int i = 1; i <= q; i++) {
            scanf("%d", &l);
            query[i].id = i;
            query[i].l = l;
        }
        sort(e+1, e+m+1);
        sort(query+1, query+q+1);
        sum = 0;
        int cnt = 1;
        for(int i = 1 ;i <= q; i++) {
            while(cnt <= m && e[cnt].w <= query[i].l) {
                _union(e[cnt].u, e[cnt].v);
                 cnt++;
            }
            ans[query[i].id] = sum;
        }
        for(int i = 1; i <= q; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}