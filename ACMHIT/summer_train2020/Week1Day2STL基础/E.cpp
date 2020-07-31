#include <cstdio>
#include <map>

std::map<int, int> m;
int n, p;

int main() {
    while(~scanf("%d%d", &n, &p)) {
        m.clear();
        for(int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            m[tmp]++;
        }
        while(p--) {
            int h;
            scanf("%d", &h);
            if(m.count(h)) {
                printf("%d\n", m[h]);
                m[h] = 0;
            } else puts("0");
        }
    }
    return 0;
}