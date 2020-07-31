#include <cstdio>
#include <unordered_map>
#include <deque>
#include <string>
const int N = 2505;
const int M = 1e5 + 5;
const int days[15] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Node {
    int hour, cost;
};

int n, m, needs[M];
std::unordered_map<std::string, int> map;
std::deque<Node> q;

inline bool isRunYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int get_hour(int year, int month, int day, int hour) {
    int ans = 0;
    ans += (day - 1);
    for(int i = 0; i < month; i++) {
        if(i == 1 && isRunYear(year)) ans += 29;
        else ans += days[i];
    }
    for(int i = 2000; i < year; i++) {
        ans += 365;
        if(isRunYear(i)) ans ++;
    }
    return ans * 24 + hour;
}

int main() {
    map["Jan"] = 0; map["Feb"] = 1; map["Mar"] = 2; map["Apr"] = 3; map["May"] = 4; map["Jun"] = 5;
    map["Jul"] = 6; map["Aug"] = 7; map["Sep"] = 8; map["Oct"] = 9; map["Nov"] = 10; map["Dec"] = 11;
    while(~scanf("%d%d", &n, &m)) {
        if(!n) break;
        int day, year, h, r, s, t;
        char month[5];
        for(int i = 0; i <= m; i++) needs[i] = 0;
        while(!q.empty()) q.pop_back();
        for(int i = 1; i <= n; i++) {
            scanf("%s%d%d%d%d", month, &day, &year, &h, &r);
            int mo = map[month];
            needs[get_hour(year, mo, day, h)] += r;
        }
        scanf("%d%d", &t, &s);
        long long ans = 0;
        for(int i = 0; i < m; i++) {
            int cost;
            scanf("%d", &cost);
            while(!q.empty() && q.back().cost + s * (i - q.back().hour) >= cost) q.pop_back();
            q.push_back((Node){i, cost});
            while(q.back().hour - q.front().hour > t) q.pop_front();
            if(needs[i]) ans += (long long)(q.front().cost + (i - q.front().hour) * s) * needs[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}