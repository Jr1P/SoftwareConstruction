#include <cstdio>
#include <vector>
#define N 100050

int n, m;
bool check[N];
int a[N];
std::vector<int> prime;

int main() {
    scanf("%d", &n);
    check[1] = true;
	for (long long i = 2L; i <= n; ++i)
		if (!check[i]) {
			prime.push_back(i);
	    	for (long long j = i * i; j <= n; j += i)
	  	    	check[j] = true;
		}
    int cnt = 1; 
    for(int i : prime) {
        for(int pos = i; pos <= n; pos += i)
            a[pos] = cnt;
        cnt++;
    }
    for(int i = 2; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}