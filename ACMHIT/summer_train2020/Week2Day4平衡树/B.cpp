#include <cstdio>
const int INF = 0x3f3f3f3f;
typedef long long ll;

ll val;

struct Node {
    int key, sz;
    ll lazy, sum, value;
    Node *ch[2], *fa;

    Node() { key = sz = lazy = sum = 0; }
    Node(int key) : key(key) { sz = 1; lazy = sum = 0; }

    inline int isRight() { return fa->ch[1] == this; }
    inline int cmp(int key) { return key == this->key ? -1 : key > this->key; }

} *nil = new Node(), *root = nil, *inf, *minf;

inline bool isLeaf(Node *u) {
    return (u->ch[0] == nil || u->ch[0] == minf) ? 
        (u->ch[1] == nil || u->ch[1] == inf) : false;
}

inline void maintain(Node *u) {
    if(u == nil || u == inf || u == minf) return ;
    u->sz = 1;
    u->sz += u->ch[0]->sz;
    u->sz += u->ch[1]->sz;
    if(u->lazy) return ;
    u->sum = u->value;
    u->sum += u->ch[0]->sum + u->ch[1]->sum;
}

inline void pushdown(Node *u) {
    if(u->lazy) {
        for(int i = 0; i < 2; i++) {
            Node *v = u->ch[i];
            if(v == nil || v == inf || v == minf) continue;
            v->lazy += u->lazy;
            v->value += u->lazy;
            v->sum += u->lazy * v->sz;
        }
        u->lazy = 0;
    }
}

void rot(Node *u) {
    Node *f = u->fa, *gf = f->fa;
    int d = u->isRight();
    pushdown(f), pushdown(u);
    if((f->ch[d] = u->ch[d ^ 1]) != nil) f->ch[d]->fa = f;
    if((u->fa = gf) != nil) gf->ch[f->isRight()] = u;
    f->fa = u;
    u->ch[d ^ 1] = f;
    maintain(f), maintain(u);
}

void splay(Node *u, Node *target) {
    for(Node *f; u->fa != target; rot(u))
        if((f = u->fa)->fa != target)
            rot(u->isRight() == f->isRight() ? f : u);
    if(target == nil) root = u;
}

Node* insert(Node *u, Node *fa, int key) {
    if(u == nil) {
        u = new Node(key);
        u->fa = fa; u->ch[0] = u->ch[1] = nil; u->value = val;
        if(fa != nil) fa->ch[u->key > fa->key] = u;
        maintain(fa);
        splay(u, nil);
        return u;
    }
    pushdown(u);
    int d = u->cmp(key);
    insert(u->ch[d], u, key);
}

Node* locate(Node*u, int x) {
    int d = u->cmp(x);
    if(d == -1) return u;
    return u->ch[d] == nil ? u: locate(u->ch[d], x);
}

void del(int l, int r) {
    Node *le = locate(root, l - 1), *ri = locate(root, r + 1);
    splay(le, nil);
    splay(ri, root);
    delete ri->ch[0];
    ri->ch[0] = nil;
    maintain(ri);
    splay(ri, nil);
    if(inf->ch[0] != nil) splay(inf->ch[0], nil);
    if(minf->ch[1] != nil) splay(minf->ch[1], nil);
}

int queryRank(Node *u, int key) { // 根据关键字值查询排名
    int d = u->cmp(key);
    if(d == -1) {
        splay(u, nil);
        return u->ch[0]->sz + 1;
    }
    return queryRank(u->ch[d], key);
}

inline Node* pre() { // 前驱
    Node* now = root->ch[0];
    while(now->ch[1] != nil) now = now->ch[1];
    return now;
}

void del(int key) {
    queryRank(root, key);
    if(root->ch[0] == nil && root->ch[1] == nil) {
        delete root;
        root = nil;
        return ;
    } else if(root->ch[0] == nil) {
        Node* tmp = root;
        (root = root->ch[1])->fa = nil;
        delete tmp;
        return ;
    } else if(root->ch[1] == nil) {
        Node* tmp = root;
        (root = root->ch[0])->fa = nil;
        delete tmp;
        return ;
    }
    Node* tmp = root, *l = pre();
    splay(l, nil);
    root->ch[1] = tmp->ch[1];
    tmp->ch[1]->fa = root;
    delete tmp;
    maintain(root);
}

ll query(int l, int r) {
    Node *le = locate(root, l - 1), *ri = locate(root, r + 1);
    splay(le, nil);
    splay(ri, le);
    ll ans = ri->ch[0]->sum;
    if(inf->ch[0] != nil) splay(inf->ch[0], nil);
    if(minf->ch[1] != nil) splay(minf->ch[1], nil);
    return ans;
}

void modify(int l, int r, ll c) {
    Node *le = locate(root, l - 1), *ri = locate(root, r + 1);
    splay(le, nil);
    splay(ri, le);
    ri->ch[0]->value += c;
    ri->ch[0]->lazy += c;
    ri->ch[0]->sum += c * ri->ch[0]->sz;
    maintain(ri);
    splay(ri->ch[0], nil);
    if(inf->ch[0] != nil) splay(inf->ch[0], nil);
    if(minf->ch[1] != nil) splay(minf->ch[1], nil);
}

int main() {
    int n;
    while(~scanf("%d", &n)) {
        if(root != nil) {
            delete root;
            root = nil;
        }
        (minf = insert(root, nil, -INF))->sz = 0;
        (inf = insert(root, nil, INF))->sz = 0;
        while(n--) {
            char ch[9];
            int x; ll c;
            scanf("%s%d%lld", ch, &x, &val);
            switch(ch[0]) {
                case 'I': insert(root, nil, x); break;
                case 'D': del(x, val); break;
                case 'M': scanf("%lld", &c); 
                    modify(x, val, c); break;
                case 'Q': printf("%lld\n", query(x, val)); break;
            }
        }
    }
    return 0;
}