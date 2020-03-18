#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
const int MAXN = 100000+5;
using namespace std;
typedef long long ll;
int n, m, t, l[MAXN]; //学生人数m, 宿舍数n, l[i]宿舍的生活质量

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int left = 0, right = 0, sum = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &l[i]);
			if (right < l[i])
				right = l[i];
		}
		while (left < right-1)
		{
			sum = 0;
			int mid = (left + right) >> 1;
			for(int i = 1; i <= n; i++)
				sum += l[i]/mid;
			if (sum >= m)
				left = mid;
			else 
				right = mid;
		}
		sum = 0;
		for(int i = 1; i <= n; i++)
			sum += l[i]/right;
		if(sum >= m)
			printf("%d\n", right);
		else
			printf("%d\n", left);
	}
	return 0;
}