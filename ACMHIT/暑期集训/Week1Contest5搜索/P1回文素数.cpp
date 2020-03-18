#include <cstdio>
#include <cmath>
#define M 50000
typedef long long ll;
int p_prime[M];
int n, t, a, b, ans;

inline bool check(ll x) {
    for(ll i = 2; i*i <= x; i++) 
        if(x % i == 0)
            return false;
    return true;
}

void dfs() {
    ans = 0;
    for(int i = 2; i < 10; i++) 
    	if (i >= a && i <= b && check(i)) p_prime[++ans] = i;
    if (a <= 11 && b >= 11)
        p_prime[++ans] = 11;
    for(int i = 10; i <= 100000; i++) {
        int now = i, cnt[20], p = 0, tot = 0;
      	while(now) {
            now /= 10;
            tot++;
        }
        now = i; p = tot;
        while(now) {
            cnt[p--] = now%10;
            now /= 10; 
        }
        now = 0;
        for(int j = 1; j <= tot; j++)
            cnt[2*tot-j] = cnt[j];
        for(int j = 1; j <= 2*tot-1; j++)
            now = now*10+cnt[j];
        if (now > b)
            break;
        if (now >= a && now <= b && check(now))
            p_prime[++ans] = now;
    }
}

int main(){
    while(scanf("%d%d", &a, &b) != EOF) {
        dfs();
        //printf("%d\n", ans);
        for(int i = 1; i <= ans; i++)
            printf("%d\n", p_prime[i]);
        printf("\n");
    }
    return 0;
}