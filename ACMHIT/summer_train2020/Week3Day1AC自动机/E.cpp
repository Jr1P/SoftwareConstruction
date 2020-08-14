#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
const int L_T = 1e4+5;
const int SZ = 128;

int n, tot, web;

int trie[N][SZ], fail[N], cnt[N], pos[N];
bool e[N];
char txt[L_T], str[205];

inline void push(int root) {
    for(int id = 0; id < SZ; id++)
        trie[root][id] = 0;
    fail[root] = 0; e[root] = 0;
}

void insert(char* c, int x, int root = 0) {
	int id, len = strlen(c);
	for(int i = 0; i < len; i++) {
		id = c[i];
		if(!trie[root][id]) {
			trie[root][id] = ++tot;
            push(tot);
        }
		root = trie[root][id];
	}
	e[root] = 1;
	pos[root] = x;
}

void getFail() {
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
				q.push(trie[root][id]);
				fail[trie[root][id]] = trie[fail[root]][id];
			} else trie[root][id] = trie[fail[root]][id];
	}
}

void query(int kase, char* txt) {
	int root = 0;
    bool f = false;
    for(int i = 1; i <= n; i++) cnt[i] = 0;
	for(int i = 0; txt[i]; i++) {
		int id = txt[i];
		root = trie[root][id];
		for(int j = root; j; j = fail[j])
			if(e[j]) cnt[pos[j]]++;
	}
	for(int i = 1; i <= n; i++)
        if(cnt[i]) {
            f = true;
            break;
        }
    if(f) {
        web++;
        printf("web %d:", kase);
        for(int i = 1; i <= n; i++)
            if(cnt[i]) printf(" %d", i);
        puts("");
    }
}

int main() {
	while(~scanf("%d", &n) && n) {
        tot = web = 0;
        for(int id = 0; id < SZ; id++)
            trie[0][id] = 0;
        fail[0] = 0; e[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", str);
            insert(str, i);
        }
        getFail();
        int m;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            scanf("%s", txt);
            query(i, txt);
        }
        printf("total: %d\n", web);
    }
	return 0;
}