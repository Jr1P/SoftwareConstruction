#include <cstdio>
typedef long long ll;
#define N 1050

int n, t;
ll s[N];
ll ans;

inline ll max(ll x, ll y) {
	return x>y?x:y;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lld", s+i);
		for(int i = 1; i < n; i++)
			for(int j = i+1; j <= n; j++)
				for(int k = 1; k <= n; k++) {
					if(k == i || k == j) continue;
					ll q = (s[i]+s[j])^s[k];
					ans = max(ans, q);
				}
		printf("%lld\n", ans);
	}
	return 0;
}