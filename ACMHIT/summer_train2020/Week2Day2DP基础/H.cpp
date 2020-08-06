#include <cstdio>
#include <iostream>
const int N = 1e5 + 5;
typedef long long ll;

int n, m;
ll sum[N];
int a[N], pos[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        for(int i = 1; i <= m; i++) pos[i] = -1;
        int nowpos = 0, ans = 0;
        pos[0] = 0;
        for(int i = 1; i <= n; i++) {
			ll mod = sum[i] % m;
			if(pos[mod] >= nowpos) {
				ans++;
				nowpos = i;
			}
			pos[mod] = i;
		}
        printf("%d\n", ans);
    }
    return 0;
}