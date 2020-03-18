#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 30
#define L 15
#define L_T 1050000
#define SZ 26

int n, m, tot;
int trie[N*L][SZ];
bool e[N*L], mark[L_T];
char txt[L_T];

void insert(char* c, int root = 0)
{
	int id, len = strlen(c);
	for(int i = 0; i < len; i++)
	{
		id = c[i]-'a';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	e[root] = 1;
}

void find(char* s)
{
    int ans = 0,root = 0, l = strlen(s);
    memset(mark, 0, sizeof(mark)); 
    for(int i = 0; i < l; i++)
        {
            int id = s[i]-'a';
            root = trie[root][id];
            if(!root)
            	break;
            if(e[root])
            	mark[i] = 1;
        }
    for(int i = 0; i < l; i++)
    {
        if(!mark[i])
        	continue;
        else 
        	ans = i+1;
       	root = 0;
        for(int j = i+1; j < l; j++)
        {
            int id = s[j]-'a';
            root = trie[root][id];
            if(!root)
            	break;
            if(e[root])
            	mark[j] = 1;
        }
    }
    printf("%d\n",ans);
}

int main()
{
	char str[L];
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", str);
		insert(str);
	}
	while(m--)
	{
		scanf("%s", txt);
		find(txt);
	}
	return 0;
}