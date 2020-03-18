#include <cstdio>
#include <queue>
using namespace std;
#define N 200050

int n, k, cnt;
long long dis[N];
int head[N], tim[N];
bool exist[N];
int q[N*50];

struct Edge
{
	long long w;
	int v, next;
}e[N<<1];

inline int read(){
    int x = 0;
    char c = getchar();
    bool flag = 0;
    while(c < '0' || c > '9'){
   		if(c == '-')
   			flag = 1;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9'){
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return flag ? -x : x;
}

inline void add(int u, int v, int w) {
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

bool spfa(int s) {
	int h = 0, t = 1;
	q[h++] = s;
	t++;
	exist[s] = true;
	tim[s] = 1;
	while(h != t) {
		int u = q[h];
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(dis[v] < dis[u]+e[i].w) {
				dis[v] = dis[u]+e[i].w;
				if(!exist[v]) {
					q[t++] = v; exist[v] = true;
					tim[v]++;
					if(tim[v] >= n)
						return true;
				}
			}
		}
		exist[u] = false;
		h++;
	}
	return false;
}

int main() {
	n = read();
	k = read();
	for(int i = 0; i <= n; i++) {
		dis[i] = 0;
		head[i] = -1;
		tim[i] = 0;
		exist[i] = false;
	}
	int s = 0;
	for(int i = 1; i <= k; i++) {
		int x, u, v;
		x = read(); u = read(); v = read();
		if(x == 1) add(u, v, 0), add(v, u, 0);
		else if(x == 2) {
			if(u == v) {
				printf("-1\n");
				return 0;
			}
			add(u, v, 1);
		}
		else if(x == 3)
			add(v, u, 0);
		else if(x == 4)  {
			if(u == v) {
				printf("-1\n");
				return 0;
			}
			add(v, u, 1);
		}
		else add(u, v, 0);
	}
	for(int i = n; i >= 1; i--)
		add(s, i, 1);
	if(spfa(s))
		printf("-1\n");
	else {
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			ans += dis[i];
		printf("%lld\n", ans);
	}
	return 0;
}