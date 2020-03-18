#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 160
#define L 80
#define L_T 1000500
#define SZ 26
//lg 3796
int n, tot;
int trie[N*L][SZ], fail[N*L], cnt[N], pos[N*L];
//fail为失配指针, cnt每个模式串成功匹配次数, pos为编号
bool e[N*L]; //表示是否为结尾
char txt[L_T], str[N][L];

inline void init()
{
	tot = 0;
	memset(trie, 0, sizeof(trie));
	memset(fail, 0, sizeof(fail));
	memset(cnt, 0, sizeof(cnt));
	memset(e, false, sizeof(e));
	memset(pos, 0, sizeof(pos));
}

void insert(char* c, int x, int root = 0)
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
	pos[root] = x;
}

void getFail()
{
	queue<int > q;
	int root = 0;
	for(int id = 0; id < SZ; id++)
		if(trie[root][id])
		{
			fail[trie[root][id]] = 0;
			q.push(trie[root][id]);
		}
	while(!q.empty())
	{
		root = q.front();
		q.pop();
		for(int id = 0; id < SZ; id++)
			if(trie[root][id])
			{
				q.push(trie[root][id]);
				fail[trie[root][id]] = trie[fail[root]][id];
			}
			else
				trie[root][id] = trie[fail[root]][id];
	}
}

void query(char* txt)
{
	int root = 0, max = -1;
	for(int i = 0; txt[i]; i++)
	{
		int id = txt[i]-'a';
		root = trie[root][id];
		for(int j = root; j; j = fail[j])
			if(e[j])
			{
				cnt[pos[j]]++;
				max = (cnt[pos[j]] > max)?cnt[pos[j]]:max;
			}
	}
	printf("%d\n", max);
	vector<int > v;
	for(int i = 1; i <= n; i++)
		if(max == cnt[i])
			v.push_back(i);
	for(unsigned i = 0; i < v.size(); i++)
		printf("%s\n", str[v[i]]);
}

int main()
{
	scanf("%d", &n);
	while(n)
	{
		init();
		for(int i = 1; i <= n; i++)
		{
			scanf("%s", str[i]);
			insert(str[i], i);
		}
		getFail();
		scanf("%s", txt);
		query(txt);
		scanf("%d", &n);
	}
	return 0;
}