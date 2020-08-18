#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e4+5;
const int L = 50;
const int SZ = 26;
const int M = 1000005;

int trie[N*L][SZ], fail[N*L], e[N*L];
int n, tot;

inline void push(int root) {
    for(int i = 0; i < SZ; i++)
        trie[root][i] = 0;
}

inline void insert(char* c, int root = 0) {
	int id;
	for(int i = 0; c[i]; i++) {
		id = c[i]-'a';
		if(!trie[root][id]) {
			trie[root][id] = ++tot;
			push(tot);
		}
		root = trie[root][id];
	}
	e[root]++;
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
			} else trie[root][id] = trie[fail[root]][id];
	}
}

void query(char* txt) {
	int res = 0, root = 0, id;
	for(unsigned i = 0; txt[i]; i++) {
		id = txt[i]-'a';
		root = trie[root][id];
		for(int j = root; j && e[j] != -1; j = fail[j]) {
			res += e[j];
			e[j] = -1;
		}
	}
	printf("%d\n", res);
}

int main() {
	int T;
    scanf("%d", &T);
	while(T--) {
        memset(e, 0, sizeof(e));
		char s[M];
		scanf("%d", &n);
		for(int i = 0; i < SZ; i++) trie[0][i] = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%s", s);
			insert(s);
		}
		getFail();
		scanf("%s", s);
		query(s);
	}
	return 0;
}