#include <cstdio>
#include <map>
#define N 6000010
typedef long long ll;

bool check[N];
int mu[N], sum_mu[N], phi[N], prime[N >> 2], tot;
ll sum_phi[N];
std::map<int, int> map_mu;
std::map<int, ll> map_phi;

void get(int n) {
	phi[1] = mu[1]= 1; check[1] = true;
	for(int i = 2; i <= n; i++) {
        if(!check[i]) prime[++tot] = i, mu[i] = -1, phi[i] = i - 1;
        for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
            check[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
	}
    for(int i = 1; i <= n; i++)
        sum_mu[i] = sum_mu[i - 1] + mu[i], sum_phi[i] = sum_phi[i - 1] + phi[i];
}

int djmu(int n) {
    if(n < N) return sum_mu[n];
    if(map_mu.count(n)) return map_mu[n];
    int ans = 1;
    for(int l = 2, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        ans -= (r - l + 1) * djmu(n / l);
    }
    map_mu.insert(std::make_pair(n, ans));
    return ans;
}

ll djphi(int n) {
    if(n < N) return sum_phi[n];
    if(map_phi.count(n)) return map_phi[n];
    ll ans = (ll)(n + 1) * n >> 1;
    for(int l = 2, r = 0; l <= n; l = r + 1) {
        r = n / (n / l);
        ans -= (ll)(r - l + 1) * djphi(n / l);
    }
    map_phi.insert(std::make_pair(n, ans));
    return ans;
}

int main() {
    get(N - 1);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("%lld %d\n", djphi(n), djmu(n));
    }
    return 0;
}