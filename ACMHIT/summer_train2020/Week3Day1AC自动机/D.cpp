#include <cstdio>
#include <cstring>
#include <queue>
const int mod = 1e4+7;
const int N = 6050;
const int L_T = 2e6+5;
const int SZ = 26;
int n, tot, m;

int trie[N][SZ], fail[N], dp[500][N];
bool e[N];
char txt[L_T], str[105];

void insert(char* c, int root = 0) {
	int id, len = strlen(c);
	for(int i = 0; i < len; i++) {
		id = c[i]-'A';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	e[root] = 1;
}

void getFail() {
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
		for(int id = 0; id < SZ; id++) {
			int child = trie[root][id];
			if(child) {
				q.push(child);
				fail[child] = trie[fail[root]][id];
				if(e[trie[fail[root]][id]]) e[child] = e[trie[fail[root]][id]];
			} else trie[root][id] = trie[fail[root]][id];
		}
	}
}

void DP() {
	for(int num = 1; num <= m; num++)
		for(int i = 0; i <= tot; i++) {
			for(int j = 0; j < SZ; j++) {
				if(!e[trie[i][j]]) 
					dp[num][trie[i][j]] = (dp[num][trie[i][j]]+dp[num-1][i])%mod;
			}
		}
}

int main() {
	scanf("%d%d", &n, &m);
    tot = 0;
    e[0] = 0; fail[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%s", str);
        insert(str);
    }
    getFail();
    dp[0][0] = 1;
    int ans = 0, all = 1;
    for(int i = 1; i <= m; i++) all = (all*SZ)%mod;
    DP();
    for(int i = 0; i <= tot; i++) ans = (ans+dp[m][i])%mod;
    printf("%d\n", ((all-ans)%mod+mod)%mod);
	return 0;
}
