#include <cstdio>
#include <cstring>
const int N = 2000;

int Q;

struct BST {
	BST *Left,*Right;
	int num;
}*rt = NULL;

void insert(BST *&x,int v) {
	if(!x) {
		x = new BST;
		x->Left = x->Right = NULL, x->num = v;
		return;
	}
	if(v == x->num) return;
	if(v < x->num) insert(x->Left, v);
	else insert(x->Right, v);
}

void Query(BST *x,int v) {
	if(v == x->num) return ;
    int d = v < x->num;
    if(d) putchar('E'), Query(x->Left, v);
	else putchar('W'), Query(x->Right, v);
}

int main() {
    int T, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        rt = NULL;
        int a;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a), insert(rt, a);
        scanf("%d", &Q);
        for(int i = 1;i <= Q; i++) {
            int x;
            scanf("%d", &x);
            Query(rt, x);
            puts("");
	    }
    }
	return 0;
}
