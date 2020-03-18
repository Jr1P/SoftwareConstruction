#include <cstdio>
#include <vector>
#include <iostream>
#define N 100050
#define SIZE 2
#define WORD 31

struct Node {
	int v, w;
	Node() {}
	Node(int _v, int _w) : v(_v), w(_w) {}
};

int n, tot, ans, rt, edg;
int trie[N * WORD][SIZE], val[N * WORD], ru[N];
std::vector<Node > tr[N];

inline void init() {
	ans = tot = 0;
	trie[0][0] = trie[0][1] = 0;
	for (int i = 0; i < n; i++) {
		tr[i].clear();
		ru[i] = 0;
	}
}

void insert(int x, int root = 0) {
	int id;
	for(int i = WORD; i >= 0; i--) {
		id = (x >> i) & 1;
		if(!trie[root][id]) {
			trie[root][id] = ++tot;
			trie[tot][0] = trie[tot][1] = 0;
			val[tot] = 0;
		}
		root = trie[root][id];
	}
	val[root] = x;
}

int query(int x, int root = 0) {
	int id;
	for(int i = WORD; i >= 0; i--) {
		id = (x >> i) & 1;
		if(trie[root][!id])
			root = trie[root][!id];
		else root = trie[root][id];
	}
	return x ^ val[root];
}

void dfs(int rt, int val) {
	int len = tr[rt].size();
	insert(val);
	for (int i = 0; i < len; i++) {
		int v = tr[rt][i].v;
		ans = std::max(ans, query(val ^ tr[rt][i].w));
		dfs(v, val ^ tr[rt][i].w);
	}
}

int main() {
	while(~scanf("%d", &n)) {
		init();
		for(int i = 1; i < n; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			tr[u].push_back(Node(v, w));
			ru[v]++;
		}
		for (int i = 0; i < n; i++)
			if (!ru[i]) {
				rt = i;
				break;
			}
		dfs(rt, 0);
		printf("%d\n", ans);
	}
	return 0;
}