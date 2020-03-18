#include <cstdio>
#include <cmath>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
#define MAXN 100050

int dp[MAXN][20], le[MAXN], ri[MAXN], a[MAXN];
int n, q;

void init() {
    mem(dp, 0);
    for(int i = 1; i <= n; i++) {
        le[i] = 0;
        ri[i] = 0;
        dp[i][0] = 1;
    }
}

inline int min(int x, int y) {
    return (x<y)?x:y;
}

inline int max(int x, int y) {
	return (x > y) ? x: y;
}

void ST() {
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++) {
            if(a[i] == a[i+(1<<j)-1]) {
                dp[i][j] = (1<<j);
                continue;
            }
			dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
            dp[i][j] = max(dp[i][j], ri[i]);
            dp[i][j] = max(dp[i][j], le[i+(1<<j)-1]);
            if(j >= 2) {
                int mid = i+(1<<(j-1)), d1, d2;
                if(a[i] == a[mid-1])
                    d1 = le[mid-1]-le[i]+1;
                else d1 = le[mid-1];
                dp[i][j] = max(dp[i][j], d1);
                if(a[i+(1<<j)-1] == a[mid])
                    d2 = ri[mid]-ri[i+(1<<j)-1]+1;
                else d2 = ri[mid];
                dp[i][j] = max(dp[i][j], d2);
                if(a[mid-1] == a[mid]) dp[i][j] = max(dp[i][j], d1+d2);
            }
            dp[i][j] = min(1<<j, dp[i][j]);
        }
}

inline int RMQ(int l, int r) {
	int j = log2(r-l+1);
    int ans = max(dp[l][j], dp[r-(1<<j)+1][j]);
    if(j >= 1) {
        int mid = (l+(1<<j))-1, d = 0;
        if(a[mid+1] == a[mid])
            d = min(1<<j, le[mid])+min(r-mid, ri[mid+1]);
        ans = max(ans, d);
    }
	return ans;
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &q);
        init();
        a[0] = a[n+1] = 99999999;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            le[i] = a[i] == a[i-1] ? le[i-1]+1 : 1;
        }
        for(int i = n; i; i--)
            ri[i] = a[i] == a[i+1] ? ri[i+1]+1 : 1;
        ST();
        while(q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", RMQ(l, r));
        }
    }
    return 0;
}
