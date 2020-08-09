#include <cstdio>
#include <cstring>
const int N = 1e5+5;

int s[N << 1], r[N << 1], len;
inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

void manacher() {
    int ctr = 0, right = 0;
    for(int i = 0; i < len; i++) {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        while(i-r[i] >= 0 && i+r[i] < len && s[i+r[i]] == s[i-r[i]])
            r[i]++;
        if(s[i+r[i]-1] == -1) r[i]--;
        if(i+r[i]-1 > right) {
            right = i+r[i]-1;
            ctr = i;
        }
    }
}

int main() {
    int t, n, kase = 0;
    scanf("%d", &t);
    while(t--) {
        len = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            s[len++] = -1;
            scanf("%d", &s[len++]);
        }
        s[len++] = -1;
        for(int i = 0; i < len; i++) r[i] = 0;
        manacher();
        int ans = 0;
        for(int i = 2; i < len; i += 2) {
            if(ans > r[i]) continue;
            int rad = r[i];
            if(i + rad + 1 >= len) rad -= 2;
            while(ans < rad && r[i+rad] < rad) rad -= 2;
            ans = max(ans, rad);
        }
        printf("Case #%d: %d\n", ++kase, ans/2*3);
    }
    return 0;
}
