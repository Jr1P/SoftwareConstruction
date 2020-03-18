#include <cstdio>

int t, n;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int a;
        scanf("%d", &a);
        for(int i = 2; i <= n; i++) {
            int b;
            scanf("%d", &b);
            a ^= b;
        }
        if(a == 0) puts("No");
        else puts("Yes");
    }
    return 0;
}