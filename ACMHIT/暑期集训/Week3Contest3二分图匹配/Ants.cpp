#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#define ll long long
#define eps 1e-8
#define INF 199912270000.1912
#define NN 105

using namespace std;
int sgn(double x){
    if(-eps < x && x < eps)
        return 0;
    if(x <= -eps)
        return -1;
    else return 1;
}
int n, nx, ny;
int lk[NN], ans[NN];
double lx[NN], ly[NN], slack[NN];
bool vis_x[NN], vis_y[NN];
struct point{
    double x,y;
    void read(){
        scanf("%lf", &x);
        scanf("%lf", &y);
    }
}pa[NN], pt[NN];
double dist(point A, point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double mp[NN][NN];

bool dfs(int x){
    vis_x[x]=1;
    for(int i=1;i<=ny;i++){
        if(vis_y[i])continue;
        double temp=lx[x]+ly[i]-mp[x][i];
        if(sgn(temp)==0){
            vis_y[i]=1;
            if(lk[i]==-1||dfs(lk[i])){
                lk[i]=x;
                return 1;
            }
        }
        else{
            slack[i]=min(slack[i],temp);
        }
    }
    return 0;
}

void KM(){
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(lk, -1, sizeof(lk));
    nx=ny=n;
    for(int i=1;i<=nx;i++){
        lx[i]=-INF;
        for(int j=1;j<=ny;j++){
            lx[i]=max(lx[i],mp[i][j]);
        }
    }
    for(int i=1;i<=nx;i++){
        for(int j=1;j<=ny;j++)slack[j]=INF;
        while(1){
            memset(vis_x,0,sizeof(vis_x));
            memset(vis_y,0,sizeof(vis_y));
            if(dfs(i))break;
            double d=INF;
            for(int j=1;j<=ny;j++){
                if(vis_y[j])
                    continue;
                d = min(d,slack[j]);
            }
            for(int j=1;j<=nx;j++){
                if(vis_x[j]){
                    lx[j]-=d;
                }
            }
            for(int j=1;j<=ny;j++){
                if(vis_y[j])ly[j]+=d;
                else slack[j]-=d;
            }
        }
    }
}
int work(){
    for(int i = 1; i <= n; i++)
        pa[i].read();
    for(int i = 1; i <= n; i++)
        pt[i].read();
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            mp[i][j]=-dist(pa[i],pt[j]);
        }
    }
    KM();
    for(int i=1;i<=n;i++)
        if(lk[i]!=-1)ans[lk[i]]=i;
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
int main(){
    while(scanf("%d", &n)!=EOF)
        work();
    return 0;
}
