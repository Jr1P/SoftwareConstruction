#include <cstdio>
int n;

int main() {
    while(~scanf("%d", &n)) {
        int i = 2, ans = 1;
        for(; i * i < n; i++)
            if(n % i == 0) ans += 2;
        if(i * i == n) ans++;
        printf("%d\n", ans);
    }
    return 0;
}