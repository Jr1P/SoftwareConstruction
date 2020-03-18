#include <cstdio>

int a, b, c, t;
int h, p;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &a, &b, &c);
        scanf("%d%d", &h, &p);
        int ans = 0;
        if(h > p) {
            if(a >= 2*b) {
                ans += h*b;
                a -= 2*b;
                if(a >= 2*c) ans += p*c;
                else ans += a/2*p;
            } else ans = a/2*h;
        } else {
            if(a >= 2*c) {
                ans += p*c;
                a -= 2*c;
                if(a >= 2*b) ans += h*b;
                else ans += a/2*h;
            } else ans = a/2*p;
        }
        printf("%d\n", ans);
    }
    return 0;
}