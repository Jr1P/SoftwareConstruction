#include <cstdio>
#define N 100050
#define INF 2147483647

int n, root;
int ch[N][2], fa[N], sz[N], val[N], dup[N];

inline bool get(int x) {
    return ch[fa[x]][1] == x;
}

inline void pushup(int k) {
    if(k) {
        sz[k] = dup[k];
        if(ch[k][0]) sz[k] += sz[ch[k][0]];
        if(ch[k][1]) sz[k] += sz[ch[k][1]];
    }
}

int main() {
    return 0;
}