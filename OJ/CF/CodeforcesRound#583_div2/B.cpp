#include <cstdio>
#include <algorithm>
using namespace std;

int b, g, n;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    scanf("%d%d%d", &b, &g, &n);
    int p = b, q = g;
    if(p < q) swap(p, q);
    if(n <= q)
        printf("%d\n", n+1);
    else if(n < p)
        printf("%d\n", q+1);
    else {
        printf("%d\n", p+q-n+1);
    }
    return 0;
}