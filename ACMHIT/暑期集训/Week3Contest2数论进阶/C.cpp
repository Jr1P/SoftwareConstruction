#include <cstdio>
typedef long long ll;
#define N 10000050

int prime[N/10];
bool check[N+5];
ll sum[N+5], phi[N+5];
ll n, tot;

inline ll min(ll x, ll y) {
    return x<y?x:y;
}

void shai() {
	phi[1] = 1; check[1] = true;
	for(ll i = 2; i <= N; i++)	{
		if(!check[i]) {
			prime[++tot] = i;
			phi[i] = i-1;
		}
		for(ll j = 1; j <= tot && i*prime[j] <= N; j++) {
			check[i*prime[j]] = 1;
			if(i % prime[j])
				phi[i*prime[j]] = phi[i]*(prime[j]-1);
			else {
				phi[i*prime[j]] = phi[i]*prime[j];
				break;
			} 
		}
	}
    for(int i = 1; i <= N; i++)
        sum[i] = sum[i-1]+phi[i];
}

ll solve(ll x) {
    if(x <= N) return sum[x];
    ll ans = (x+1)*x>>1;
    ll dup = 0;
    for(ll i = 2; i <= x; i += dup) {
        ll v = x/i;
        dup = x/v-i+1;
        ans -= dup*solve(v);
    }
    return ans;
}

int main() {
    scanf("%lld", &n);
    shai();
    ll ans = solve(n);
    printf("%lld\n", ans);
    return 0;
}