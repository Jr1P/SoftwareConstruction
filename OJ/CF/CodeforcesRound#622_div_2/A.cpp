#include <cstdio>
#include <cstring>
#include <iostream>
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define drep(i, n, a) for(int i = (n); i >= (a); i--)

int n, m;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        int ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        if(a < b) std::swap(a, b);
        if(b < c) std::swap(b, c);
        if(a < b) std::swap(a, b);
        if(a) {
            ans++;
            a--;
        }
        if(b) {
            ans++; b--;
        }
        if(c) {
            ans++; c--;
        }
        if(a && b) {
            ans++; a--; b--;
        }
        if(a && c) {
            ans++; a--; c--;
        }
        if(c && b) {
            ans++; c--; b--;
        }

        if(a && b && c) {
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}