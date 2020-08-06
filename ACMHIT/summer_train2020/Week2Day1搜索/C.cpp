#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <map>
const int N = 380000;
#define AIM 123456780

const int fac[] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
char ma[4][4];
int sta;

std::map<int, std::string> ans;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Node {
    int loc;
    int hash;
    // std::string step;
    int m[9];

} q[N >> 1];

char path[10] = "dlur";

inline int calc(int m[]) {
    int hash = 0;
    for(int i = 0; i < 9; i++)
        hash += fac[i] * m[i];
    return hash;
}

inline bool check(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

void bfs() {
    int head = 0, tail = 1;
    ans[q[0].hash] = "";
    while(head != tail) {
        Node now = q[head];
        for(int i = 0; i < 4; i++) {
            int x = now.loc / 3 + dx[i], y = now.loc % 3 + dy[i];
            if(check(x, y)) {
                Node next = now;
                next.loc = x * 3 + y;
                next.m[now.loc] = next.m[next.loc]; 
                next.m[next.loc] = 0;
                next.hash = calc(next.m);
                if(!ans.count(next.hash)) {
                    // next.step = path[i] + next.step;
                    if(tail >= N) tail = 0;
                    ans[next.hash] = path[i] + ans[now.hash];
                    q[tail++] = next;
                }
            }
        }
        head++;
        if(head >= N) head = 0;
    }
    // return (Node){0, 0, 0, 0};
}

int main() {
    char ch[3];
    q[0] = Node{8, 123456780, 1, 2, 3, 4, 5, 6, 7, 8, 0};
    bfs();
    while(~scanf("%s", ch)) {
        int kk = 0;
        if (!strcmp(ch, "x")) kk = kk * 10;
        else kk = kk * 10 + ch[0] - '0';
        for (int i = 1; i < 9; i++) {
            scanf("%s", ch);
            if (!strcmp(ch, "x")) kk = kk * 10;
            else kk = kk * 10 + ch[0] - '0';
        }

        // Node an = bfs();
        if(!ans.count(kk))
            puts("unsolvable");
        else
            std::cout << ans[kk] << std::endl;
        // v.clear();
        // while(an.pre != -1) {
        //     int i = an.c;
        //     if(i == 0) v.push_back('u');
        //     else if(i == 1) v.push_back('r');
        //     else if(i == 2) v.push_back('d');
        //     else v.push_back('l');
        //     an = q[an.pre];
        // }
        // if(v.size()) {
        //     std::vector<char>::iterator it;
        //     for(it = v.end(); it != v.begin(); it--)
        //         putchar(*it);
        //     putchar(*it);
        // }
        // puts("");
    }
    return 0;
}