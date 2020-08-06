// luogu3369 AC板子
#include <cstdio>

struct Node {
    int sz, dup, key;
    Node* ch[2], *fa;

    Node() { key = sz = dup = 0; }
    Node(int key) : key(key) { sz = dup = 1; }
    inline int isRight() { return fa->ch[1] == this; }
    inline int cmp(int key) { return (key == this->key) ? -1 : key > this->key; }

};
Node *nil = new Node(), *root = nil;

inline void maintain(Node *u) {
    if(u == nil) return ;
    u->sz = u->dup;
    if(u->ch[0] != nil) u->sz += u->ch[0]->sz;
    if(u->ch[1] != nil) u->sz += u->ch[1]->sz;
}

// inline void pushdown(Node* u) {

// }

void rotate(Node *u) {
    Node* f = u->fa, *gf = f->fa;
    int d = u->isRight();
    if((f->ch[d] = u->ch[d ^ 1]) != nil) f->ch[d]->fa = f;
    if((u->fa = gf) != nil) gf->ch[f->isRight()] = u;
    f->fa = u;
    u->ch[d ^ 1] = f;
    maintain(f), maintain(u);
}

void splay(Node *u, Node *target) { // 把u旋到target儿子
    for(Node* f; u->fa != target; rotate(u))
        if((f = u->fa)->fa != target)
            rotate(u->isRight() == f->isRight() ? f : u);
    if(target == nil) root = u;
}

void insert(Node *u, Node *fa, int key) { // 插入关键字
    if(u == nil) {
        u = new Node(key);
        u->fa = fa; u->ch[0] = u->ch[1] = nil;
        if(fa != nil) fa->ch[u->key > fa->key] = u;
        maintain(fa);
        splay(u, nil);
        return ;
    }
    int d = u->cmp(key);
    if(d == -1) {
        u->dup++;
        maintain(u); maintain(u->fa);
        splay(u, nil);
        return ;
    }
    insert(u->ch[d], u, key);
}

inline Node* pre() { // 前驱
    Node* now = root->ch[0];
    while(now->ch[1] != nil) now = now->ch[1];
    return now;
}

inline Node* succ() { // 后继
    Node* now = root->ch[1];
    while(now->ch[0] != nil) now = now->ch[0];
    return now;
}

int queryRank(Node *u, int key) { // 根据关键字值查询排名
    int d = u->cmp(key);
    if(d == -1) {
        splay(u, nil);
        return u->ch[0]->sz + 1;
    }
    return queryRank(u->ch[d], key);
}

int queryKey(Node *u, int rank) { // k-th number
    if(rank <= u->ch[0]->sz)
        return queryKey(u->ch[0], rank);
    if(rank <= u->ch[0]->sz + u->dup) {
        splay(u, nil);    
        return u->key;
    }
    return queryKey(u->ch[1], rank - u->ch[0]->sz - u->dup);
}

void del(int key) {
    queryRank(root, key);
    if(root->dup > 1) {
        root->dup--;
        maintain(root);
        return ;
    } else if(root->ch[0] == nil && root->ch[1] == nil) {
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

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int op, key;
        scanf("%d%d", &op, &key);
        switch (op) {
        case 1: // insert
            insert(root, nil, key); break;
        case 2: // del
            del(key); break;
        case 3: // query Rank of x
            printf("%d\n", queryRank(root, key)); break;
        case 4: // query key of rank x
            printf("%d\n", queryKey(root, key)); break;
        case 5: // x pre
            insert(root, nil, key); printf("%d\n", pre()->key); del(key);
            break;
        case 6: // x succ
            insert(root, nil, key); printf("%d\n", succ()->key); del(key);
            break;
        }
    }
    return 0;
}