#include <cstdio>
const int MAXT = 1e5;
int x[5], y[5], t;

bool vertical(int x1, int x2)
{
	return (x1 == x2) ? 1 : 0;
}

bool valid(int ax, int ay)
{
	if()
}
// y = y1+k1(x-x1)
// y = y3+k2(x-x3)
//k2 = (y4-y3)/(x4-x3)
//k1 = (y2-y1)/(x2-x1)

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		float ax, ay, k1, k2; // 交点坐标, 两直线斜率
		for(int i = 1; i <= 4; i++)
			scanf("%d%d", &x[i], &y[i]);
		if (vertical(x[1], x[2]) && vertical(x[3], x[4]))
			printf("NO\n");
		else if (vertical(x[1], x[2]) && !vertical(x[3], x[4]))
		{
			k2 = (y[4]-y[3])/(x[4]-x[3]);
			ax = x[1]; ay = y[3]+k2*(ax-x[3]);
			if (ay)
		}

	}
	return 0;
}