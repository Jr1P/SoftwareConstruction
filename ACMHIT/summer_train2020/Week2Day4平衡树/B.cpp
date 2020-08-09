// AC
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

} *nil = new Node(), *root = nil, *lnode, *rnode;

inline void maintain(Node *u) {
    if(u == nil) return ;
    u->sz = 1;
    u->sum = u->value;
    u->sz += u->ch[0]->sz;
    u->sz += u->ch[1]->sz;
    u->sum += u->ch[0]->sum + u->ch[1]->sum;
}

inline void pushdown(Node *u) {
    if(u->lazy) {
        for(int i = 0; i < 2; i++) {
            Node *v = u->ch[i];
            if(v == nil) continue;
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

Node* insert(Node *&u, Node *fa, int key) {
    if(u == nil) {
        u = new Node(key);
        u->fa = fa; u->ch[0] = u->ch[1] = nil; u->value = val;
        // if(fa != nil) fa->ch[u->key > fa->key] = u;
        splay(u, nil);
        return u;
    }
    pushdown(u);
    int d = u->cmp(key);
    insert(u->ch[d], u, key);
}

void pre(Node*u, int key) {
    if(u == nil) return ;
    int d = u->cmp(key);
    if(d == -1) {
        lnode = u;
        return ;
    }
    pushdown(u);
    if(d == 1) lnode = u;
    pre(u->ch[d], key);
}

void succ(Node*u, int key) {
    if(u == nil) return ;
    int d = u->cmp(key);
    if(d == -1) {
        rnode = u;
        return ;
    }
    pushdown(u);
    if(d == 0) rnode = u;
    succ(u->ch[d], key);
}

void del(int l, int r) {
    pre(root, l - 1); succ(root, r + 1);
    splay(lnode, nil); splay(rnode, root);
    delete rnode->ch[0];
    rnode->ch[0] = nil;
    maintain(rnode);
    splay(rnode, nil);
}

ll query(int l, int r) {
    pre(root, l - 1); succ(root, r + 1);
    splay(lnode, nil); splay(rnode, lnode);
    ll ans = rnode->ch[0]->sum;
    splay(rnode->ch[0], nil);
    return ans;
}

void modify(int l, int r, ll c) {
    pre(root, l - 1); succ(root, r + 1);
    splay(lnode, nil); splay(rnode, lnode);
    if(rnode->ch[0] != nil) {
        rnode->ch[0]->value += c;
        rnode->ch[0]->lazy += c;
        rnode->ch[0]->sum += c * rnode->ch[0]->sz;
    }
    maintain(rnode);
    splay(rnode->ch[0], nil);
}

int main() {
    int n;
    scanf("%d", &n);
    if(root != nil) {
        delete root;
        root = nil;
    }
    val = 0;
    insert(root, nil, -INF);
    insert(root, nil, INF);
    while(n--) {
        char ch[9];
        int key; ll c;
        scanf("%s%d%lld", ch, &key, &val);
        switch(ch[0]) {
            case 'I': insert(root, nil, key); break;
            case 'D': del(key, val); break;
            case 'M': scanf("%lld", &c); 
                modify(key, val, c); break;
            case 'Q': printf("%lld\n", query(key, val)); break;
        }
    }
    return 0;
}