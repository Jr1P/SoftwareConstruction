#include <cstdio>
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define irep(i, a, n) for(int i = (a); i < (n); i++)
typedef long long ll;
const int O = 7;
const ll mod = 2147493647;

struct Mat {
    ll m[O][O];

    inline void init() {
        irep(i, 0, O)
            irep(j, 0, O)
                m[i][j] = 0;
    }
} base, e;

inline ll mul(ll a, ll b) {
    ll ans = 0;
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod; b >>= 1;
    }
    return ans;
}

inline Mat mmul(Mat a, Mat b) {
    Mat c;
    c.init();
    irep(i, 0, O)
        irep(j, 0, O)
            irep(k, 0, O)
                c.m[i][j] = (c.m[i][j] + mul(a.m[i][k], b.m[k][j])) % mod;
    return c;
}

Mat power(Mat a, int b) {
    Mat ans = e;
    while(b) {
        if(b & 1) ans = mmul(ans, a);
        a = mmul(a, a); b >>= 1;
    }
    return ans;
}

int main() {
    irep(i, 0, O)
        irep(j, 0, O)
            if(i == j) e.m[i][j] = 1;
            else e.m[i][j] = 0;
    int t;
    scanf("%d", &t);
    while(t--) {
        base = (Mat){1, 2, 1, 0, 0, 0, 0,
                     1, 0, 0, 0, 0, 0, 0,
                     0, 0, 1, 4, 6, 4, 1,
                     0, 0, 0, 1, 3, 3, 1,
                     0, 0, 0, 0, 1, 2, 1,
                     0, 0, 0, 0, 0, 1, 1,
                     0, 0, 0, 0, 0, 0, 1};
        ll a, b, n;
        scanf("%lld%lld%lld", &n, &a, &b);
        if(n == 1) {
            printf("%lld\n", a);
            continue;
        } else if(n == 2) {
            printf("%lld\n", b);
            continue;
        }
        base = power(base, n - 2);
        printf("%lld\n", (mul(base.m[0][0], b) + mul(base.m[0][1], a) + mul(base.m[0][2], 81)
                            + base.m[0][3] * 27 % mod + base.m[0][4] * 9 % mod + base.m[0][5] * 3 % mod + base.m[0][6]) % mod);
    }
    return 0;
}