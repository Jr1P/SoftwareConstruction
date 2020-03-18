#include <cstdio>
#define N 100050
#define Q 100050

typedef long long ll;

ll a[N], k[N], c[N];
int n, q, cnt, add, x, y; //[x, y]

struct Node
{
    ll l, r, sum, lz;
}node[N<<2];

inline void down(int k)
{
    int ls = k<<1, rs = k<<1|1;
    node[ls].lz += node[k].lz;
    node[rs].lz += node[k].lz;
    node[ls].sum += node[k].lz*(node[ls].r-node[ls].l+1);
    node[rs].sum += node[k].lz*(node[rs].r-node[rs].l+1);
    node[k].lz = 0;
}

void build(int l, int r, int k)
{
    node[k].l = l; node[k].r = r;
    if(l == r)
    {
        node[k].sum = c[++cnt];
        return ;
    }
    int mid = (l+r)>>1;
    build(l, mid, k<<1);
    build(mid+1, r, k<<1|1);
    node[k].sum = node[k<<1].sum+node[k<<1|1].sum;
}

ll intervalModify(int k)
{
    if(node[k].l >= x && node[k].r <= y)
    {

    }
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
}

void intervalInquiry(int k)
{
    if(node[k].l >= x && node[k].r <= y)
    {
        node[k].;
        return ;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &k[i]);
        c[i] = a[i+1]-a[i]-k[i];
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++)
    {
        char ch;
        scanf("%c", &ch);
        if (ch == 's')
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", intervalInquiry(1));
        }
        else
        {
            scanf("%d%d", &x, &add);
            y = n;
            intervalModify(i);
        }
    }
    return 0;
}
