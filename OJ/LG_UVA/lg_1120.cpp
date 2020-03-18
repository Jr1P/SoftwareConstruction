#include <cstdio>
#include <algorithm>
using namespace std;

int n, cnt;
int a[105];
bool f[105], flag;

bool dfs(int len, int tt, int x) {
	if(len == 0 && x == 0)
		return true;
	if(len == 0 && x != 0)
		return dfs(tt, tt, x);
	if(len != 0 && x == 0)
		return false;
	int last = -1;
	for (int i = cnt; i > 0; i--) {
		if (last == a[i]) continue;
		if (!f[i] && len-a[i] >= 0) {
			f[i] = true;
			if (dfs(len-a[i], tt, x-1))
				return true;
			else last = a[i];
			f[i] = false;
			if (len == tt)
				break;
		}
	}
	return false;
}

int main() {
    scanf("%d", &n);
    int sum = 0;
    for(int i = 1; i <= n; i++) f[i] = false;
    for(int i = 1; i <= n; i++) {
        int b;
        scanf("%d", &b);
        if(b > 50) continue;
        sum += b;
        a[++cnt] = b;
    }
    int ans = sum;
    sort(a+1, a+cnt+1);
    for(int i = 1; i <= sum ; i++) {
        if(sum % i || a[cnt] > i) continue;
        for(int j = 1; j <= cnt; j++) f[j] = false;
        if(dfs(i, i, cnt)) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
	return 0;
}