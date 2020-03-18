#include <cstdio>
const int N = 4;
typedef long long ll;
const ll MOD = 1000000007L;

struct Mat {
    ll m[N][N];
    Mat() {}

    inline void init() {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                m[i][j] = 0L;
    }
};

ll n;
Mat e, bas;

inline Mat mul(Mat a, Mat b) {
    Mat c;
    c.init();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j] % MOD) % MOD;
    return c;
}

inline Mat qpow(Mat a, ll b) {
    Mat ans = e;
    while(b) {
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    int ans1[5] = {1, 1, 5, 11, 36};
    for(int i = 0; i < N; i++)
        e.m[i][i] = 1;
    bas.m[0][0] = 1; bas.m[0][1] = 5; bas.m[0][2] = 1; bas.m[0][3] = -1;
    bas.m[1][0] = bas.m[2][1] = bas.m[3][2] = 1;
    while(~scanf("%lld", &n)) {
        if(n >= 1L && n <= 4L) {
            printf("%d\n", ans1[n]);
            continue;
        }
        Mat ans = qpow(bas, n - 4);
        ll p = (ans.m[0][0] * 36L % MOD + ans.m[0][1] * 11L % MOD + ans.m[0][2] * 5L % MOD + ans.m[0][3] % MOD) % MOD;
        p = (p + MOD) % MOD;
        printf("%lld\n", p);
    }
    return 0;
}