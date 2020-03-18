#include <cstdio>
#include <cstring>
#define LENGTH 55
#define N 10050
#define SIZE 26

const char s[3][10] = {"OK", "REPEAT", "WRONG"};

int n, m, tot = 0;
int trie[N * LENGTH][SIZE];
bool ended[N * LENGTH], flag[N * LENGTH];

void insert(char *name, int root = 0) {
	unsigned len = strlen(name), id;
	for(unsigned i = 0; i < len; i++) {
		id = name[i] - 'a';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	ended[root] = true;
}

void query(char *name, int root = 0) {
	unsigned len = strlen(name), id;
	for(unsigned i = 0; i < len; i++) {
		id = name[i] - 'a';
		if(!trie[root][id]) {
			printf("%s\n", s[2]);
			return ;
		}
		root = trie[root][id];
	}
	if(flag[root])
		printf("%s\n", s[1]);
	else if(!ended[root])
		printf("%s\n", s[2]);
	else {
		printf("%s\n", s[0]);
		flag[root] = true;
	}

}
int main() {
	scanf("%d", &n);
	char str[LENGTH];
	for(int i = 0; i < n; i++) {
		scanf("%s", str);
		insert(str);
	}
	scanf("%d", &m);
	while(m--) {
		scanf("%s", str);
		query(str);
	}
	return 0;
}