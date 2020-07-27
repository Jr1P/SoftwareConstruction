#include <cstdio>
#include <iostream>
const int N = 1e5 + 5;

int a[N];
int n, k;

int partition(int l, int r) { // 以a[r]为主元，将数组分为小于a[r]和大于等于a[r]的两部分, 并返回划分后a[r]的下标
    int i = l;
    for(int j = l; j < r; j++)
        if(a[j] <= a[r])
            std::swap(a[i++], a[j]);
    std::swap(a[i], a[r]);
    return i;
}

int kth(int l, int r, int k) {
    if(l >= r) return a[l];
    int i = partition(l, r);
    if(k == i) return a[i];
    else if(k < i) return kth(l, i-1, k);
    else return kth(i+1, r, k - i);
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%d\n", kth(1, n, k));
    return 0;
}