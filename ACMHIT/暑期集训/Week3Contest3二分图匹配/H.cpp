#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define M 505

struct Point{
    int x, y;
};

struct Q{
    Point s, t;
    int time;
    bool operator < (const Q& rhs) const {
        return time < rhs.time;
    }
}query[M];

int t, n, car;
char ch[10];
int match[M<<1];
bool check[M<<1], flag[M];
vector<int > G[M];

inline int abs(int x) {
    return x>0?x:-x;
}

inline int dis(Point a, Point b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

inline int calc(char *s) {
    int x = s[4]-'0';
    x += ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10;
    return x;
}

bool dfs(int u) {
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!check[v]) {
            check[v] = 1;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                match[u] = v;
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
        if(match[i] == -1) {
            memset(check, 0, sizeof(check));
            if(dfs(i)) ans++;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++) {
            scanf("%s", ch);
            query[i].time = calc(ch);
            cin >> query[i].s.x >> query[i].s.y >> query[i].t.x >> query[i].t.y;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j < i ; j++) {
                if(query[i].time-query[j].time > dis(query[j].s, query[j].t)+dis(query[j].t, query[i].s)) {
                    G[i].push_back(j+n);
                }
            }
        }
        printf("%d\n", n-hungarian());
    }
    return 0;
}