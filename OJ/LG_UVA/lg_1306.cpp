#include <cstdio>
#define M 100000000
#define N 2
typedef long long ll;

struct Mat
{
    ll m[N][N];
}e, x;

void init()
{
    for(int i = 0; i < N; i++)
        e.m[i][i] = 1;
    x.m[0][0] = 1, x.m[0][1] = 1;
    x.m[1][0] = 1, x.m[1][1] = 0;
}

ll gcd(ll a, ll b)
{
    return (a%b == 0) ? b : gcd(b, a%b);
}

Mat Mul(Mat a, Mat b)
{
    Mat tmp;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            tmp.m[i][j] = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                tmp.m[i][j] = (tmp.m[i][j]+(a.m[i][k]%M)*(b.m[k][j]%M))%M;
    return tmp;
}

Mat power(Mat a, ll b)
{
    Mat ans = e;
    while(b)
    {
        if(b&1)
            ans = Mul(a, ans);
        a = Mul(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    ll g = gcd(n, m);
    init();
    if (g == 1 || g == 2)
        printf("1\n");
    else
    {
        Mat ans = power(x, g-2);
        ll d = (ans.m[0][0]+ans.m[0][1])%M;
        printf("%lld\n", d);
    }
}
