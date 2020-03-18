//埃氏筛
#include<cstdio>
#include<cstring>
#include <vector>
#include <algorithm>
#define MAXN 10000500
//int prime[MAXN<<1];
typedef long long ll;
using namespace std;
bool check[MAXN];
vector<ll> prime;

int main()
{
	ll n;
	freopen("output.txt", "w", stdout);
	scanf("%lld", &n);
	//memset(check, true, sizeof(check)); //0表示素数 1表示合数
	check[1] = 1;
	for (ll i = 2; i <= n; ++i)
		if (!check[i]) {
			prime.push_back(i);
	    	for (ll j = i*i; j <= n; j += i)
	  	    	check[j] = 1;
		}
	for(ll i : prime)
		printf("%lld, ", i);
	printf("%d", prime.size());
	return 0;
}

//———————————————————————————————————————————————————————分割线————————————————————————————————————————————*/
// //欧式筛
/*#include <cstdio>
#define N 10000500
bool check[N];
int prime[N>>2];

int n, m, tot = 0;

int main()
{
	scanf("%d%d", &n, &m);
	check[0] = check[1] = true;
	for(long long i = 2; i <= n; i++) {
		if(!check[i])
			prime[++tot] = i;
		for(int j = 1; j <= tot && i*prime[j] <= n; j++) {
			check[i*prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
	// for(int i = 1; i <= 25; i++)
	// 	printf("%d ", prime[i]);
	for(int i = 1; i <= m; i++)
	{
		int a;
		scanf("%d", &a);
		if(check[a])
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}*/