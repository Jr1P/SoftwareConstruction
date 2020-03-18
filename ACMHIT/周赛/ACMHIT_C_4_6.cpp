#include <stdio.h>
using namespace std;
const char ch[] ="DABC";
const int MAXL = 1e5+5;

int a[MAXL], t[5] = {0, 0, 0, 0, 0};

int main()
{
	int n, mod;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		mod = i % 4;
		t[mod] += a[i];
	}
	int max = t[0], p = 0;
	for (int i = 1; i < 4; i++)
		if (max < t[i])
		{
			max = t[i];
			p = i;
		}
	if (max == t[1])
		p = 1;
	else if (max == t[2])
		p = 2;
	else if (max == t[3])
		p = 3;
	else
	{} 
	printf("%c\n", ch[p]);
	return 0;
}