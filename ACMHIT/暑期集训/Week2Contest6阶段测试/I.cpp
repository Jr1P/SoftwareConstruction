#include <cstdio>
#include <vector>
using namespace std;
#define N 200050
typedef long long ll;

ll a[N], tree[N];
int n, p, x, y;
ll ans = 0;
vector <ll> v[N];

inline ll min(ll x, ll y) {return x < y? x: y;}
inline ll lowbit(ll k) {return k&(-k);}

void modify(ll x, ll add) {
	for(int i = x; i <= n; i += lowbit(i))
		tree[i] += add;
}

ll getSum(int x) {
	ll ans = 0;
	for(int i = x; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		a[i] = min(a[i], n);
		ll k = min(i-1, a[i]);
		v[k].push_back(i);
	}
	ans = 0;
	for(int i = 1; i <= n; i++) {
		modify(a[i], 1);
		for(ll j: v[i])
			ans += getSum(n)-getSum(j-1);
	}
	printf("%lld\n", ans);
	return 0;
}
