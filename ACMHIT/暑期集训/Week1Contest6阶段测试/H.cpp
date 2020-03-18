#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 55
#define N 1050

int m, n, w, tot, mid, waste = 0, ans = 0;
int nd[N], pd[M], PD[M], sum[N];

bool dfs(int x, int st) {
	if(x == 0) return true;
	if(waste+sum[mid] > tot) return false;
	for(int i = st; i <= m; i++)
		 if(nd[x] <= pd[i]) {
			pd[i] -= nd[x];
			if(pd[i] < nd[1]) {
				waste += pd[i];
			}
			if(nd[x] == nd[x-1]){
				if(dfs(x-1 ,i))
					return true;
			} else {
				if(dfs(x-1, 1))
					return true;
			} 
			if(pd[i] < nd[1]) {
				waste -= pd[i];
			}
			pd[i] += nd[x];
		}
	return false;
}

int main() {
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &PD[i]);
		tot += PD[i];
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &nd[i]);
	}
	sort(PD+1, PD+m+1);
	sort(nd+1, nd+n+1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i-1]+nd[i];
	int l = 0, r = n;
	while(l <= r) {
		mid = (l+r)>>1;
		waste = 0;
		memcpy(pd, PD, sizeof(PD));
		if(dfs(mid, 1)) {
			l = mid+1;
			ans = mid;
		}
		else
			r = mid-1;
	}
	printf("%d\n", ans);
	return 0;
}