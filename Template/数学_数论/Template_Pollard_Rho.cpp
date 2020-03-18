#include<bits/stdc++.h>
#define gc getchar
#define ll long long
using namespace std;

ll Ans;
int n;
ll rd() {
    ll ans = 0,flag = 1;
    char ch = gc();
    while((ch>'9'||ch<'0') && ch != '-') ch = gc();
    if(ch == '-') flag=-1;
    while(ch>='0'&&ch<='9') ans = (ans<<3)+(ans<<1)+ch-'0', ch=gc();
    return flag*ans;
}

inline ll qpow(ll x, ll a, ll mod) {
    ll ans = 1;
    while(a) {
        if(a&1) ans = ans*x%mod;
        a>>=1,x=x*x%mod;
    }
    return ans;
}

inline bool test(ll x, ll p) {
    return qpow(x, p-1, p) == 1;
}

inline bool Miller_Rabin(ll x, ll p) {
    if(!test(x, p))
        return false;
    ll k = p-1;
    while(!(k&1)) {
        k >>= 1;
        ll t = qpow(x, k, p);
        if( t!= 1 && t != p-1) return false;
        if(t == p-1) return true;
    }
    return true;
}

inline bool Test(ll p)
{
    if(p == 1) return false;
    if(p == 2 || p == 3 || p == 5 || p == 7 || p == 11) return true;
    return Miller_Rabin(2, p)&&Miller_Rabin(3, p)&&Miller_Rabin(5, p)&&Miller_Rabin(7, p);
}
 
inline ll qmul(ll x, ll y, ll mod) {
    return (x*y-(long long)((long double)x/mod*y)*mod+mod)%mod;
}

inline ll gcd(ll x,ll y) {
    return y?gcd(y,x%y):x;  
}
 
void Pollard_Rho(ll x)  {
    if(Test(x)) {
        Ans=max(x,Ans);
        return; 
    }
    ll t1 = rand()%(x-1)+1;
    ll t2 = t1, b = rand()%(x-1)+1;
    t2 = (qmul(t2,t2,x)+b)%x;
    ll p = 1, i = 0;
    while(t1!=t2) {
        ++i;
        p = qmul(p,abs(t1-t2),x);
        if(p == 0) {
            ll t = gcd(abs(t1-t2), x);
            if(t!=1&&t!=x) 
                Pollard_Rho(t),Pollard_Rho(x/t);    
            return;
        }
        if(i%127==0) {
            p=gcd(p,x);
            if(p!=1&&p!=x) {
                Pollard_Rho(p),Pollard_Rho(x/p);
                return;
            }
            p=1;
        }
        t1=(qmul(t1,t1,x)+b)%x;
        t2=(qmul(t2,t2,x)+b)%x;
        t2=(qmul(t2,t2,x)+b)%x;
    }
    p = gcd(p,x);
    if(p != 1&& p != x) {
        Pollard_Rho(p),Pollard_Rho(x/p);
        return;
    }
 
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        ll t;
        scanf("%lld", &t);
        if(Test(t)) {
            printf("Prime\n");
            continue;
        }
        Ans = 0;
        while(Ans == 0)
            Pollard_Rho(t);
        printf("%lld\n", Ans);
    }
    return 0;
}