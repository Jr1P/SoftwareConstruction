#include <cstdio>
const int N = 65;

typedef long long  ll;
ll n, MOD, k;

struct Mat {
    ll m[N][N];
    inline void init() {
        for(int i = 0; i < 2 * n; i++)
            for(int j = 0; j < 2 * n; j++)
                m[i][j] = 0L;
    }
}A, E, bas;

inline Mat mul(Mat a, Mat b) {
    Mat c;
    c.init();
    for(int i = 0; i < 2 * n; i++)
        for(int j = 0; j < 2 * n; j++)
            for(int k = 0; k < 2 * n; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % MOD) % MOD;
    return c;
}

inline Mat qpow(Mat a, ll b) {
    Mat ans = E;
    while(b) {
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%lld%lld%lld", &n, &k, &MOD);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            scanf("%lld", &A.m[i][j]);
            A.m[i][j] %= MOD;
        }
    for(int i = 0; i < 2 * n; i++)
        E.m[i][i] = 1;
    bas = A;
    for(int i = n; i < 2 * n; i++) {
        bas.m[i - n][i] = 1;
        bas.m[i][i] = 1;
    }
    
    Mat ans = qpow(bas, k - 1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            A.m[i + n][j] = A.m[i][j];
    ans = mul(ans, A);
    for(int i = 0; i < n; i++) {
        printf("%lld", ans.m[i][0]);
        for(int j = 1; j < n; j++)
            printf(" %lld", ans.m[i][j]);
        puts("");
    }
    return  0;
}