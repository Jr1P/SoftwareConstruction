#include <cstdio>
#include <vector>
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
#define irep(i, a, n) for(int i = (a); i < (n); i++)
const int N = 10005;

std::vector<int > prime;
bool check[N];

void shai(int n) {
    check[1] = true;
    for(int i = 2; i <= n; i++)
        if(!check[i]) {
            prime.push_back(i);
            for(int j = i * i; j <= n; j += i)
                check[j] = true;
        }
}

int n, m;

int main() {
    shai(N - 5);
    int p;
    while(~scanf("%d", &p)) {
        int t = p / 2;
        while(check[t] || check[p - t]) t--;
        printf("%d %d\n", t, p - t);
    }
    return 0;
}

// void shai() {
//     check[1] = true;
//     for(int i = 2; i <= n; i++)
//         if(check[i]) {
//             prime.push_back(i);
//             for(int j = 0; j < prime.size() && i * prime[j] <= n; j ++) {
//                 check[i * prime[j]] = true;
//                 if(i % prime[j]) break;
//             }
//         }
// }