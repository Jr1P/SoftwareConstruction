#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
#define L_T 1000050
#define SZ 26

int trie[L_T][SZ], fail[L_T], e[L_T];
int n, tot;
string s;

inline void insert(string& c, int root = 0)
{
	int id, len = c.length();
	for(int i = 0; i < len; i++)
	{
		id = c[i]-'a';
		if(!trie[root][id])
			trie[root][id] = ++tot;
		root = trie[root][id];
	}
	e[root]++;
}

inline void getFail()
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
				fail[trie[root][id]] = trie[fail[root]][id];
				q.push(trie[root][id]);
			}
			else
				trie[root][id] = trie[fail[root]][id];
	}
}

void query(string& txt)
{
	int res = 0, root = 0, id;
	for(unsigned i = 0; i < txt.length(); i++)
	{
		id = txt[i]-'a';
		root = trie[root][id];
		for(int j = root; j && e[j] != -1; j = fail[j])
		{
			res += e[j];
			e[j] = -1;
		}
	}
	printf("%d\n", res);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		cin >> s;
		insert(s);
	}
	getFail();
	cin >> s;
	query(s);
	return 0;
}