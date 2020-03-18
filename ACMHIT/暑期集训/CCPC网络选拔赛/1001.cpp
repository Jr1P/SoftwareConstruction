#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

ll t;
ll aa[35], bb[35];

int main()
{
    scanf("%lld", &t);
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        for(int i = 0; i <= 34; i++) aa[i] = (long long)0, bb[i] = (long long)0;
        ll tot = (ll)0;
        while (a)
        {
            aa[++tot] = a & (ll)1;
            a >>= 1;
        }
        tot = (ll)0;
        while (b)
        {
            bb[++tot] = b & (ll)1;
            b >>= 1;
        }
        ll c = 0;
        for (ll i = 1ll; i <= (ll)33; i++)
        {
            if (aa[i] == 1ll && bb[i] == 1ll)
            {
                c += (ll)1 << (i - 1ll);
            }
        }
        if(c == 0) c++;
        cout << c << endl;
    }
}
