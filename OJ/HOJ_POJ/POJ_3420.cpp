#include <cstdio>
#define irep(i, a, n) for(int i = (a); i < (n); i++)
typedef long long ll;
const int O = 4;

struct Mat {
    ll m[O][O];

    inline void init() {
        irep(i, 0, O)
            irep(j, 0, O)
                m[i][j] = 0;
    }
} base, e = (Mat){1, 0, 0, 0,
             0, 1, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1};

Mat mul(Mat a, Mat b, ll mod) {
    Mat c; c.init();
    irep(i, 0, O)
        irep(j, 0, O)
            irep(k, 0, O)
                c.m[i][j] = ((c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod + mod) % mod;
    return c;
}

Mat pow(Mat a, ll b, ll mod) {
    Mat ans = e;
    while(b) {
        if(b & 1) ans = mul(ans, a, mod);
        a = mul(a, a, mod); b >>= 1;
    }
    return ans;
}

int main() {
    int n, mod;
    int a[] = {1, 1, 5, 11};
    while(~scanf("%d%d", &n, &mod) && n) {
        base = (Mat) {1, 5, 1, -1,
                    1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0};
        if(n <= 3) printf("%d\n", a[n] % mod);
        else {
            base = pow(base, n - 3, mod);
            printf("%lld\n", ((base.m[0][0] * 11 % mod + base.m[0][1] * 5 % mod + base.m[0][2] + base.m[0][3]) % mod + mod) % mod);
        }
    }
    
    return 0;
}