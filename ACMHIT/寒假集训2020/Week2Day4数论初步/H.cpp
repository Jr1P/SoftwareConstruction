#include <cstdio>

int k, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &k);
        if(k == 1) puts("5");
        else printf("%d\n", k + 5);
    }
    return 0;
}