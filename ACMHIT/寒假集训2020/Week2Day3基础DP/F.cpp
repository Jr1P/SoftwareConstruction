#include <cstdio>
#include <iostream>
#define N 5050

int n, ans;
int a[N], f[N];

int main() {
    int kase = 0;
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        a[1] = n; ans = 0;
        int p = 1;
        while(1) {
            scanf("%d", &a[++p]);
            if(a[p] == -1) break;
        }
        p--;
        n = p;
        for(int i = 1; i <= n; i++) f[i] = 1;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j < i; j++)
                if(a[i] <= a[j])
                    f[i] = std::max(f[i], f[j] + 1);	
        for(int i = 1; i <= n; i++)
            ans = std::max(ans, f[i]);
        printf("Test #%d:\n  maximum possible interceptions: %d\n\n", ++kase, ans);
    }
    return 0;
}