#include <cstdio>
#include <cstring>
const int MAXN = 3000000+5;
const int MAXK = 10000+5;
using namespace std;
typedef long long ll;
int n, k, a, b, f[MAXK];
bool occpied[MAXN];
// f(i) = (Ai + B) mod N;
int main()
{
	memset(occpied, false, sizeof(occpied));
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; i++)
	{
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		for(int j = 1; j <= y; j++)
			f[j] = (a*i+b)%n;
		
	}
	return 0;
}