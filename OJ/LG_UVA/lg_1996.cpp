#include <iostream>
using namespace std;

int n, m, cnt, out[101];

int main(){
    int now = 1;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cnt = 0;
    while (cnt != n)
    {
        int mm = 0;
        while (1)
        {
            if (!out[now])
            {
                mm++;
                if (mm == m)
                    break;
            }
            now++;
            if(now > n)
                now = now % n;
        }
        cnt++;
        out[now] = 1;
        cout << now << ' ';
    }
    return 0;
}