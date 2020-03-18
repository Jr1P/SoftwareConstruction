#include <cstdio>
#define Q 500050
#define eps 1e-8

int q;
int a[Q];
long long sum[Q];

int main()
{
	scanf("%d", &q);
	int cnt = 0, max = 0;
	while(q--)
	{
		char t;
		getchar();
		scanf("%c", &t);
		if(t == '1')
		{
			scanf("%d", &a[++cnt]);
			max = a[cnt];
			sum[cnt] = sum[cnt-1]+a[cnt];
		}
		else
		{
			int l = 1, r = cnt;
			double a1 = 0.0, a2 = 0.0, a3 = 0.0;
			while(l < r-2)
			{
				if(l == r-2)
					break;
				int mid = (l+r)>>1;
				int rmid = (mid+r)>>1;
				a1 = (double)(sum[mid]+max)/(double)(mid+1);
				a2 = (double)(sum[rmid]+max)/(double)(rmid+1);
				if(a2-a1 > eps)
					r = rmid;
				else 
					l = mid;
				//else break;
			}
			a1 = (double)(sum[l]+max)/(double)(l+1);
			a2 = (double)(sum[l+1]+max)/(double)(l+2);
			a3 = (double)(sum[r]+max)/(double)(r+1);
			if(a1-a2 > eps && r-l >= 1)
				a1 = a2;
			if(a2-a3 > eps && r-l == 2)
				a1 = a3;
			double mm = (double)max;
			printf("%.10f\n", mm-a1);
		}
	}
	return 0;
}