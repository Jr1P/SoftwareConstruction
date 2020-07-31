#include <cstdio>
#include <queue>
const int N = 5e4 + 5;

struct Person {
    int f, id;
    bool operator < (const Person o) const {
        if(f == o.f) return id > o.id;
        return f < o.f;
    }
};

int n, t;
std::priority_queue<Person > q[101];

int main() {
    scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        printf("Case #%d:\n", ++kase);
        int maxv = 0;
        for(int i = 1; i <= n; i++) {
            int f, v;
            scanf("%d%d", &f, &v);
            maxv = std::max(maxv, v);
            Person p;
            p.f = f, p.id = i;
            q[v].push(p);
        }
        for(int i = 0; i < n; i++) {
            int maxD = -1, minID, mv;
            for(int j = 1; j <= maxv; j++) {
                if(!q[j].empty()) {
                    Person now = q[j].top();
                    int dis = now.f + j * i;
                    if(dis > maxD || (dis == maxD && now.id < minID))
                        maxD = dis, minID = now.id, mv = j;
                }
            }
            if(i == 0) printf("%d", minID);
            else printf(" %d", minID);
            q[mv].pop();
        }
        printf("\n");
    }
    return 0;
}