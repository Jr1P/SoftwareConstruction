#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, q; 

ll gcd(ll a, ll b) {
	return a%b == 0? b: gcd(b, a%b);
}

int main() {
	cin >> n >> m >> q;
	ll g = gcd(n, m);
	if(n == 1 || m == 1 || g == 1)
		for(int i = 1; i <= q; i++)
			puts("YES");
	else {
		for(int i = 1; i <= q; i++){
			ll sx, sy, ex, ey;
			scanf("%lld%lld%lld%lld", &sx, &sy, &ex, &ey);
			ll a = n/g, b = m/g;
			ll l, r;
			sy -= 1;
			if(sx == 1 && ex == 1)
				l = sy/a*a+1, r = sy/a*a+a;
			else if(sx == 2 && ex == 2)
				l = sy/b*b+1, r = sy/b*b+b;
			else if(sx == 1 && ex == 2)
				l = sy/a*b+1, r = sy/a*b+b;
			else
				l = sy/b*a+1, r = sy/b*a+a;
			if(ey >= l && ey <= r)
				puts("YES");
			else puts("NO");
		}
	}
	return 0;
}