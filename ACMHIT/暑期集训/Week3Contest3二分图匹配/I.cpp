#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10000
#define N 1010500

struct zb{
    int a, b;
}q[N];

struct Edge{
    int v, next;
}e[N<<1];

int n, ma, cnt, t = 0;
int match[N<<1], head[N<<1];
int state[N<<1];
//bool check[N<<1];

inline int read() {// 读入优化
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

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

bool dfs(int u) {
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (state[v] == t)
            continue;
        state[v] = t;
        if (match[v] == -1 || dfs(match[v])) { 
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    t = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= ma; i++) {
        if(match[i] == -1) {
            ++t;    
            if(dfs(i)) ans++;
            else break; 
        }
    }
    return ans;
}

int main() {
    n = read();
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++) {
        q[i].a = read();
        q[i].b = read();
        add(q[i].a, i+n);
        add(q[i].b, i+n);
        ma = ma<q[i].a?q[i].a:ma;
        ma = ma<q[i].b?q[i].b:ma;
    }
    printf("%d\n", hungarian());
    return 0;
}