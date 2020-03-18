#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
struct EDGE{
    int ver,dis,nxt,pre,num;
}edge[1000100];
int cnt,dfs_cnt,dfn[1001],low[1001],head[1001],n,m,key[1001],tot,ans=1;
int T,vis[1001],sum[1001];
void add(int u,int v){
    edge[++cnt].ver=v;
    edge[cnt].nxt=head[u];
    edge[cnt].pre=u;
    head[u]=cnt;
}
inline int read(){
    int sym=0,res=0;char ch=0;
    while (ch<'0'||ch>'9')sym|=(ch=='-'),ch=getchar();
    while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
    return sym?-res:res;
}
void file(){
    freopen("read.in","r",stdin);
    freopen("write.out","w",stdout);
}
int cmp(int a,int b){
    return a<b;
}
void tarjan(int u,int root){//割点板子
    int child=0;
    dfn[u]=low[u]=++dfs_cnt;
    for (int i=head[u];i;i=edge[i].nxt){
        int v=edge[i].ver;
        if (!dfn[v]){
            tarjan(v,root);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]&&u!=root)key[u]=1;
            if (u==root)child++;
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if (u==root&&child>=2)key[u]=1;
}
void bfs(int s){
    int sum=1,sum_key=0,stack[1001],top=0;
    queue<int>q;q.push(s);vis[s]=1;
    while (!q.empty()){
        int u=q.front();q.pop();
        for (int i=head[u];i;i=edge[i].nxt){
            int v=edge[i].ver;
            if (vis[v])continue;vis[v]=1;
            if (key[v]){
                sum_key++;stack[++top]=v;vis[v]=1;//把割点用一个栈存起来
                continue;
            }               
            q.push(v);sum++;
        }
    }
    while (top)vis[stack[top--]]=0;
    if (sum_key<2){
        tot++;ans*=sum;
    }
}
signed main(){//file();
    m=read();T++;
    while(m!=0){
        memset(head,0,sizeof(head));//庞大的初始化
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(key,0,sizeof(key));
        memset(vis,0,sizeof(vis));
        memset(sum,0,sizeof(sum));
        dfs_cnt=0;n=0;cnt=0;tot=0;ans=1;//庞大的初始化
        for (int i=1;i<=m;i++){
            int x=read(),y=read();
            add(x,y);add(y,x);n=max(n,max(x,y));//没有输入n就自己求n
        }
        for (int i=1;i<=n;i++){
            if (!dfn[i])tarjan(i,i);//找割点
        }
        for (int i=1;i<=n;i++){
            if (!vis[i]&&!key[i]){//如果没有搜到且不是割点
                bfs(i);
            }
        }if (tot==1){//只有一个连通块
            tot=2;ans=(ans-1)*ans/2;
        }
        printf("Case %lld: %lld %lld\n",T,tot,ans);
        m=read();T++;
    }
}