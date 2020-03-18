#include<stdio .h>
#include<math .h>
#define N 1010
#define T 15
#define B 25
#define eps 1e-3
#define INF 1e30
struct CPoint
{
	double x,y;
}p[N];
struct Houxuan
{
	double x,y,d;
}q[T],tmp,tt;
double sqr(double x)
{
	return x*x;
}
double dis(double x,double y,double z,double w)
{
	return sqrt(sqr(x-z)+sqr(y-w));
}
double min(double x,double y)
{
	return x>y?y:x;
}
double max(double x,double y)
{
	return x<y ?y:x;
}
int main()
{
	int t,n,i,j,k;
	double width,length,delta,th;
	double pi = acos(-1);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %lf %d",&width,&length,&n);
		for(i = 0 ; i < n ; i++)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		for(i = 0 ; i < T ; i++)
		{
			q[i].x = rand()%1001*width/1000;
			q[i].y = rand()%1001*length/1000;
			q[i].d = INF;
			for(j = 0 ; j < n ; j++)
				q[i].d = min(q[i].d,dis(q[i].x,q[i].y,p[j].x,p[j].y));
		}
		delta = max(width,length)/sqrt(n);
		while(delta > eps)
		{
			for(i = 0 ; i < T ; i++)
			{
				tt = q[i];
				for(j = 0 ; j < B ; j++)
				{
					th = rand()%1001*pi*2/1000;
					tmp.x = tt.x + delta*sin(th);
					tmp.y = tt.y + delta*cos(th);
					if(tmp.x > width || tmp.x <0 || tmp.y > length || tmp.y < 0) continue;
					tmp.d = INF;
					for(k = 0 ; k < n ; k++)
						tmp.d = min(tmp.d, dis(tmp.x,tmp.y,p[k].x,p[k].y));
					if(tmp.d > q[i].d)q[i] = tmp;
				}
			}
			delta *= 0.86;
		}
		j = 0;
		for(i = 1 ; i < T ; i++)
			if( q[i].d > q[j].d ) j = i;
		printf("The safest point is (%.1lf, %.1lf).\n",q[j].x,q[j].y);
	}
	return 0;
}