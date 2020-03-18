#include <cstdio>
#include <queue>
#define N 1000050

struct INT {
	int val, belong;
	bool operator < (const INT& a) const {
		return val > a.val;
	}
	INT() {}
	INT(int _val, int _belong) : val(_val), belong(_belong) {}
};

int n;
int a[N], b[N], end[N];
std::priority_queue<INT > q;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; i++) {
		int c = a[i] + b[1];
		q.push(INT(c, i));
		end[i]++;
	}
	while(n--) {
		int tmp = q.top().val, belong = q.top().belong;
		q.pop();
		end[belong]++;
		printf("%d ", tmp);
		q.push(INT(a[belong] + b[end[belong]], belong));
	}
	return 0;
}
