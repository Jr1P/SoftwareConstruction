#include <cstdio>
typedef long long ll;
const int INF = 0x7fffffff;
const int N = 100; 

int n, m;
int mina, minb;
int a[N], b[N];
ll ans;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        mina = minb = INF;
        ans = 0;
        for(int i = 1; i<= n; i++) scanf("%d", a + i), mina = min(mina, a[i]);
        for(int i = 1; i <= n; i++) scanf("%d", b + i), minb = min(minb, b[i]);
        
        for(int i = 1; i <= n; i++) {
            if(a[i] - mina < b[i] - minb) {
                ans += b[i] - minb;
            } else ans += a[i] - mina;
        }
        printf("%lld\n", ans);
    }
    return 0;
}