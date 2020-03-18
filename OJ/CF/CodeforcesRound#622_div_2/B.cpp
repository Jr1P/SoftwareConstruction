#include <cstdio>
#include <cstring>
#include <iostream>
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define drep(i, n, a) for(int i = (n); i >= (a); i--)

int n;
int ma, mi;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int x, y;
        scanf("%d%d%d", &n, &x, &y);
        int sum = x + y;
        if(sum <= n) {
            mi = 1;
            ma = sum - 1;
        }
        else {
            ma = n;
            int k = sum - n;
            if(x != n && y != n) {
                if(x != k + 1 && y != k + 1)
                    mi = k + 1;
                else mi = k + 2;
            } else {
                if(x == n)
                    mi = y + 1;
                else mi = x + 1;
            }
        }
        printf("%d %d\n", mi, ma);
    }
    return 0;
}