#include <cstdio>
typedef long long ll;
#define N 2050

int n, t;
ll a, b;
char s[N];

struct D {
    int x, y, type;
}d[N];

inline ll min(ll x, ll y) {
    return x < y? x: y;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%lld%lld", &n, &a, &b);
        ll ans = 0;
        scanf("%s", s);
        int len = 0, cnt = 1;
        while(len < n && s[len] == '0') len++;
        d[1].x = 0; d[1].y = len-1;
        d[1].type = 1;
        int p = n;
        while(s[p-1] == '0') p--;
        int head = len;
        for(int i = len; i < p; i++) {
            if(s[i] == '0' && s[i+1] == '1' && d[cnt].y < i) {
                d[++cnt].x = head;
                d[cnt].y = i;
                d[cnt].type = 1;
                head = i+1;
            } else if(s[i] == '1' && (s[i+1] == '0' && s[i+2] == '0' || i == p-1)) {
                d[++cnt].x = head;
                d[cnt].y = i;
                d[cnt].type = 2;
                head = i+1;
            }
        }
        d[++cnt].x = head; d[cnt].y = n-1;
        d[cnt].type = 1;
        ll l = d[1].y-d[1].x+1;
        ans += min(l*b + l*a+a, l*b*(ll)2 + l*a);
        for(int i = 2; i < cnt; i++) {
            l = d[i].y-d[i].x+1;
            if(d[i].type == 2)
                ans += (l+1)*b*(ll)2+l*a;
            else {
                ans += min(l*a + (ll)2*a + (l-1)*b, l*a + (l-1)*(ll)2*b);
            }
        }
        l = d[cnt].y - d[cnt].x;
        ans += min(l*b + l*a+a, l*b*(ll)2 + l*a);
        printf("%lld\n", ans);
    }
    return 0;
}