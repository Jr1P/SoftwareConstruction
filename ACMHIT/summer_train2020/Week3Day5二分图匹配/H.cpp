#include <cstdio>
#include <cstring>
#include <vector>
const int M = 505;

struct Point{
    int x, y;
};
struct Edge {
    int v, nxt;
}e[M*M];

struct Q {
    Point s, t;
    int time;
} query[M];

int t, n, car, cnt;
char ch[10];
int match[M<<1], head[M<<1];
bool check[M<<1];

inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}
inline int abs(int x) {return x>0?x:-x;}
inline int dis(Point a, Point b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

inline int calc(char *s) {
    int x = s[4]-'0';
    x += ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10;
    return x;
}

bool dfs(int u) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!check[v]) {
            check[v] = 1;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= n; i++) {
        memset(check, 0, sizeof(check));
        ans += dfs(i);
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", ch);
            query[i].time = calc(ch);
            scanf("%d%d%d%d", &query[i].s.x, &query[i].s.y, &query[i].t.x, &query[i].t.y);
        }
        for(int i = 2; i <= n; i++)
            for(int j = 1; j < i; j++)
                if(query[i].time-query[j].time > 
                    dis(query[j].s, query[j].t)+dis(query[j].t, query[i].s))
                    add(i, j+n);
        printf("%d\n", n-hungarian());
    }
    return 0;
}