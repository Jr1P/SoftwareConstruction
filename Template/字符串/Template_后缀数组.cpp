#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000050
#define M 123

int c[N], sa[N], x[N] ,y[N], rk[N], height[N];
int n;
char s[N];

void buildSA(int m)
{
	int i;
	memset(c, 0, sizeof(c));
	for(i = 0; i < n; i++) c[x[i] = s[i]]++;
	for(i = 1; i < m; i++) c[i] += c[i-1];
	for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1)
	{
		int p = 0;
		for(i = n-k; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++)
			if(sa[i] >= k) y[p++] = sa[i]-k;

		memset(c, 0, sizeof(c));
		for(i = 0; i < n; i++) c[x[y[i]]]++;
		for(i = 1; i < m; i++) c[i] += c[i-1];
		for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];

		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for(i = 1; i < n; i++)
			x[sa[i]] = (y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+k] == y[sa[i]+k])?p-1:p++;
		if(p >= n) break;
		m = p;
	}
}

inline void getHeight()
{
	int k = 0;
	for(int i = 0; i < n; i++)
		rk[sa[i]] = i;
	for(int i = 0; i < n; i++)
	{
		if(k) k--;
		int j = sa[rk[i]-1];
		while(s[i+k] == s[j+k]) k++;
		height[rk[i]] = k;
	}
}

int main()
{
	scanf("%s", s);
	n = strlen(s);
	buildSA(M);
	for(int i = 0; i < n; i++)
		printf("%d ", sa[i]);
	return 0;
}