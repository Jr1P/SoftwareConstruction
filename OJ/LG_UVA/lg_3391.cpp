#include <cstdio>
const int N = 1e5 + 5;

struct Node {
    int l, r, key, lazy, sz;
    Node *ch[2], fa;

    Node() {}
    Node(int key) : key(key) { sz = lazy = 0; }

    inline int isRight() { return fa->ch[1] == fa; }
    inline int cmp(int key) { return key == this.key ? -1 : key > this.key; }

} *nil = new Node(),*root = nil;

inline void maintain() {

}

inline void pushdown() {}

inline void insert() {}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char ch[9]; int x;
        scanf("%s%d", ch, &x);
        switch(ch[0]) {
            case 'I': insert(root, x); break;
            case 'D': del(root, x); break;
            case 'M': printf("%d\n", Rank(root, x)); break;
            case 'Q': ;
        }
    }
    return 0;
}