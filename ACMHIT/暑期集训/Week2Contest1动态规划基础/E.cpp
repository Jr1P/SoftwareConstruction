#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1050

int t, n, k, sum;
char name[10];
int p[N], j[N];
int dp[N][N], val[N][N];

struct Node {
    int p, j;
}node[N];

inline bool cmp(Node a, Node b) {
    if(a.p != b.p) return a.p > b.p;
    return a.j < b.j;
}

void work() {
    memset(dp, 0, sizeof(dp));
    memset(val, 0, sizeof(val));
    for(int i = 1; i <= n-k; i++)
        for(int j = 1; j <= (i+1)/2; j++) {
            if(dp[i-1][j] > dp[i-1][j-1]+node[i+k].j) {
                dp[i][j] = dp[i-1][j];
                val[i][j] = val[i-1][j];
            } else if(dp[i-1][j] == dp[i-1][j-1]+node[i+k].j) {
                dp[i][j] = dp[i-1][j];
                val[i][j] = min(val[i-1][j], val[i-1][j-1]+node[i+k].p);
            } else {
                dp[i][j] = dp[i-1][j-1]+node[i+k].j;
                val[i][j] = val[i-1][j-1]+node[i+k].p;
            }
        }
    printf("%d %d\n", sum-val[n-k][(n-k+1)/2], dp[n-k][(n-k+1)/2]);
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
        sum = 0;
		scanf("%s", name);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &node[i].p, &node[i].j);
            sum += node[i].p;
        }
        sort(node+1, node+1+n, cmp);
		if(name[0] == 'P')
            k = 1;
		else k = 0;
        work();
	}
	return 0;
}