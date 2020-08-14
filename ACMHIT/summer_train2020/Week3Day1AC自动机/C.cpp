#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 3e4+5;
const int SZ = 2;

int trie[N][SZ], fail[N], e[N];
int n, tot;
bool vis[N << 1], dang[N << 1], insta[N << 1];
vector<int > G[N << 1];

inline void insert(char* c, int root = 0) {
	int id;
	for(int i = 0; c[i]; i++) {
		id = c[i]-'0';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
    dang[root] = 1;
}

inline void getFail() {
	queue<int > q;
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
                if(dang[fail[trie[root][id]]]) dang[trie[root][id]] = 1;
			} else trie[root][id] = trie[fail[root]][id];
	}
}

bool dfs(int u) {
    if(insta[u]) return true;
    if(dang[u] || vis[u]) return false;
    vis[u] = insta[u] = 1;
    for(int i = 0; i < SZ; i++)
        if(dfs(trie[u][i])) return true;
    insta[u] = 0;
    return false;
}

int main() {
    char s[N];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s);
        insert(s);
    }
    getFail();
    if(dfs(0)) puts("TAK");
    else puts("NIE");
	return 0;
}