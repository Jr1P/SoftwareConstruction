#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define M 1000000007
using namespace std;

typedef long long ll;

ll n, b, x, k;
int num[15];

struct Mat {
    long long a[105][105];
}ans, temp, e;

Mat mult(Mat a, Mat b)
{
    Mat c;
    memset(c.a, 0, sizeof(c.a));
    for(int i = 0; i < x; i++)
        for(int j = 0; j < x; j++)
            for(int k = 0; k < x; k++)
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%M;
    return c;
}

Mat pow(Mat a, ll b) {
    Mat ans = e;
    while(b) {
        if(b&1) ans = mult(a, ans);
        a = mult(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &b, &k, &x);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d",&t);
        num[t]++;
    }
    for(int i = 0; i < x; i++) e.a[i][i] = 1;
    for(int i = 0;i < x; i++)
        for(int j = 0;j <= 9; j++)
             temp.a[i][(i*10+j)%x] = (temp.a[i][(i*10+j)%x]+num[j])%M;
    ans = pow(temp, b);
    printf("%lld", ans.a[0][k]);
    return 0;
}