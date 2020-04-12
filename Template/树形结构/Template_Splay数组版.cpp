#include <cstdio>
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define isRight(x) (rs(fa[(x)]) == (x)) // 返回是否为右儿子

const int N = 1e5 + 5;
int siz, rt; // rt根节点, siz为当前节点个数
int sz[N], dup[N], ch[N][2], key[N], fa[N]; // sz 为子树大小，不包括自身

inline void clear(int x) { 
    sz[x] = dup[x] = key[x] = fa[x] = ch[x][0] = ch[x][1] = 0;
}

inline void update(int x) { // 更新节点大小
    if(!x) return ;
    sz[x] = dup[x];
    if(ls(x)) sz[x] += sz[ls(x)];
    if(rs(x)) sz[x] += sz[rs(x)];
}

inline void connect(int x, int f, int r) { // 将father的r儿子设为x
    fa[x] = f;
    ch[f][r] = x; 
}

void rotate(int x) { // 旋转, f-father, gfa-grandpa
    int left = isRight(x), fleft = isRight(fa[x]), f = fa[x], gfa = fa[fa[x]];
    connect(ch[x][left ^ 1], f, left);
    connect(f, x, left ^ 1);
    connect(x, gfa, fleft);
    update(f); update(x);
}

void splay(int x) { // 把x旋转到根, 要转到特定位置稍微改改
    for(int f; f = fa[x]; rotate(x))
        if(fa[f]) rotate(isRight(x) == isRight(f) ? f : x);
    rt = x;
}

int queryRank(int x) { // 根据关键字值查询排名
    int ans = 0, now = rt;
    while(1) {
        if(x < key[now])
            now = ls(now);
        else if(x > key[now]) {
            ans += sz[ls(now)] + dup[now];
            now = rs(now);
        } else {
            ans += sz[ls(now)] + 1;
            splay(now);
            return ans;
        }
    }
}

int queryKey(int rank) { // k-th number
    int now = rt;
    while(1) {
        if(rank <= sz[ls(now)])
            now = ls(now);
        else if(rank <= sz[ls(now)] + dup[now]) {
            splay(now);
            return key[now];
        } else {
            rank -= sz[ls(now)] + dup[now];
            now = rs(now);
        }
    }
}

void insert(int x) { // 插入关键字x, 返回插入节点编号
    if(!rt) { // 树中还没有节点
        rt = ++siz;
        key[rt] = x;
        sz[rt] = dup[rt] = 1;
        ch[rt][0] = ch[rt][1] = 0;
        update(fa[rt]);
        return ;
    }
    int now = rt, f = 0;
    while(1) {
        if(key[now] == x) {
            dup[now]++;
            update(now); update(f);
            splay(now);
            return ;
        }
        f = now; now = ch[now][x > key[now]];
        if(!now) { // 还没有叶子
            key[++siz] = x;
            sz[siz] = dup[siz] = 1;
            fa[siz] = f;
            ch[f][x > key[f]] = siz;
            update(f);
            splay(siz);
            return ;
        }
    }
}

int pre() {
    int now = ls(rt);
    while(rs(now)) now = rs(now);
    return now;
}

int succ() {
    int now = rs(rt);
    while(ls(now)) now = ls(now);
    return now;
}

void del(int x) { // 删除关键字 x
    queryRank(x);
    if(dup[rt] > 1) {
        dup[rt]--;
        update(rt);
        return ;
    } else if(!ls(rt) && !rs(rt)) {
        clear(rt);
        rt = 0;
        return ;
    } else if(!rs(rt)) {
        int tmp = rt;
        fa[rt = ls(rt)] = 0;
        clear(tmp);
        return ;
    } else if(!ls(rt)) {
        int tmp = rt;
        fa[rt = rs(rt)] = 0;
        clear(tmp);
        return ;
    }
    int tmp = rt, left = pre();
    splay(left);
    connect(rs(tmp), rt, 1);
    clear(tmp);
    update(rt);
}

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int op, x;
        scanf("%d%d", &op, &x);
        switch (op) {
        case 1: // insert
            insert(x);
            break;
        case 2: // del
            del(x);
            break;
        case 3: // query Rank of x
            printf("%d\n", queryRank(x));
            break;
        case 4: // query key of rank x
            printf("%d\n", queryKey(x));
            break;
        case 5: // x pre
            insert(x); printf("%d\n", key[pre()]); del(x);
            break;
        case 6: // x succ
            insert(x); printf("%d\n", key[succ()]); del(x);
            break;
        }
    }
    return 0;
}