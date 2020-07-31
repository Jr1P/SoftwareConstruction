#include <cstdio>
#include <vector>
#include <algorithm>
const int N = 1e5 + 5;

int a[N], disp[N], n;
std::vector<int> v, id;
 
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = n - 1; i >= 0; i--) {
        if(v.empty() || v.back() >= a[i]) {
            v.push_back(a[i]);
            id.push_back(i);
            disp[i] = -1;
        } else {
            int j = lower_bound(v.rbegin(), v.rend(), a[i]) - v.rbegin();
            j = v.size() - j;
            disp[i] = id[j] - i - 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(i) putchar(' ');
        printf("%d", disp[i]);
    }
    
    return 0;
}
