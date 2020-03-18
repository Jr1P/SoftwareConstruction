#include <cstdio>
#define N 100050

int a, n;
int sum;

int main() {
    bool f = false;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(a%2 == 1) f = true;
    }
    if(f)
        puts("First");
    else puts("Second");
    return 0;
}