#include <cstdio>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y) : x(_x), y(_y) {}
};

int a[55][55], b[55][55];
int n, m;
bool ex[55][55];
vector<Point > ans;

int main() {
    scanf("%d%d", &n, &m);
    ans.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1 ; j <= m; j++)
            scanf("%d", &a[i][j]);
    }
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++) {
            if(a[i][j] == 1 && !b[i][j]) {
                Point tmp(i, j);
                ans.push_back(tmp);
                if(a[i][j+1] == 0 || a[i+1][j] == 0 || a[i+1][j+1] == 0) {
                    puts("-1");
                    return 0;
                }
                b[i][j] = 1;
                b[i+1][j+1] = 1;
                b[i+1][j] = 1;
                b[i][j+1] = 1;
            } else if(a[i][j] && b[i][j]) {
                if(a[i][j+1] == 1 && a[i+1][j] == 1 && a[i+1][j+1] == 1) {
                    Point tmp(i, j);
                    ans.push_back(tmp);
                    b[i+1][j+1] = 1;
                    b[i+1][j] = 1;
                    b[i][j+1] = 1;
                }
            }
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] != b[i][j]) {
                puts("-1");
                return 0;
            }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].x, ans[i].y);
    return 0;
}