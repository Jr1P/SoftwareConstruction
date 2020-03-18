#include <cstdio>

int t, a, b, c, d, gcd_bd, lcm_ac;

inline int gcd(int a, int b)
{
	return (a%b==0)?b:gcd(b, a%b);
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a /= gcd(a, b);
		b /= gcd(a, b);
		c /= gcd(c, d);
		d /= gcd(c, d);
		gcd_bd = gcd(b, d);
		lcm_ac = a*c/gcd(a, c);
		if(lcm_ac%gcd_bd)
			printf("%d/%d\n", lcm_ac, gcd_bd);
		else
		{	
			int ans = lcm_ac/gcd_bd;
			printf("%d\n", ans);
		}
	}
	return 0;
}