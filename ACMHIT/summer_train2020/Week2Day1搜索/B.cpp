#include <cstdio>
#include <cmath>
const int M = 5e4;
typedef long long ll;
int hprime[M];
int n, t, a, b, count;

inline bool check(ll x) {
    for(ll i = 2; i * i <= x; i++) 
        if(x % i == 0) return false;
    return true;
}

void dfs() {
    count = 0;
    for(int i = 2; i < 10; i++) 
        if (check(i)) hprime[++count] = i;
    hprime[++count] = 11;
    for(int i = 10; i < 10000; i++) {
        int now = i, cnt[20], tot = log10(now) + 1, p = tot;
        while(now) {
            cnt[p--] = now % 10;
            now /= 10; 
        }
        for(int j = 1; j <= tot; j++) cnt[2 * tot - j] = cnt[j];
        for(int j = 1; j <= 2 * tot - 1; j++) now = now * 10 + cnt[j];
        if (check(now)) hprime[++count] = now;
    }
}

int main(){
    dfs();
    while(~scanf("%d%d", &a, &b)) {
        for(int i = 1; i <= count; i++) {
            if(hprime[i] < a) continue;
            if(hprime[i] > b) break;
            printf("%d\n", hprime[i]);
        }
        puts("");
    }
    return 0;
}