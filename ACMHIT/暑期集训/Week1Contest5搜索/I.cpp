#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
typedef long long ll;
const int INF = 0x1fffffff;
const int N = 110;
// #define M 5500

int n, m;
ll gcd[N][N], lcm[N][N], val[N], l[N], r[N];
bool vis[N];

std::vector<int > G[N];

inline ll _gcd(ll a, ll b) {
	return a % b == 0 ? b : _gcd(b, a % b);
}

std::queue<int > q;

bool bfs(int x) {
	while(!q.empty()) q.pop();
	q.push(x);
	vis[x] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : G[u]) {
			ll vv;
			if(gcd[u][v] * lcm[u][v] % val[u]) return false;
			vv = gcd[u][v] * lcm[u][v] / val[u];
			if(!vis[v]) {
				vis[v] = true;
				q.push(v);
				val[v] = vv;
				continue;
			}
			if(val[v] != vv || _gcd(val[v], val[u]) != gcd[u][v]) return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	if(m == 0) {
		printf("YES\n");
		for(int i = 1; i <= n; i++) printf("1 ");
		return 0;
	}
	for(int i = 1; i <= n; i++) l[i] = 0, r[i] = INF;
	for(int i = 1; i <= m; i++) {
		ll lc, g;
		int u, v;
		scanf("%d%d%lld%lld", &u, &v, &g, &lc);
		lcm[u][v] = lcm[v][u] = lc;
		gcd[u][v] = gcd[v][u] = g;
		if(_gcd(lc, g) != g) {
			printf("NO\n");
			return 0;
		}
		G[u].push_back(v); G[v].push_back(u);
		l[u] = std::max(g, l[u]);
		l[v] = std::max(g, l[v]);
		r[u] = std::min(r[u], lc);
		r[v] = std::min(r[v], lc);
	}
	for(int i = 1; i <= n; i++) {
		bool f;
		if (!vis[i] && l[i] && r[i]) {
			for(ll j = l[i]; j <= r[i]; j++)
				if (l[i] * r[i] % j == 0) {
					memset(vis, 0, sizeof(vis));
					val[i] = j;
					f = bfs(i);
					if(f) break;
				}
			if (!f) {
				printf("NO\n");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i = 1; i <= n; i++)
		printf("%lld ", val[i] == 0 ? 1 : val[i]);
	return 0;
}