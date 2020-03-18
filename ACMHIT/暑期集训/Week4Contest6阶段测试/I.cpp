#include <cstdio>
#include <map>
#include <vector>
#define N 100055
using namespace std;

int n;
int dp[N];
vector<int > v[N];
map<pair<int ,int >, int > mp;

inline int max(int x,int y){
    return x > y ? x : y;
}

inline int min(int x,int y){
    return x < y ? x : y;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a+b >= n) continue;
        int l = a+1, r = n-b;
        mp[make_pair(l,r)]++;
        if(mp[make_pair(l,r)] > n-a-b) mp[make_pair(l, r)] = n-a-b;
        if(mp[make_pair(l,r)] == 1)
            v[r].push_back(l);
    }
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1];
        int sz = v[i].size();
        for(int j = 0; j < sz; j++)
            dp[i] = max(dp[i], dp[v[i][j]-1]+min(i-v[i][j]+1, mp[make_pair(v[i][j], i)]));
    }
    printf("%d\n", n-dp[n]);
    return 0;
}  
