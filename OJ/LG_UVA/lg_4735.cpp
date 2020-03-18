/***
 * 可持久化trie树
 * root[i]为第i棵trie树的树根编号
 * trie[i][]为编号为i的节点的左右儿子
 * preX[]前缀异或和
 * cnt[i]为编号为i的节点的数字个数
***/
#include <cstdio>
#define N 500050
#define SIZE 2  // 01-trie
#define WORD 24 // 2^24 约等于 1.7e7

int n, t, m, tot = 1;
int root[N], cnt[N * WORD], trie[N * WORD][SIZE];
int preX[N];

/***
 * insert---插入函数, 在树根编号now的trie树插入数x
 * pre为前一状态的trie树的树根
 * t从高位到低位
***/
void insert(int now, int pre, int t, int x)
{
    if (t < 0)
        return;
    int id = (x >> t) & 1;                          // 第t位的数
    trie[now][!id] = trie[pre][!id];                // 树now的[!id]儿子指向pre的[!id]儿子
    trie[now][id] = tot++;                          // 为now的[id]儿子分配新的编号
    cnt[trie[now][id]] = cnt[trie[pre][id]] + 1;    // 数字个数
    insert(trie[now][id], trie[pre][id], t - 1, x); // 向now的[id]儿子插入x的剩下t - 1位
}

/***
 * query---查询函数, 在可持久化trie树中查找与 x 异或后值最大的并返回异或后的最大值
 * l, r限定了trie树的版本
 * 策略: 贪心地从高位到低位选择
 * 
***/

int query(int l, int r, int t, int x)
{
    if (t < 0)
        return 0;
    int id = (x >> t) & 1;
    if (cnt[trie[r][!id]] > cnt[trie[l][!id]]) //
        return (1 << t) + query(trie[l][!id], trie[r][!id], t - 1, x);
    else
        return query(trie[l][id], trie[r][id], t - 1, x);
}

int main()
{
    scanf("%d%d", &n, &m);
    root[0] = tot++;
    insert(root[0], 0, WORD, 0);
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        root[i] = tot++;
        preX[i] = preX[i - 1] ^ tmp;
        insert(root[i], root[i - 1], WORD, preX[i]);
    }
    while (m--)
    {
        char type[5];
        int x, l, r;
        scanf("%s", type);
        if (type[0] == 'A') // 插入数x
        {
            scanf("%d", &x);
            n++;
            preX[n] = preX[n - 1] ^ x;
            root[n] = tot++;
            insert(root[n], root[n - 1], WORD, preX[n]);
        }
        else // 查询
        {
            scanf("%d%d%d", &l, &r, &x);
            l--;
            r--;
            if (l == 0)
                printf("%d\n", query(0, root[r], WORD, x ^ preX[n]));
            else
                printf("%d\n", query(root[l - 1], root[r], WORD, x ^ preX[n]));
        }
    }
    return 0;
}