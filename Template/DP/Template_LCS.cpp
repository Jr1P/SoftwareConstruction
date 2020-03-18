#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005
//lg_1439

int n, len = 0;
int a[N], b[N], d[N];
int belong[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		belong[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
		scanf("%d", b+i);
	for(int i = 1; i <= n; i++) {
		if(belong[b[i]] > d[len])
			d[++len] = belong[b[i]];
		else {
			int j = lower_bound(d+1, d+len+1, belong[b[i]])-d;
			d[j] = belong[b[i]];
		}
	}
	printf("%d\n", len);
	return 0;
}