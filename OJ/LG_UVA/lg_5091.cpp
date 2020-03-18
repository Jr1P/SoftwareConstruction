#include <iostream>
#include <string>
using namespace std;
#define L 20000050
typedef long long ll;

string b;
ll a, m;

ll getphi(ll x)
{
    ll phi = x;
    for(int i = 2; i*i <= x; i++)
    {
        if (x%i == 0)
            phi = phi/i*(i-1);
        while(x%i == 0)
            x /= i;
    }
    if (x > 1) phi = phi/x*(x-1);
    return phi;
}

ll power(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1)
            ans = ans*a%m;
        a = a*a%m;
        b >>= 1;
    }
    return ans%m;
}

int main()
{
    ll y = 0;
    ios::sync_with_stdio(false);
    cin >> a >> m >> b;
    for(unsigned i = 0; i < b.length(); i++)
        y = (y*10+b[i]-'0')%m;
    y = y%getphi(m);
    cout << power(a, y) << '\n';
    return 0;
}
