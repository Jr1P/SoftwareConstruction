#include <cstdio>
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define irep(i, a, n) for(int i = (a); i < (n); i++)
const int O = 3;
const int mod = 200907;

int n;

struct Mat {
    int m[O][O];

    inline void init() {
        irep(i, 0, O)
            irep(j, 0, O)
                m[i][j] = 0;
    }
} base, e = (Mat){1, 0, 0, 0, 1, 0, 0, 0, 1};

inline Mat mmul(Mat a, Mat b) {
    Mat c;
    c.init();
    irep(i, 0, O)
        irep(j, 0, O)
            irep(k, 0, O)
                c.m[i][j] = (1ll * c.m[i][j] + 1ll * a.m[i][k] * b.m[k][j] % mod) % mod;
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
    while(~scanf("%d", &n) && n) {
        base = (Mat){1, 2, 1, 1, 0, 0, 0, 0, 1};
        if(n == 1) {
            puts("1");
            continue;
        } else if(n == 2) {
            puts("2");
            continue;
        }
        base = power(base, n - 2);
        printf("%d\n", (base.m[0][0] * 2 + base.m[0][1] + base.m[0][2]) % mod);
    }
    return 0;
}