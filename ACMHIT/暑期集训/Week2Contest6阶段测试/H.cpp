#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050
#define INF 0x7fffffff

int n, k, tot = 0, root = 0;
int val[N], ch[N][2], cnt[N], sz[N], dat[N];

inline int Rand() {
    static int seed = 703;
    return seed = int(seed*48271LL%(~0u>>1));
}

inline int New(int v) {
    val[++tot] = v;
    sz[tot] = 1;
    dat[tot] = Rand();
    cnt[tot] = 1;
    return tot;
}

inline void pushup(int id) {
    sz[id] = sz[ch[id][0]]+sz[ch[id][1]]+cnt[id];
}

inline void rotate(int &id, int d) {
    int temp = ch[id][d^1];
    ch[id][d^1] = ch[temp][d];
    ch[temp][d] = id;
    id = temp;
    pushup(ch[id][d]);
    pushup(id);
}

inline void insert(int &id, int v) {
    if(!id) {
        id = New(v);
        return ;
    }
    if(v == val[id]) {
        //cnt[id]++;
        return ;
    } else {
        int d = (v < val[id]? 0: 1);
        insert(ch[id][d], v);
        if(dat[id] < dat[ch[id][d]])
            rotate(id, d^1);
    }
    pushup(id);
}

inline int get_rank(int id, int v) {
    if(!id) return -1;
    if(v == val[id])
        return sz[ch[id][0]]+1;
    else if(v < val[id])
        return get_rank(ch[id][0], v);
    else
        return sz[ch[id][0]]+cnt[id]+get_rank(ch[id][1], v);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        insert(root, k);
        printf("%d\n", get_rank(root, k));
    }
    return 0;
}