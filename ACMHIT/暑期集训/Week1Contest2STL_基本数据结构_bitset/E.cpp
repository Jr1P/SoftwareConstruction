#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string s;
double num[1000];
char o[1000];

int main()
{
    while (1)
    {
        stack<double> s1;
        stack<char> s2;
        int cnt_n = 0, cnt_o = 0;
        double a = 0, now = 0;
        getline(cin, s);
        if (s[0] == '0' && s.length() == 1)
            break;
        for (unsigned i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                for (; isdigit(s[i]); i++)
                    now = now * 10 + s[i] - 48;
                s1.push(now);
                now = 0;
            }
            if (s[i] == ' ')
                continue;
            else
            {
                if (s[i] == '*')
                {
                    i += 2;
                    for (; isdigit(s[i]); i++)
                        now = now * 10 + s[i] - 48;
                    a = s1.top();
                    s1.pop();
                    s1.push(a * now);
                    now = 0;
                }
                else if (s[i] == '/')
                {
                    i += 2;
                    for (; isdigit(s[i]); i++)
                        now = now * 10 + s[i] - 48;
                    a = s1.top();
                    s1.pop();
                    s1.push(a / now);
                    now = 0;
                }
                else if (s[i] == '+' || s[i] == '-')
                    s2.push(s[i]);
            }
        }
        while (!s1.empty())
        {
            num[cnt_n++] = s1.top();
            s1.pop();
        }
        while (!s2.empty())
        {
            o[cnt_o++] = s2.top();
            s2.pop();
        }
        double ans = num[cnt_n-1];
        for(int i = cnt_o-1; i >= 0; i--)
        {
            if(o[i] == '+')
                ans = ans+num[i];
            else
                ans = ans-num[i];
        }
        printf("%.2f\n", ans);
    }
}