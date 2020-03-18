// #include <cstdio>

// using namespace std;
// const int MAXN = 1e6+1;

// int tree[MAXN], n;

// inline int lowbit(int k) {
// 	return k&(-k);
// }

// inline void nodeUpdate(int x, int add) {
// 	for(int i = x; i <= n; i += lowbit(i))
// 		tree[i] += add;
// }

// inline int getSum(int r) {
// 	int ans = 0;
// 	for(int i = r; i; i -= lowbit(i))
// 		ans += tree[i];
// 	return ans;
// }

// int main() {
// 	while(~scanf("%d", &n)) {
// 		int ans = 0;
// 		for(int i = 1; i <= n; i++) tree[i] = 0;
// 		for(int i = 1; i <= n; i++) {
// 			int a;
// 			scanf("%d", &a);
// 			nodeUpdate(a+1, 1);
// 			ans += i-getSum(a+1);
// 		}
// 		printf("%d\n", ans);
// 	}
// 	return 0;
// }

#include <cstdio>
#include <iostream>
const int N = 5005;

int n, a[N], ans;
int ni1[N], ni2[N], zh1[N], zh2[N];

int main() {
    while(~scanf("%d", &n)) {
        ans = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ni1[i] = ni2[i] = zh1[i] = zh2[i] = 0;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < i; j++)
                if(a[i] < a[j]) ni1[i]++;
                else zh1[i]++;
            for(int j = i + 1; j <= n; j++)
                if(a[i] > a[j]) ni2[i]++;
                else zh2[i]++;
            ans += ni2[i];
        }
        int tmp = ans;
        for(int i = 1; i < n; i++) {
            tmp = tmp + ni1[i] - ni2[i] - zh1[i] + zh2[i];
            ans = std::min(ans, tmp);
        }
        printf("%d\n", ans);
    }
    return 0;
}