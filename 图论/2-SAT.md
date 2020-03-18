# 2-SAT

## 什么是2-SAT ?

首先将2和SAT拆开。SAT是satisfiability的缩写，意思是可满足性。对于一串布尔型变量，给每个变量赋值为真或假，使得满足布尔方程(即布尔方程的值为真)。

举个例子：教授正在讲授一个算法，教室中的同学们的语言基础各不相同，所以每个人提出k个要求，每个人的k个要求至少有一个被满足。比如，取k == 3 ：

ZeiDong的要求：

1. 不使用 using namespace std; ($\lnot a$)
2. 使用读入优化 ($b$)
3. 大括号不换行 ($\lnot c$)

ZhuPi的要求：

1. 使用 using namespace std; ($a$)
2. 使用读入优化 ($b$)
3. 大括号不换行 ($\neg c$)

WangBao的要求：

1. 不使用 using namespace std; ($\lnot a$)
2. 不使用读入优化($\lnot b$)
3. 大括号换行($c$)

我们不妨把三种要求设为$a,b,c$。上述条件翻译成布尔方程为：
$$
(\lnot a \or b \or \lnot c)\and(a\or b\or \lnot c)\and(\lnot a \or \lnot b \or c)
$$
SAT问题，已经证明是**NP完全**的，只能使用暴力求解；而2-SAT问题，是学生的要求只有两种的问题，即上面的$a,b,c$中去掉一个条件

## 怎么求解2-SAT问题

利用数理逻辑的知识：
$$
\lnot a \or b \iff a \rightarrow b \and \lnot b \rightarrow \lnot a\\
a \or b \iff \lnot a \rightarrow b \and \lnot b \rightarrow a\\
\lnot a \or \lnot b \iff a \rightarrow \lnot b \and b \rightarrow \lnot a
$$
于是我们可以根据布尔表达式来建图，对于图上的每一个点$x$，建两个点：$x$和$\lnot x$分别表示$x$取true和false。对于每个要求$x_i\or x_j$，把它们转化为$\lnot x_i \rightarrow x_j \or \lnot x_j \rightarrow x_i$，可以得到一张有向图。**在同一个强连通分量内的所有点的取值(true或false)是一致的**。那么如果每一个$x$和$\lnot x$所在的强连通分量都不相同，就一定有解；否则，如果存在$x$和$\lnot x$在同一强连通分量内，就没有解。

问题又来了，如果有解，每个变量应该如何取值？

对于每个点$i$，如果$color[i] < color[i + n]$，该点就取真，如果大于就取假

## 板子

- [洛谷 P4782 **2-SAT**](https://www.luogu.com.cn/problem/P4782)

    ```cpp
    #include <cstdio>
    #include <vector>
    const int N = 2e6 + 5;
    
    std::vector<int > g[N];
    
    int n, m, tim, num, top;
    int low[N], dfn[N], color[N], stk[N];
    bool instk[N];
    
    inline int min(int x, int y) { return x < y ? x : y; }
    
    void tarjan(int u) {
        dfn[u] = low[u] = ++tim;
        stk[++top] = u; instk[u] = true;
        for(int v : g[u]) {
            if(!dfn[v])
                tarjan(v), low[u] = min(low[u], low[v]);
            else if(instk[v])
                low[u] = min(low[u], dfn[v]);
        }
        if(dfn[u] == low[u]) {
            ++num;
            do {
                color[u] = num;
                u = stk[top--];
                instk[u] = false;
            } while(dfn[u] != low[u]);
        }
    }
    
    int main() {
        scanf("%d%d", &n, &m);
        while(m--) {
            int a, b, va, vb;
            scanf("%d%d%d%d", &a, &va, &b, &vb);
            g[a + n * (va & 1)].push_back(b + n * (vb ^ 1));
            g[b + n * (vb & 1)].push_back(a + n * (va ^ 1));
        }
        for(int i = 1; i <= (n << 1); i++)
            if(!dfn[i]) tarjan(i);
        for(int i = 1; i <= n; i++)
            if(color[i] == color[i + n]) {
                puts("IMPOSSIBLE");
                return 0;
            }
        puts("POSSIBLE");
        for(int i = 1; i <= n; i++)
            printf("%d ", color[i] < color[i + n]);
        return 0;
    }
    ```

    