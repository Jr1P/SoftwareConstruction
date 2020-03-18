#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 30

int n, cnt = 0;
int num[N];
int a[N], b[N], c[N], Next[N];
char s1[N], s2[N], s3[N];
bool used[N];

bool judge()
{
	int x = 0;
	for(int i = n-1; i >= 0; i--)
	{
		int A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if ((A+B+x)%n != C)
			return false;
		x = (A+B+x)/n;
	}
	return true;
}

bool pr() // 剪枝
{
	if (num[a[0]]+num[b[0]] >= n)
		return true;
	for(int i = n-1; i >= 0; i--)
	{
		int A = num[a[i]], B = num[b[i]], C = num[c[i]];
		if (A == -1 || B == -1 || C == -1)
			continue;
		if((A+B)%n != C && (A+B+1)%n != C)
            return true;
	}
	return false;
}

void print()
{
	for(int i = 0; i < n; i++)
		printf("%d ", num[i]);
}

inline int get(char x)
{
	return x - 'A';
}

void GetNext(int x) 
{
    if(used[x] == false) 
    {
        used[x] = true;
        Next[cnt++] = x;
    }
    return ;
}

void dfs(int x)
{
	if (pr())
		return ;
	if (x == n)
	{
		if(judge())
		{
			print();
			exit(0);
		}
		return ;
	}
	for(int i = n-1; i >= 0; i--)
		if (!used[i])
		{
			num[Next[x]] = i;
			used[i] = true;
			dfs(x+1);
			num[Next[x]] = -1;
			used[i] = false;
		}
	return ;
}

int main()
{
	
	scanf("%d", &n);
	scanf("%s%s%s", s1, s2, s3);
	for(int i = 0; i < n; i++)
	{
		a[i] = get(s1[i]);
		b[i] = get(s2[i]);
		c[i] = get(s3[i]);
		num[i] = -1;
	}
	for(int i = n-1; i >= 0; i--)
	{
        GetNext(a[i]);
        GetNext(b[i]);
        GetNext(c[i]);
    }
    for(int i = 0; i < n; i++)
    	used[i] = false;
	dfs(0);
	return 0;
}