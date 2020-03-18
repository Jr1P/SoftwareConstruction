#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define N 600
const double eps = 1e-7;

vector<int> G[N];
int n, m;
int match[N];
bool check[N];

struct Point{
    double x, y;
}hole[N], gopher[N];

inline double dis(Point X, Point Y) {
    double dx = X.x-Y.x, dy = X.y-Y.y;
    return sqrt(dx*dx+dy*dy);
}

bool dfs(int u) {
    for (unsigned i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v])) { 
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false; 
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= m; i++) {
        if (match[i] == -1) {
            memset(check, false, sizeof(check));
            if (dfs(i)) ans++;
        }
    }
    return ans;
}

int main() {
    double s, v;
    while(scanf("%d%d%lf%lf", &n, &m, &s, &v) != EOF) {
        for(int i = 1; i <= m; i++) G[i].clear();
        for(int i = 1; i <= n; i++)
            scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
        for(int i = 1; i <= m; i++) {
            scanf("%lf%lf", &hole[i].x, &hole[i].y);
            for(int j = 1; j <= n; j++) {
                if(dis(hole[i], gopher[j])+eps < s*v)
                    G[i].push_back(j+m);
                //printf("%lf\n", dis(hole[i], gopher[j]));
            }
        }
        printf("%d\n", n-hungarian());
    }
    return 0;
}