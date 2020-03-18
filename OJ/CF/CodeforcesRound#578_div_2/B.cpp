#include <cstdio>
#define N 150

int n, m, t, k; 
int h[N];

int max(int x, int y) {
	return x>y?x:y;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		bool f = true;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= n; i++)
			scanf("%d", &h[i]);
		for(int i = 1; i < n; i++) {
			if(h[i+1] > h[i]+k) {
				m -= (h[i+1]-h[i]-k);
				if(m < 0) {
					puts("NO");
					f = false;
					break;
				}
			} else
				m += h[i]-max(h[i+1]-k, 0);
		}
		if(f) puts("YES");
	}
	return 0;
}