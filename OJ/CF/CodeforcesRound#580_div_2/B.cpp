#include <cstdio>
#include <iostream>
using namespace std;
#define N 100050
typedef long long ll;
const ll INF = 0x3f3ffffffffffff;

int n;
ll a[N], dp[N][2];

inline ll _abs(ll x) {
    return x<(ll)0?-x:x;
}

inline ll min(ll x, ll y) {
    return x<y?x:y;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = INF;
    dp[1][0] = _abs(a[1]+(ll)1);
    dp[1][1] = _abs(a[1]-(ll)1);
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i-1][0]+_abs(a[i]-(ll)1), dp[i][0]);
        dp[i][0] = min(dp[i-1][1]+_abs(a[i]+(ll)1), dp[i][0]);
        dp[i][1] = min(dp[i-1][1]+_abs(a[i]-(ll)1), dp[i][1]);
        dp[i][1] = min(dp[i-1][0]+_abs(a[i]+(ll)1), dp[i][1]);
    }
    cout << dp[n][1] << endl;
    return 0;
}