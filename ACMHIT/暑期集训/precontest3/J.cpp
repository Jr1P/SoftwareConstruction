#include <cstdio>

int p[2], k, l[2], r[2], d[2];
int t;

/*void check(int x)
{

}
*/
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int ans = 0;
		scanf("%d%d%d%d", &l[0], &r[0], &p[0], &d[0]);
		scanf("%d%d%d%d", &l[1], &r[1], &p[1], &d[1]);
		scanf("%d", &k);
		if(d[0] == 0) d[0] = -1;
		if(d[1] == 0) d[1] = -1;
		for(int i = 1; i <= k; i++) {
			if(p[0] == p[1]) ++ans;
			if(p[0] == l[0] && d[0] == -1)
				d[0] = 1;
			else if(p[0] == r[0] && d[0] == 1)
				d[0] = -1;
			p[0] += d[0];
			if(p[1] == l[1] && d[1] == -1)
				d[1] = 1;
			else if(p[1] == r[1] && d[1] == 1)
				d[1] = -1;
			p[1] += d[1];
		}
		if(p[0] == p[1]) ++ans;
		printf("%d\n", ans);
	}
	return 0;
}