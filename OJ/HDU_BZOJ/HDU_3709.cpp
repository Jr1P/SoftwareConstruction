#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(b))
typedef long long ll;

ll a, b;
ll dp[20][1800][20], num[20];
int pivot;

ll dfs(int pos, int bal, bool limit, bool lead) {
    if(bal < 0) return 0L;
    if(pos == -1) {
        if(bal == 0) {
            if(lead && pivot)
                return 0L;
            return 1L;
        }
        else return 0L;
    }
    if(!limit && !lead && dp[pos][bal][pivot] != -1L) return dp[pos][bal][pivot];
    int up = limit ? num[pos] : 9;
    ll ans = 0L;
    for(int i = 0; i <= up; i++) {
        if(lead && i == 0)
            ans += dfs(pos - 1, bal, limit && i == num[pos], true);
        else ans += dfs(pos - 1, bal + i * (pos - pivot), limit && i == num[pos], false);
    }
    if(!limit && !lead) dp[pos][bal][pivot] = ans;
    return ans;
}

ll solve(ll r) {
    if(r < 0) return 0;
    if(r == 0) return 1;
	int pos = 0;
	while(r) {
		num[pos++] = r % 10;
		r /= 10;
	}
    ll ans = 0L;
    for(pivot = 0; pivot < pos; pivot++)
	    ans += dfs(pos - 1, 0, true, true);
    return ans;
}

int main() {
    for(int i = 0; i < 20; i++)
        for(int j = 0; j < 1800; j++)
            for(int k = 0; k < 20; k++)
                dp[i][j][k] = -1L;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", solve(b) - solve(a - 1));
    }
    return 0;
}