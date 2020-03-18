#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e9+50;
const int K = 1e5+10;
const ll M = 1e9+9;

ll n, k;
ll a, b, x, y;
string str;

ll ksm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if (b&1) ans = ans*a%M;
		a = a*a%M;
		b >>= 1;
	}
	return (ans%M+M)%M;
}

ll exgcd(ll a, ll b) {
	if(!b) {
		x = 1; y =0;
		return a;
	}
	ll gcd = exgcd(b, a%b);
	ll x2 = x, y2 = y;
	x = y2;
	y = x2-(a/b)*y2;
	return gcd;
}

int main()
{
	scanf("%lld%lld%lld%lld", &n, &a, &b, &k);
	cin >> str;
	ll f, s = 0, len = (n+1)/k;
	for(unsigned i = 0; i < str.length(); i++) {
		if(str[i] == '-') f = -1;
		else f = 1;
		s = ((s+f*ksm(a, n-i)*ksm(b, i))%M+M)%M;
	}
	s = (s+M)%M;
	ll ans;
	exgcd(a, M);
	ll q = ksm(x, k)*ksm(b, k)%M;
    if(q != 1){
         exgcd(q-1, M);
         ans = (s*(ksm(q, len)-1)%M*x%M+M)%M;
    } else {
        ans = s*len%M;
    }
	printf("%lld\n", ans);
	return 0;
}
