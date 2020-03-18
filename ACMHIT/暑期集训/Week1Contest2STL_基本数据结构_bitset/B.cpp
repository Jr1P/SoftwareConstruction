#include <cstdio>
#include <deque>
#include <algorithm>
using namespace std;
#define N 100500

int n, t, k;
int a[N<<1], s[N<<1];
deque<int > q;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int max = 0, l = 1, r = 1;
		scanf("%d%d", &n, &k);
		q.clear();
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			a[i+n] = a[i];
		}
		for(int i = 1; i < n+n; i++)
			s[i] = s[i-1]+a[i];
		max = s[1];
		q.push_back(0);
		for(int i = 2; i < n+k; i++)
		{
			while(!q.empty() && s[q.back()] > s[i-1])
				q.pop_back();
			q.push_back(i-1);
			if(i-q.front() > k)
				q.pop_front();
			if(s[i]-s[q.front()] > max)
			{
				max = s[i]-s[q.front()];
				l = q.front()+1;
				r = i;
			}
		}
		if (l > n) l -= n;
		if (r > n) r -= n;
		printf("%d %d %d\n", max, l, r);
	}
	return 0;
}