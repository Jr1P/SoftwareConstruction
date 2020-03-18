#include <cstdio>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
#define N 10050

int n, t;
int a[N], pos[N];
bool f = false;

int main() {
	scanf("%d", &t);
	srand(0);
	while(t) {
		scanf("%d", &n);
		f = false;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a+i);
			pos[a[i]] = i;
		}
		int ceiling = max(n-2, 8000);
		register int i, j, k;
		for(i = 1; i <= ceiling; i++){
			if(f) break;
			for(j = n; j >= 3 && j > i+1; j--){
				if(((a[i]+a[j])&1) == 0) {
					k = pos[(a[i]+a[j])>>1];
					if(k > i && k < j) {
						f = true;
						break;
					}
				}
			}
		}
		if(f) puts("Y");
		else puts("N");
		t--;
	}
	return 0;
}