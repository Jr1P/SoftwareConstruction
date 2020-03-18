#include <cstdio>
#include <queue>
using namespace std;
#define N 200050

int du[N];
int n, cnt, t;

queue<int > q;

int main() {
	scanf("%d", &t);
	while(t--) {
		cnt = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			du[i] = 0;
		if(n == 0) break;
		for(int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			du[u]++; du[v]++;
		}
		for(int i = 1; i <= n; i++)
			if(du[i]%2 == 1)
				cnt++;
		printf("%d\n", cnt/2);
	}
	return 0;
}