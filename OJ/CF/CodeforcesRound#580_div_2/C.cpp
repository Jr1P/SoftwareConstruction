#include <cstdio>
#define N 100050

int n;
int a[N<<1];

int main() {
    scanf("%d", &n);
    if(n&1) {
        a[1] = 1; a[n+1] = 2;
        for(int i = 2; i <= n; i++) {
            if(i%2 == 0) {
                a[i+n] = 2*i-1;
                a[i] = 2*i;
            } else {
                a[i] = 2*i-1;
                a[i+n] = 2*i;
            }
        }
    } else {
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i = 1; i < n+n; i++)
        printf("%d ", a[i]);
    printf("%d\n", a[n+n]);
    return 0;
}