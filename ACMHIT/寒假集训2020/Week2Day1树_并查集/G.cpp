#include<cstdio>
#include<iostream>

const int N = 30010;
int father[N], size[N], dep[N];
 
int find(int x) {
	if(x == father[x])
		return x;
	int tmp = father[x];
	father[x] = find(tmp);
	dep[x] += dep[tmp];
	return father[x];
}

inline void init() {
    for(int i = 0; i < N; ++i) {
		father[i] = i;
		size[i] = 1;
		dep[i] = 0;
	}
}

inline void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 != f2) {
        father[f2] = f1;
        dep[f2] = size[f1];
        size[f1] += size[f2];
    }
}

int main() {
	int m;
	scanf("%d", &m);
	init();
	while(m--) {
        char type;
        int x, y;
        getchar();
	    type = getchar();
		if(type == 'M') {
			scanf("%d%d", &x, &y);
			_union(x, y);
		}
		else {
			scanf("%d", &x);
			printf("%d\n", size[find(x)] - dep[x] - 1);
		}
	}
	return 0;
}