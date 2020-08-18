#include<stdio.h>
#include<algorithm>

int n,ans,y[2002],Y,an;
double x0[2002],x1[2002],X;
bool f[2002];

struct poi {
    double v;int p;
    friend bool operator <(const poi &a,const poi &b){return a.v<b.v;}
}K[4004];

int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%lf%lf%d",x0+i,x1+i,y+i);
        if (x1[i]<x0[i]) std::swap(x1[i],x0[i]);
        x0[i]-=0.0000001;x1[i]+=0.0000001;
    }
    for (int i=1;i<=n;i++) for (int now=0;now<2;now++) {
        int tot=0;ans=std::max(ans,an=x1[i]-x0[i]);
        Y=y[i];X=(now)?x0[i]:x1[i];
        for (int j=1;j<=n;j++) if (Y!=y[j]) {
            K[tot++]={(X-x0[j])/(Y-y[j]),j};
            K[tot++]={(X-x1[j])/(Y-y[j]),j};
        }
        std::sort(K,K+tot);
        for (int j=0;j<tot;j++) if (ans<(an+=(f[K[j].p]^=1)?x1[K[j].p]-x0[K[j].p]:x0[K[j].p]-x1[K[j].p]+0.0000003)) ans=an;
    }
    printf("%d",ans);
}