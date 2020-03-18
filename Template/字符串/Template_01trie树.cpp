#include <cstdio>
#define N 100050
typedef long long ll;

int trie[N << 5][2];
ll val[N << 5];
int root, n, m, tot, t;

void insert(ll a, int root = 0) {
	for(int i = 32; i >= 0; i--) {
		ll v = (a >> i) & 1;
		if(!trie[root][v])
			trie[root][v] = ++tot;
		root = trie[root][v];
	}
	val[root] = a;
}

ll query(ll x, int root = 0) {
	for(int i = 32; i >= 0; i--) {
		ll v = (x >> i) & 1;
		if(trie[root][v ^ 1])
			root = trie[root][v ^ 1];
		else root = trie[root][v];
	}
	return val[root];
}

int main() {
	int kase = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= (n << 5); i++) {
			trie[i][0] = trie[i][1] = 0;
			val[i] = 0L;
		}
		for(int i = 0; i < n; i++) {
			ll a;
			scanf("%lld", &a);
			insert(a);
		}
		printf("Case #%d:\n", ++kase);
		while(m--) {
			ll x;
			scanf("%lld", &x);
			printf("%lld\n", query(x));
		}
	}
	return 0;
}
