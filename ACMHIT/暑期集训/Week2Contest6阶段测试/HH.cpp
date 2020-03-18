#include <cstdio>
#include <algorithm>
#include <ext/rope>
using namespace std;
#define N 150050

int n, k;
int tr[N], ans[N];
__gnu_cxx::rope<int > r;

inline int max(int x, int y) {return x>y?x:y;}

inline int lowbit(int k) {return k&(-k);}

inline void update(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i))
        tr[i] = max(tr[i], val);
}

inline int query(int x) {
    int ma = 0;
    for(int i = x; i; i -= lowbit(i))
        ma = max(ma, tr[i]);
    return ma;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        r.insert(k, i);
    }
    for(int i = 0; i < n; i++) {
        int d = r[i];
        update(d, ans[d] = query(d)+1);
    }
    for(int i = 1; i <= n; i++) printf("%d\n", ans[i] = max(ans[i], ans[i-1]));
	return 0;
}