#include <cstdio>
#define N 30000000
typedef long long ll;

int t, n;
ll sum[N+10];

void pre() {
    for(ll x = 1; x <= (N>>1); x++) {
        for(ll i = 1; (i+1)*x <= N; i++) {
            ll b = i*x, a = b+x;
            if((a^b) == x) sum[a]++;
        }
    }
    for(int i = 1; i <= N; i++)
        sum[i] = sum[i-1]+sum[i];
}

int main() {
    scanf("%d", &t);
    pre();
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", ++kase, sum[n]);
    }
    return 0;
}