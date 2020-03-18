#include <cstdio>
#define eps 1e-7

int t;
double d, l;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lf%lf", &l, &d);
        if(l + eps < d) {
            puts("0.000000");
            continue;
        }
        
    }
    return 0;
}