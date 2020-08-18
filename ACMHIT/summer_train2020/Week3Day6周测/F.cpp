#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const int N = 205;
const int SZ = 26;

struct Matrix {
	ll m[N][N];

	inline void init() { mem(m, -1); }
} base, e;

int trie[N][SZ], fail[N], a[N];
int n, tot;
ll m, val[N];
char str[N];

inline ll max(ll x, ll y) { return x > y ? x : y; }

Matrix Mul(Matrix a, Matrix b) {
	Matrix c; c.init();
	for(int k = 0; k <= tot; k++)
		for(int i = 0; i <= tot; i++)
			if(~a.m[i][k])
				for(int j = 0; j <= tot; j++)
					if(~b.m[k][j])
						c.m[i][j] = max(c.m[i][j], a.m[i][k]+b.m[k][j]);
	return c;
}

Matrix pow(Matrix a, ll b) {
	Matrix ans = a;
	while(b) {
		if(b&1) ans = Mul(ans, a);
		b >>= 1; a = Mul(a, a);
	}
	return ans;
}

void insert(char *s, int p, int root=0) {
	for(int i = 0; s[i]; i++) {
		int id = s[i]-'a';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	val[root] += a[p];
}

void getFail() {
	int root = 0, q[N*N], hd = 0, tp = 0;
	for(int i = 0; i < SZ; i++)
		if(trie[root][i])
			fail[q[tp++] = trie[root][i]] = 0;
	while(hd != tp) {
		root = q[hd++];
		for(int i = 0; i < SZ; i++) {
			if(trie[root][i]) {
				fail[trie[root][i]] = trie[fail[root]][i];
				q[tp++] = trie[root][i];
				val[trie[root][i]] += val[fail[trie[root][i]]];
			} else trie[root][i] = trie[fail[root]][i];
		}
	}
}

int main() {
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	mem(base.m, -1);
	for(int i = 1; i <= n; i++) {
		scanf("%s", str);
		insert(str, i);
	}
	getFail();
	for(int i = 0; i <= tot; i++)
		for(int id = 0; id < SZ; id++)
			base.m[i][trie[i][id]] = val[trie[i][id]];
	base = pow(base, m-1);
	ll ans = 0;
	for(int i = 0; i <= tot; i++)
		ans = max(ans, base.m[0][i]);
	printf("%lld\n", ans);
	return 0;
}