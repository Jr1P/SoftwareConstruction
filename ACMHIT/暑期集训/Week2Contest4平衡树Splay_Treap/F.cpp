#include <iostream>
#include <algorithm>
const int MAXN = 1e4+1;
const int MAXM = 2e5+1;
using namespace std;

int n, m, father[MAXN], cnt = 0;

struct EDGE 
{
	int u, v, w;
}e[MAXM];

inline int cmp(const EDGE &x, const EDGE &y)
{
	return x.w < y.w;
}

inline int find(int x)
{
	if (father[x] != x)
		father[x] = find(father[x]);
	return father[x];
}

inline bool _union(int x, int y)
{
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2) 
		return false;
	else
		father[f2] = f1;
	return true;
}

int main()
{
    while(1) {
        int MST = 0;
        //ios::sync_with_stdio(false);
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &m);
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        sort(e+1, e+m+1, cmp);
        for(int i = 1; i <= n; i++)
            father[i] = i;
        for(int i = 1; i <= m; i++)
            if(_union(e[i].u, e[i].v))
                MST += e[i].w;
        printf("%d\n", MST);
    }
	return 0;
}//