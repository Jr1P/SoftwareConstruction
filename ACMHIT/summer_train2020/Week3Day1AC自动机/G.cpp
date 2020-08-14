#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int N = 1e5+5;
const int SZ = 26;

int cn, len, strcnt, tot;
int trie[N][SZ], fail[N], cnt[N], l[N], r[N], fa[N], strID[N], head[N];
int tree[N];

struct Edge {
    int v, nxt;
    Edge() {}
    Edge(int v, int nxt) : v(v), nxt(nxt) {}
} e[N];

inline void add(int u, int v) {
    e[++cn] = Edge(v, head[u]);
    head[u] = cn;
}

inline int lowbit(int x) { return x&(-x); }
inline int sum(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}
inline int change(int x, int val) {
    for(int i = x; i <= tot + 1; i += lowbit(i))
        tree[i] += val;
}

inline void insert(char* c, int root = 0) {
	for(int i = 0; c[i]; i++) {
	    int id = c[i]-'a';
        if(c[i] == 'P') strID[++strcnt] = root;
        else if(c[i] == 'B') { root = fa[root]; }
        else {
            if(!trie[root][id]) {
                trie[root][id] = ++tot;
                fa[trie[root][id]] = root;
            }
            root = trie[root][id];
        }
	}
}

inline void getFail() {
	std::queue<int > q;
	int root = 0;
	for(int id = 0; id < SZ; id++)
		if(trie[root][id]) {
			fail[trie[root][id]] = 0;
			q.push(trie[root][id]);
		}
	while(!q.empty()) {
		root = q.front();
		q.pop();
		for(int id = 0; id < SZ; id++)
			if(trie[root][id]) {
				fail[trie[root][id]] = trie[fail[root]][id];
				q.push(trie[root][id]);
			} else trie[root][id] = trie[fail[root]][id];
	}
}

void dfs(int u) {
    l[u] = ++len;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        dfs(v);
    }
    r[u] = len;
}

struct Query {
    int x, id;
};

int ans[N];
std::vector<Query> Q[N];

int main() {
    char s[N];
    scanf("%s", s);
    insert(s);
    getFail();
    for(int i = 1; i <= tot; i++) add(fail[i], i);
    dfs(0);
    int q;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        Q[y].push_back((Query){x, i});
    }
    strcnt = 0;
    int root = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == 'P') {
            strcnt++;
            for(int j = 0; j < Q[strcnt].size(); j++) {
                int x = strID[Q[strcnt][j].x];
                ans[Q[strcnt][j].id] = sum(r[x])-sum(l[x]-1);
            }
        } else if(s[i] == 'B') change(l[root], -1), root = fa[root];
        else {
            int id = s[i]-'a';
            root = trie[root][id];
            change(l[root], 1);
        }
    }
    for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}