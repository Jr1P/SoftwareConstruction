#include <cstdio>
#include <unordered_map>
typedef long long ll;

int n, m, d;
int life[2][9];
std::unordered_map<ll, double> dp;

inline ll getSta() {
    ll sta = 0;
    for(int i = 1; i <= 6; i++) sta = sta * 10 + life[1][i];
    for(int i = 1; i <= 6; i++) sta = sta * 10 + life[0][i];
    return sta;
}

inline int count() {
    int sum = 0;
    for(int i = 1; i <= 6; i++) sum += life[1][i];
    for(int i = 1; i <= 6; i++) sum += life[0][i];
    return sum;
}

double dfs(ll sta, int d) {
    if(dp.count(sta)) return dp[sta];
    if(sta < 1000000) return 1.0;
    if(!d) return 0.0;
    int cnt = count();
    double ans = 0.0;
    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= 6; j++) {
            if(!life[i][j]) continue;
            life[i][j]--, life[i][j - 1]++;
            ll newsta = getSta();
            double tmp = dfs(newsta, d - 1);
            dp[newsta] = tmp;
            life[i][j]++, life[i][j - 1]--;
            ans += tmp * life[i][j] / cnt;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &d);
    int num;
    for(int i = 1; i <= n; i++) scanf("%d", &num), life[0][num]++;
    for(int i = 1; i <= m; i++) scanf("%d", &num), life[1][num]++;
    printf("%.8f\n", dfs(getSta(), d));
    return 0;
}