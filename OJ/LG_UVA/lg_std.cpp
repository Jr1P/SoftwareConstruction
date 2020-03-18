#include<queue>
#include<cstdio>
#include<cstring>
#define rg register
#define ci const int
#define cl const long long int

namespace IO {
    char buf[110];
}

template <typename T>
inline void qr(T &x) {
    char ch=getchar(),lst=' ';
    while((ch > '9') || (ch < '0')) lst=ch,ch=getchar();
    while((ch >= '0') && (ch <= '9')) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    if(lst == '-') x=-x;
}

template <typename T>
inline void write(T x,const char aft,const bool pt) {
    if(x < 0) {putchar('-');x=-x;}
    rg int top=0;
    do {
        IO::buf[++top]=x%10+'0';x/=10;
    } while(x);
    while(top) putchar(IO::buf[top--]);
    if(pt) putchar(aft);
}

template <typename T>
inline T mmax(const T a,const T b) {return a > b ? a : b;}
template <typename T>
inline T mmin(const T a,const T b) {return a < b ? a : b;}
template <typename T>
inline T mabs(const T x) {return x < 0 ? -x : x;}

template <typename T>
inline void mswap(T &a,T &b) {
    T temp=a;a=b;b=temp;
}

const int maxn = 4010;
const int maxm = 1000010;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to,nxt,flow;
};
Edge edge[maxm];int hd[maxn],ecnt=1;
inline void cont(ci from,ci to,ci flw) {
    Edge &e=edge[++ecnt];
    e.to=to;e.nxt=hd[from];e.flow=flw;hd[from]=ecnt;
}

int n,m,end,s,t;
int dist[maxn],pre[maxn];

std::queue<int>Q;

bool BFS();
int dfs(ci,int);
void reading();

int main() {
    qr(n);qr(m);end=n+m,s=end+1,t=end+2;end=t;
    reading();
    rg int _ans=0;
    while(BFS())
    {
      for(rg int i=1;i<=end;++i)
        pre[i]=hd[i];
      _ans+=dfs(s,INF);
    }
    write(_ans,'\n',true);
    return 0;
}

void reading() {
    rg int a,b,e=0;qr(e);
    while(e--) {
        a=b=0;qr(a);qr(b);
        b+=n;
        cont(a,b,1);cont(b,a,0);
    }
    for(rg int i=1;i<=n;++i) {cont(s,i,1);cont(i,s,0);}
    for(rg int i=1;i<=m;++i) {cont(i+n,t,1);cont(t,i+n,0);}
}

bool BFS() {
    while(!Q.empty()) Q.pop();
    memset(dist,-1,sizeof dist);
    Q.push(s);dist[s]=0;
    while(!Q.empty()) {
        int h=Q.front();Q.pop();
        for(rg int i=hd[h];i;i=edge[i].nxt) if(edge[i].flow > 0) {
            int &to=edge[i].to;
            if(~dist[to]) continue;
            dist[to]=dist[h]+1;Q.push(to);
        }
    }
    return dist[t] != -1;
}

int dfs(ci u,int ag) {
    if((u == t) || (!ag)) return ag;
    int _flow=0;
    for(int &i=pre[u];i;i=edge[i].nxt) if(edge[i].flow > 0) {
        int &to=edge[i].to;
        if(dist[to] != dist[u]+1) continue;
        int f=dfs(to,mmin(ag,edge[i].flow));
        edge[i].flow-=f;edge[i^1].flow+=f;
        _flow+=f;ag-=f;
        if(!ag) break;
    }
    return _flow;
}