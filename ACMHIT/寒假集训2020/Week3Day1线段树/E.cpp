#include <cstdio>

const int N = 5e5 + 5;

int tree[N], n, q, addnum;

inline int lowbit(int k) { return k & (-k); }

inline int read() {
    int x, f;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void add(int x, int ad) {
	for(int i = x; i <= n; i += lowbit(i))
		tree[i] += ad;
}

inline int sum(int r) {
	int ans = 0;
	for(int i = r; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d:\n", ++kase);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) tree[i] = 0;
        for(int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            add(i, a);
        }

        while(1) {
            char type[6];
            scanf("%s", type);
            if(type[0] == 'E') break;
            if(type[0] == 'Q') {
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%d\n", sum(r) - sum(l - 1));
            } else if(type[0] == 'A') {
                int l;
                scanf("%d%d", &l, &addnum);
                add(l, addnum);
            } else if(type[0] == 'S') {
                int l;
                scanf("%d%d", &l, &addnum);
                add(l, -addnum);
            }
        }
    }
    return 0;
}
