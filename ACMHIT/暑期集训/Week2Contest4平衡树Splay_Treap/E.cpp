#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
typedef long long LL;
using namespace std;
int Rand() { 
    static int seed=703;
    return seed=int(seed*48271LL%(~0u>>1));
}

const int maxn = 1000019,INF = 1e9;
int na;
int ch[maxn][2];
int val[maxn],dat[maxn];
int size[maxn],cnt[maxn];
int tot,root;
int New(int v) { 
    val[++tot] = v;
    dat[tot] = Rand();
    size[tot] = 1;
    cnt[tot] = 1;
    return tot;
}///
void pushup(int id) {
    size[id] = size[ch[id][0]] + size[ch[id][1]] + cnt[id];
}
void build() {
    root = New(-INF),ch[root][1] = New(INF);
    pushup(root);
}
void Rotate(int &id,int d) {
    int temp = ch[id][d ^ 1];
    ch[id][d ^ 1] = ch[temp][d];
    ch[temp][d] = id;
    id = temp;
    pushup(ch[id][d]),pushup(id);
}
void insert(int &id,int v) {
    if(!id) {
        id = New(v);
        return ;
    }
    if(v == val[id])cnt[id]++;
    else {
        int d = v < val[id] ? 0 : 1;
        insert(ch[id][d],v);
        if(dat[id] < dat[ch[id][d]])Rotate(id,d ^ 1);
    }
    pushup(id);
}
void Remove(int &id,int v) { 
    if(!id)return ;
    if(v == val[id]) { 
        if(cnt[id] > 1) {
            cnt[id]--,pushup(id);
            return ;
        }
        if(ch[id][0] || ch[id][1]) {
            if(!ch[id][1] || dat[ch[id][0]] > dat[ch[id][1]]) {
                Rotate(id,1),Remove(ch[id][1],v);
            } else Rotate(id,0),Remove(ch[id][0],v);
            pushup(id);
        } else id = 0;
        return ;
    }
    v < val[id] ? Remove(ch[id][0],v) : Remove(ch[id][1],v);
    pushup(id);
}

int get_val(int id,int rank) {
    if(!id)return INF;
    if(rank <= size[ch[id][0]])return get_val(ch[id][0],rank);
    else if(rank <= size[ch[id][0]] + cnt[id])return val[id];
    else return get_val(ch[id][1],rank - size[ch[id][0]] - cnt[id]);
}

int main() {
    int n;
    build();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        char ch = getchar();
        ch = getchar();
        int x;
        scanf("%d", &x);
        if(ch == 'I')insert(root,x);
       
        else printf("%d\n", get_val(root,x + 1));
    }
    return 0;
}
