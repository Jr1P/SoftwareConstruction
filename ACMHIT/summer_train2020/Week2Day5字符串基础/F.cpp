#include <cstdio>
#include <cstring>
const int N = 2e6+5;
const int mod = 51123987;

char s[N << 1];
int r[N << 1], ll[N << 1], rr[N << 1];
int n, len;
inline int min(int x, int y) { return x < y ? x : y; }

void manacher() {
    int ctr = 0, right = 0;
    for(int i = 0; i < len; i++) {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        while(i >= r[i] && i+r[i] < len && s[i+r[i]] == s[i-r[i]]) r[i]++;
        if(s[i+r[i]-1] == '#') r[i]--;
        if(i+r[i]-1 > right) {
            right = i+r[i]-1;
            ctr = i;
        }
    }
}

int main() {
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++)
        s[len++] = '#', s[len++] = getchar();
    s[len++] = '#';
    manacher();
    for(int i = 1; i < len; i ++) {
        rr[i]++, rr[i+r[i]+1]--;
        ll[i-r[i]+1]++, ll[i+1]--;
    }
    for(int i = 1; i < len; i++)
        rr[i] = (rr[i-1]+rr[i])%mod,
        ll[i] = (ll[i-1]+ll[i])%mod;
    for(int i = 3; i < len; i += 2)
        rr[i] = (rr[i-2]+rr[i])%mod;
    int ans = 1ll*rr[len-2]*(rr[len-2]-1)/2%mod;
    for(int i = 1; i < len; i += 2)
        ans = ((ans-1ll*ll[i+2]*rr[i]%mod)%mod+mod)%mod;
    printf("%d\n", ans);
    return 0;
}