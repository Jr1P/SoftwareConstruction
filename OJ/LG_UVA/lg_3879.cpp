#include <cstdio>
#include <cstring>
#define M 10050 //询问数
#define N 1050 //短文最大篇数
#define L_E 5050 //文章最大长度
#define SZ 26
#define L_L 25 //每个单词最大长度

int n, m, l, tot;
int trie[N][L_E][SZ];
bool e[N][L_E];

void insert(char* c, int x, int root = 0)
{
	int len = strlen(c), id;
	for(int i = 0; i < len; i++)
	{
		id = c[i]-'a';
		if(!trie[x][root][id])
			trie[x][root][id] = ++tot;
		root = trie[x][root][id];
	}
	e[x][root] = 1;
}

bool Inquiry(char* c, int x, int root = 0)
{
	int len = strlen(c), id;
	for(int i = 0; i < len; i++)
	{
		id = c[i]-'a';
		if(!trie[x][root][id])
			return false;
		root = trie[x][root][id];
	}
	if(!e[x][root])
		return false;
	else
		return true; 
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &l);
		tot = 0;
		for(int j = 1; j <= l; j++)
		{
			char word[L_L];
			scanf("%s", word);
			insert(word, i);
		}
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		char word[L_L];
		scanf("%s", word);
		for(int j = 1; j <= n; j++)
			if (Inquiry(word, j))
				printf("%d ", j);
		printf("\n");
	}
	return 0;
}