#include <cstdio>
#include <queue>
#define N 1000050

int s, t;
int depth[2][N];

std::queue<int > q[2];

inline bool check(int x, int flag) {
	if((x <= 0 || x >= 1e7) || depth[flag][x]) return false;
	return true;
}

void bfs(int s, int t) {
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
	q[0].push(s); q[1].push(t);
	depth[0][s] = 1; depth[1][t] = 1;
	bool flag;
	while(!q[0].empty() && !q[1].empty()) { // flag == 0 : q[0]队列, flag == 1 ： q[1]队列
		if(q[0].size() > q[1].size())
			flag = 1;
		else
			flag = 0;
		int now = q[flag].front(), len = 2, tmp[3];
		q[flag].pop();
		if(!flag) { // flag == 0
			tmp[0] = (now << 1) + now;
			tmp[1] = now >> 1;
		} else {
			tmp[0] = now << 1;
			tmp[1] =  now << 1 | 1;
			tmp[2] = now / 3;
			if(now % 3 == 0) len = 3;
		}
		for(int i = 0; i < len; i++) {
			if(depth[flag ^ 1][tmp[i]]) {
				printf("%d\n", depth[flag ^ 1][tmp[i]] + depth[flag][now] - 1);
				return ;
			}
			if(check(tmp[i], flag)) {
				depth[flag][tmp[i]] = depth[flag][now] + 1;
				q[flag].push(tmp[i]);
			}
		}
	}
}

int main() {
	scanf("%d%d", &s, &t);

	bfs(s, t);
	return 0;
}