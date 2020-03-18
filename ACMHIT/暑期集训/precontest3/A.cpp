#include <cstdio>

typedef long long ll;

int t;
ll r, R;

int main() {
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld", &R, &r);
		if(R*R > r*r*2)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}