// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;
 
// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 9901;
// Macro end
 
int T, cas = 0;
int n, d;
int a[N], b[N], dp[N];
int bit[N];
 
// Imp
void add(int i, int x) {
    while(i < N) {
        bit[i] = (bit[i] + x) % MOD;
        i += i & (-i);
    }
}
int sum(int x) {
    int ret = 0;
    while(x > 0) {
        ret = (ret + bit[x]) % MOD;
        x -= x & (-x);
    }
    return ret;
}
 
 
int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(sii(n, d) != EOF) {
        int idx = 0;
        mem(bit, 0);
        rep(i, n) {
            si(a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        dp[idx++] = b[0];
        REP(i, 1, n) if(b[i] != b[i-1]) dp[idx++] = b[i];
        dp[idx++] = inf;
        rep(i, n) {
            int x = lower_bound(dp, dp + idx, a[i]) - dp + 1;
            int l = lower_bound(dp, dp + idx, a[i] - d) - dp;
            int r = upper_bound(dp, dp + idx, a[i] + d) - dp;
            int tmp = ((sum(r) - sum(l) + 1) % MOD + MOD) % MOD;
            add(x, tmp);
        }
        int ans = ((sum(idx) - n) % MOD + MOD) % MOD;
        put(ans);
    }
    
    return 0;
}