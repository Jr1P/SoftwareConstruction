#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 10050
using namespace std;

struct Edge{
	int v, next;
}e[N<<1];

int n, tim, cnt;
int d[N], match[N<<1], state[N<<1], head[N];
int t[5], an[N], tot;
bool check[N<<1];

inline void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

bool dfs(int u) {
	for(int i = head[u]; i != -1; i = e[i].next) {
		int v = e[i].v;
		if(!check[v]) {
			check[v] = true;
			if(match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				//match[u] = v;
				return true;
			}
		}
	}
	return false;
}

int hungarian() {
	int ans = 0;
	tim = 0;
	memset(match, -1, sizeof(match));
	memset(state, 0, sizeof(state));
	for(int i = n-1; i >= 0; i--) {
		//if(match[i] == -1) {
			memset(check, false, sizeof(check));
			if(dfs(i)) ans++;
		//}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	int cnt1 = 0;
	for(int i = 0; i <= n; i++) head[i] = -1;
	for(int i = 0; i < n; i++) {
		cnt1 = 0;
		scanf("%d", &d[i]);
		if(i-d[i] >= 0) t[++cnt1] = i-d[i];
		if(i+d[i] < n) t[++cnt1] = i+d[i];
		d[i] = n-d[i];
		if(i-d[i] >= 0) t[++cnt1] = i-d[i];
		if(i+d[i] < n) t[++cnt1] = i+d[i];
		sort(t+1, t+cnt1+1);
		for(int j = cnt1; j >= 1; j--)
			add(i, t[j]);
	}
	if(hungarian() != n) printf("No Answer");
	else {
		for(int i = 0; i < n; i++)
			an[match[i]] = i;
		for(int i = 0; i < n-1; i++)
			printf("%d ", an[i]);
		printf("%d\n", an[n-1]);
	}
	return 0;
}