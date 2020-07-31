#include <cstdio>
#include <unordered_map>
#include <set>
typedef long long ll;

const int N = 5e6 + 5;

struct Stack {
    int Top = 0;
    ll ele[N];

    inline void push(int k) {
        ele[Top++] = k;
    }

    inline bool empty() {
        return Top == 0;
    }

    inline void pop() {
        Top--;
    }

    inline int top() {
        return ele[Top - 1];
    }

} s;

// std::stack<int > s;
// std::unordered_map<unsigned, unsigned > ma;
// std::set<unsigned > set;

int p, q, m, n;
unsigned int SA, SB, SC;
unsigned int rng61() {
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}

ll gen(){
    scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        unsigned t;
        if(rng61() % (p + q) < p) {
            t = rng61() % m + 1;
            if(s.empty() || s.top() < t) s.push(t);
            else s.push(s.top());
        } else {
            if(!s.empty()) s.pop();
            else continue;
        }
        if(!s.empty())
            ans = ans ^ (((ll)i) * s.top());
    }
    return ans;
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        while(!s.empty()) s.pop();
        printf("Case #%d: %lld\n", ++kase, gen());
    }
    return 0;
}