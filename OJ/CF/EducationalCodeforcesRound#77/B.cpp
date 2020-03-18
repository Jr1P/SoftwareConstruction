#include <cstdio>
#include <iostream>
typedef long long ll;

int a, b;
int t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &a, &b);
        if(a > b) std::swap(a, b);
        if(a == 0 && b == 0) {
            puts("YES");
            continue;
        }
        if((a+b) % 3 != 0 || b > 2*a) {
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}