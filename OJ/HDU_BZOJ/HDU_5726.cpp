#include <cstdio>
#include <cmath>
const int N = 1e5 + 5;

int gcd[N][20], n;

inline int _gcd(int a, int b) { return b == 0 ? a : _gcd(b, a % b); }

void ST() {
    for(int i = j; (1 << j) < n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            gcd[i][j] = _gcd(gcd[i][j - 1], gcd[i + (1 << (j - 1))][j - 1]);
}

inline int query(int l, int r) {
    int k = log2(r - l + 1);
    return _gcd(gcd[l][k], gcd[r - (1 << k) + 1][k]);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", gcd[i][0]);
    ST();
    
    return 0;
}