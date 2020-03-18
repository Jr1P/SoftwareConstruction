#include <cstdio>
#include <vector>
#define N 105000

int n;
int a[N];
bool shown[N];
std::vector<int> re, cho;

int main() {
    scanf("%d", &n);
    re.clear(); cho.clear();
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(n == 1) {
            printf("1\n");
            return 0;
        }
        if(a[i] > n) continue;
        if(!shown[a[i]]) shown[a[i]] = 1;
        else re.push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] <= n) continue;
        a[i] = a[i] % n + 1;
        re.push_back(i);
    }
    for(int i = n; i >= 1; i--) if(!shown[i]) cho.push_back(i);
    int sz = re.size(), sz2 = cho.size();
    for(int i = 0; i < sz; i++) {
        a[re[i]] = cho[--sz2];
        cho.pop_back();
    }
    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
    return 0;
}