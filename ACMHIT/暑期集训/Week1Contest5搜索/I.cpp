#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 120
#define M 5500

int n, m;
int gcd[N][N], lcm[N][N], val[N], gg[N], ll[N];
bool g[N][N], vis[N], f = true;

inline int _gcd(int a, int b) {
	return a%b == 0? b: _gcd(b, a%b);
}

queue<int > q;

void bfs(int x) {
	while(!q.empty()) q.pop();
	q.push(x);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v = 1; v <= n; v++) {
			int vv = gcd[u][v]*lcm[u][v]/val[u];
			if(!g[u][v]) continue;
			if(!vis[v]) {
				q.push(v);
				val[v] = vv;
			} else if(val[v] == vv)
				continue;
			else {
				f = false;
				return ;
			}
		}
	}
	f = true;
	//printf("YES\n");
	//for(int i = 1; i < n; i++)
	//	printf("%lld ", val[i]);
	//printf("%lld\n", val[n]);
	//exit(0);
}

int main() {
	scanf("%d%d", &n, &m);
	if(m == 0) {
		printf("YES\n");
		for(int i = 1; i <= n; i++)
			printf("1 ");
		return 0;
	}
	for(int i = 1; i <= m; i++) {
		int _l, _g;
		int u, v;
		scanf("%d%d%d%d", &u, &v, &_g, &_l);
		lcm[u][v] = lcm[v][u] = _l;
		gcd[u][v] = gcd[v][u] = _g;
		if(_gcd(_l, _g) != _g) {
			printf("NO\n");
			return 0;
		}
		g[u][v] = 1; g[v][u] = 1;
		gg[u] = gg[v] = _g; ll[u] = ll[v] = _l;
	}
	for(int i = 1; i <= n; i++) {
		if (!vis[i])
		for(int j = gg[i]; j*j <= gg[i]*ll[i]; j++) {
			if (gg[i]*ll[i] % j == 0) {
				//memset(val, 0, sizeof(val));
				memset(vis, 0, sizeof(vis));
				val[i] = j;
				bfs(i);
				if(f) break;
				//memset(val, 0, sizeof(val));
				memset(vis, 0, sizeof(vis));
				val[i] = gg[i]*ll[i]/j;
				bfs(i);
			}
		}
		if (!f) {
			printf("NO\n");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		if (val[i] == 0)
			val[i] = 1;
		printf("%d\n", val[i]);
	}
	return 0;
}