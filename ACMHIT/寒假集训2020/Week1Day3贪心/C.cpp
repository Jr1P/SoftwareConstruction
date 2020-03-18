#include <cstdio>
#include <algorithm>
#define N 1050

int n, r;
int x[N];

int main() {
    while(1) {
        scanf("%d%d", &r, &n);
        if(n == -1 && r == -1) break;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        std::sort(x + 1, x + n + 1);
        
        int i = 1, cnt = 0;
		while(i <= n) {
			int s = x[i++];
			while(i <= n && x[i] <= s + r) i++;
			s = x[i - 1];
			while(i <= n && x[i] <= s + r) i++;
			cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}