#include <cstdio>

int n, m;

int main() {
    while(1) {
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        if(n % 2 == 1 && m % 2 == 1)
            puts("What a pity!");
        else puts("Wonderful!");
    }
    return 0;
}