#include <cstdio>
#include <cstring>
#define SZ 26
#define N 10010
#define L 55
//lg_2580
const char c1[] = "OK";
const char c2[] = "REPEAT";
const char c3[] = "WRONG";

int trie[N*L][SZ];
int tot, n, m;
char str[N][L];
bool flag[N*L], e[N*L];//flag:是否被点名过, e:是否为结尾

inline void Insert(char* c, int root = 0) {
	int len = strlen(c), id;
	for(int i = 0; i < len; i++) {
		id = c[i]-'a';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	e[root] = true;
}

inline void Inquiry(char* c, int root = 0) { //查询是否出现过
	int len = strlen(c), id;
	for(int i = 0; i < len; i++) {
		id = c[i]-'a';
		if (!trie[root][id])
		{
			printf("%s\n", c3);
			return ;
		}
		else
			root = trie[root][id];
	}
	if (!flag[root] && e[root]) {
		flag[root] = true;
		printf("%s\n", c1);
	} else if(!e[root]) printf("%s\n", c3);
	else printf("%s\n", c2);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", str[i]);
		Insert(str[i]);
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		char q[L];
		scanf("%s", q);
		Inquiry(q);
	}
	return 0;
}