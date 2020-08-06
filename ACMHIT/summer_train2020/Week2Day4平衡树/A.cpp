#include <cstdio>
#include <cstdlib>
#define INF 0x7fffffff

inline int Rand() {
    static int seed = 703;
    return seed = int(seed*48271LL%(~0u>>1));
}

struct Node { 
    int val, pr, sz, dup;
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

//插入
void insert(Node* &root, int val) {
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
            rotate(root, d^1    );
    }
    root->pushup();
}

inline int Kth(Node* root, int k) {
    if(root == nil) return INF;
    if(k <= root->ch[0]->sz)
        return Kth(root->ch[0], k);
    if(k <= root->ch[0]->sz + root->dup)
        return root->val;
    return Kth(root->ch[1], k - root->ch[0]->sz - root->dup);
}

int main() {
    int n = read();
    for(int i = 1; i <= n; i++) {
        char c[10];
        scanf("%s", c);
        int x = read();
        switch(c[0]) {
            case 'I': insert(root, x); break;
            case 'Q': printf("%d\n", Kth(root, x)); break;
        }
    }
    return 0;
}