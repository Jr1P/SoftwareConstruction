#include <cstdio>
#define N 100050
typedef long long ll;

int n;
ll a[N], sum, ans, sum2;
ll sumb, sum2b;
int bnum[N], cnt;
bool b1, bn;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
        sum2 += a[i] * a[i];
    }
    for(int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(!tmp) {
            if(i == 1) b1 = true;
            else if(i == n) bn = true;
            bnum[++cnt] = i;
            sumb += a[i];
            sum2b += a[i] * a[i];
        }
    }
    ans = sum * sum - sum2;
    ans >>= 1;
    if(n == 3) printf("%lld\n", ans);
    else {
        ans -= ((sumb * sumb - sum2b) >> 1);
        for(int i = 1; i < cnt; i++) {
            if(bnum[i] + 1 == bnum[i + 1])
                ans += (a[bnum[i]] * a[bnum[i + 1]]);
        }
        if(b1 && bn) ans += a[1] * a[n];
        printf("%lld\n", ans);
    }
    return 0;
}