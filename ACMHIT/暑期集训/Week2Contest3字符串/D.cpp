#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
#define L 1000050

string in, s;
int r[L<<1], l, kase = 0;

void manacher()
{
    int ctr = 0, right = 0, len = 0;
    int ll = s.length();
    memset(r, 0, sizeof(r));
    for(int i = 0; i < ll; i++)
    {
        r[i] = (right > i) ? min(r[ctr+ctr-i], right-i+1): 1;
        while(i-r[i] >= 0 && i+r[i] < ll && s[i+r[i]] == s[i-r[i]])
            r[i]++;
        if(s[i+r[i]-1] == '#') r[i]--;
        if(r[i] > len) len = r[i];
        if(i+r[i]-1 > right) {
            right = i+r[i]-1;
            ctr = i;
        }
    }
    printf("Case %d: %d\n", ++kase, len);
}

int main()
{
    while(1) {
        cin >> in;
        if(in[0] == 'E')
            break;
        l = in.length();
        s = "";
        for(int i = 0; i < l-1; i++)
            s += in[i], s += '#';
        s += in[l-1];
        manacher();
        
    }
    return 0;
}
