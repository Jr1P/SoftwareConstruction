#include <cstdio>
const int MAXN = 1e4+1;
double l[MAXN], p[MAXN];
int n, t;
double S, H, V;


int main()
{
	double ans;
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%lf%lf", &l[i], &p[i]);
		scanf("%lf%lf%lf", &S, &H, &V);
		double hw=V/S;
		double v=0;
		for(int i = 1; i <= n; i++){
			if(p[i]>=1){
				v+=l[i]*l[i]*l[i];
			}else{
				v+=l[i]*l[i]*l[i]*p[i];
			}
		}
		double delta=v/S;
		if(delta+hw>H){
			ans=H;
		}else
			ans=delta+hw;
		printf("%.2f\n", ans);
	}
	return 0;
}