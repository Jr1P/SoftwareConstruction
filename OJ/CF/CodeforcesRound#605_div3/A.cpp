#include <cstdio>

int n, m, t;
long a, b ,c;

void swap(long &a, long &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%ld%ld%ld", &a, &b, &c);
        if(a > b) swap(a, b); 
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        long ans;
        if(c - 2 >= a) ans = (c - a - 2) << 1;
        else ans = 0;
        printf("%ld\n", ans);
    }
    return 0;
}