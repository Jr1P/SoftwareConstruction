//查询区间不同颜色数
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>

typedef long long ll;
#define N 100003

int n, m, unit, ans, size; // n为数组大小, m为查询数
int sum[N], a[N], color[N];
//unit表示每个区块的长度, belong[i]表示数字i所属的区块的编号
//a[]为原数组, color[]是离散化后数组, res存放结果

struct Mo {
    int l, r, ID, ans, block; //[l, r]区间, id 代表编号, ans 为颜色数
} q[N]; //将查询定义为结构体

inline bool cmp(Mo a, Mo b) {
    return (a.block == b.block) ? (a.r < b.r) : (a.block < b.block);
}

inline bool CMP(Mo a, Mo b) {
    return a.ID < b.ID;
}

inline void inc(int x) {
    int tmp = color[x];
    sum[tmp]++;
    if (sum[tmp] == 1)
        ans++;
}

inline void dec(int x) {
    int tmp = color[x];
    sum[tmp]--;
    if (sum[tmp] == 0)
        ans--;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &m);
        unit = sqrt(n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", a+i);
            color[i] = a[i];
        }
		std::sort(a + 1, a + n + 1);
        size = unique(a + 1, a + n + 1) - (a + 1);
        for(int i = 1; i <= n; i++)
            color[i] = lower_bound(a + 1, a + size + 1, color[i]) - a;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].ID = i;
            q[i].ans = 0;
            q[i].block = q[i].l / unit + 1;
        }

		std::sort(q + 1, q + m + 1, cmp);
        int l = 1, r = 0;
        for(int i = 1; i <= m; i++) {
        	while(l < q[i].l)
                dec(l++);
            while(l > q[i].l)
                inc(--l);
            while(r < q[i].r)
                inc(++r);
            while(r > q[i].r)
                dec(r--);
            q[i].ans = ans;
        }
        
		std::sort(q + 1, q + m + 1, CMP);
        for(int i = 1; i <= m; i++)
            printf("%d\n", q[i].ans);
    }
    return 0;    
}
