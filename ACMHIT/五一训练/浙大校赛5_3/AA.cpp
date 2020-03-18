#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 100010
int n,m,T;
int a[MAXN],b[MAXN],p[MAXN],q[MAXN];
int gn[MAXN],dn[MAXN],gl[MAXN],dl[MAXN];
int Min(int x,int y)
{
	if(x>y) return y;
	else return x;
}
int main()
{
	scanf("%d",&T);
	while(T--){
		memset(gn,0,sizeof(gn));
		memset(dn,0,sizeof(dn));
		memset(gl,0,sizeof(gl));
		memset(dl,0,sizeof(dl));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&q[i]);
		for(int i=1;i<=n;i++){
			if(p[i]==1)
				gn[++gn[0]]=a[i];
			if(p[i]==0)
				dn[++dn[0]]=a[i];
		}
		for(int i=1;i<=m;i++){
			if(q[i]==1)
				gl[++gl[0]]=b[i];
			if(q[i]==0)
				dl[++dl[0]]=b[i];
		}
		sort(gn+1,gn+gn[0]+1);
		sort(dn+1,dn+dn[0]+1);
		sort(gl+1,gl+gl[0]+1);
		sort(dl+1,dl+dl[0]+1);
		int ans=0;
		int nn=1,nl=1;
		while(nn<=gn[0]&&nl<=dl[0]){
			if(gn[nn]<dl[nl]){
				ans++;
				nn++;
				nl++;
			}else{
				nl++;
			}
		}
		nn=1,nl=1;
		while(nn<=dn[0]&&nl<=gl[0]){
			if(dn[nn]>gl[nl]){
				ans++;
				nn++;
				nl++;
			}else{
				nn++;
			}
		}
		printf("%d\n",ans);
	}
}