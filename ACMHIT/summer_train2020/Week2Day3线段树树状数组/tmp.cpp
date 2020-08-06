#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
typedef long long ll;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int b[N];
int MIN[N << 2], lazy[N << 2], sum[N << 2];
void pushup(int rt)
{
    MIN[rt] = min(MIN[rt << 1], MIN[rt << 1 | 1]);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void pushdown(int rt, int m)
{
    if (lazy[rt])
    {

        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        MIN[rt << 1] += lazy[rt];
        MIN[rt << 1 | 1] += lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l, int r, int rt)
{
    lazy[rt] = 0;
    if (l == r)
    {
        MIN[rt] = b[l] - 1;
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
    {
        if (MIN[rt] > 0) //当此节点最小值大于0时，更新最小值和lazy
        {
            lazy[rt]--;
            MIN[rt]--;
        }
        else if (MIN[rt] == 0)
        {
            if (l == r) //当更新到叶子节点时
            {
                MIN[rt] = b[l] - 1; //赋值为初始的
                sum[rt]++;
            }
            else
            {
                pushdown(rt, r - l + 1);
                int m = (l + r) >> 1;
                if (MIN[rt << 1] == 0)
                    update(L, R, lson);
                else
                {
                    lazy[rt << 1]--;
                    MIN[rt << 1]--;
                }
                if (MIN[rt << 1 | 1] == 0)
                    update(L, R, rson);
                else
                {
                    lazy[rt << 1 | 1]--;
                    MIN[rt << 1 | 1]--;
                }
                pushup(rt);
            }
        }
    }
    else
    {
        pushdown(rt, r - l + 1);
        int m = (l + r) >> 1;
        if (L <= m)
            update(L, R, lson);
        if (R > m)
            update(L, R, rson);
        pushup(rt);
    }
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return sum[rt];
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ans = 0;
    if (L <= m)
        ans += query(L, R, lson);
    if (R > m)
        ans += query(L, R, rson);
    return ans;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int n, m;
    char s[10];
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        build(1, n, 1);
        int x, y;
        for (int i = 1; i <= m; i++)
        {
            scanf("%s", s);
            if (s[0] == 'a')
            {
                scanf("%d%d", &x, &y);
                update(x, y, 1, n, 1);
            }
            else if (s[0] == 'q')
            {
                scanf("%d%d", &x, &y);
                printf("%d\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}