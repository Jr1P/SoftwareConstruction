// luogu3369 AC板子
#include <cstdio>
#define INF 2147483647

inline int Rand() {
    static int seed = 703;
    return seed = int(seed*48271LL%(~0u>>1));
}

struct Node { 
    int val, pr, sz, dup; //pr-随机优先级, sz-子树大小(包括自身), dup-副本数目
    Node* ch[2];

    Node() { sz = dup = pr = 0; }
    Node(int v) : val(v) { pr = Rand(); sz = dup = 1; }

    inline int cmp(int x) {
        if(x == val) return -1;
        return x < val ? 0 : 1;
    }

    inline void pushup() {
        sz = dup + ch[0]->sz + ch[1]->sz;
    }

} *nil = new Node(), *root = nil;

inline int read() {
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
    return flag ? -x: x;
}

//0左旋, 1右旋
inline void rotate(Node* &node, int d) {
    Node* x = node->ch[d^1];
    node->ch[d^1] = x->ch[d];
    x->ch[d] = node;
    node = x;
    node->ch[d]->pushup();
    node->pushup();
}

//插入操作
void insert(Node* &root, int val) {
//根为null，则直接创建此结点为根结点
    if (root == nil) {
        root = new Node(val);
        root->ch[0] = root->ch[1] = nil;
        return ;
    }
    int d = root->cmp(val);
    if(d == -1) root->dup++;
    else {
        insert(root->ch[d], val);
        if(root->ch[d]->pr > root->pr)
            rotate(root, d^1);
    }
    root->pushup();
}
//删除结点操作
void del(Node* &root, int val) {
    if(root == nil) return ;
    int d = root->cmp(val);
    if(d == -1) {
        if(root->dup > 1) {
            root->dup--;
            root->pushup();
        } else {
            if(root->ch[0] == nil) root = root->ch[1];
            else if(root->ch[1] == nil) root = root->ch[0];
            else {
                if(root->ch[0]->pr > root->ch[1]->pr)
                    rotate(root, 1), del(root->ch[1], val);
                else rotate(root, 0), del(root->ch[0], val);
                root->pushup();
            }     
        }
    } else {
        del(root->ch[d], val);
        root->pushup();
    }
}

inline int Kth(Node* root, int k) {
    if(root == nil) return INF;
    if(k <= root->ch[0]->sz)
        return Kth(root->ch[0], k);
    if(k <= root->ch[0]->sz + root->dup)
        return root->val;
    return Kth(root->ch[1], k - root->ch[0]->sz - root->dup);
}

inline int Rank(Node* root, int val) {
    if(root == nil) return 0;
    int d = root->cmp(val);
    if(d == -1)
        return root->ch[0]->sz + 1;
    return d * (root->ch[0]->sz + root->dup) + Rank(root->ch[d], val);
}

inline int pre(int val) {
    Node* id = root;
    int p;
    while(id != nil) {
        if(id->val < val)
            p = id->val, id = id->ch[1];
        else id = id->ch[0];
    }
    return p;
} // 前驱

inline int nxt(int val) {
    Node* id = root;
    int next;
    while(id != nil) {
        if(id->val > val)
            next = id->val, id = id->ch[0];
        else id = id->ch[1];
    }
    return next;
} // 后继

int n;

int main() {
    /*
    1 插入数x
    2 删除数x(若有多个相同的数，因只删除一个)
    3 查询x数的排名(排名定义为比当前数小的数的个数+1。输出最小的排名)
    4 查询排名为x的数
    5 求xx的前驱(前驱定义为小于x，且最大的数)
    6 求xx的后继(后继定义为大于x，且最小的数)
    */
    //build();
    // freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int cmd = read(), x = read();
        switch(cmd) {
            case 1: insert(root, x); break;
            case 2: del(root, x); break;
            case 3: printf("%d\n", Rank(root, x)); break;
            case 4: printf("%d\n", Kth(root, x)); break;
            case 5: printf("%d\n", pre(x)); break;
            case 6: printf("%d\n", nxt(x)); break;
        }
    }
    return 0;
}