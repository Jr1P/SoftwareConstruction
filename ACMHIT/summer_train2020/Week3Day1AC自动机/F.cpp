#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 5e4+5;
const int L_T = 2e6+5;
const int SZ = 26;
int n, tot;

int trie[N][SZ], fail[N], cnt[N], pos[N];
bool e[N];
char txt[L_T], str[1005][55];

inline void push(int root) {
    for(int id = 0; id < SZ; id++)
        trie[root][id] = 0;
    fail[root] = 0; e[root] = 0;
}

void insert(char* c, int x, int root = 0) {
	int id, len = strlen(c);
	for(int i = 0; i < len; i++) {
		id = c[i]-'A';
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

void query(char* txt) {
	int root = 0;
	for(int i = 0; txt[i]; i++) {
        if(txt[i] < 'A' || txt[i] > 'Z') {
            root = 0; continue;
        }
		int id = txt[i]-'A';
		root = trie[root][id];
		for(int j = root; j; j = fail[j])
			if(e[j]) cnt[pos[j]]++;
	}
	for(int i = 1; i <= n; i++)
        if(cnt[i]) printf("%s: %d\n", str[i], cnt[i]);
}

int main() {
	while(~scanf("%d", &n) && n) {
        tot = 0;
        for(int i = 1; i <= n; i++) cnt[i] = 0;
        for(int id = 0; id < SZ; id++)
            trie[0][id] = 0;
        fail[0] = 0; e[0] = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%s", str[i]);
            insert(str[i], i);
        }
        getFail();
        scanf("%s", txt);
        query(txt);
    }
	return 0;
}