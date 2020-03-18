#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
#define L 200000
#define S "Error"

char str[L];
int pre;
string ans;

int main()
{
	scanf("%s", str);

	int len = strlen(str);
	if(len%8)
	{
		puts(S);
		return 0;
	}
	for(int i = 0; i < len; i++)
		if (str[i] != '0' && str[i] != '1')
		{
			puts(S);
			return 0;
		}
	for(int i = 0; i < (len/8); i++)
	{
		string c;
		int now = 8*i;
		c += str[now], c += str[now+1], c += str[now+2];
		if(c == "101")
		{
			int d = 0;
			for(int j = 3; j <= 7; j++)
			{
				d = d << 1;
				d += str[now+j]-'0';
			}
			if (d > 25)
			{
				puts(S);
				return 0;
			}
			ans += (d+'A');
			//printf("%c", d+'A');
		}
		else if(c == "111")
			ans += ' ';
			//printf(" ");
		else if(c[0] == '0')
		{
			pre = 0;
			int d = 0;
			for(int j = 1; j <= 7; j++)
			{
				d = d<<1;
				d += str[now+j]-'0';
			}
			pre = d/2;
			i++;
			if(i >= (len/8))
			{
				puts(S);
				return 0;
			}
			now += 8;
			if(str[now] != '0')
			{
				puts(S);
				return 0;
			}
			d = 0;
			for(int j = 1; j <= 7; j++)
			{
				d = d<<1;
				d += str[now+j]-'0';
			}
			d /= 2;
			pre += d;
			char tmp[10];
			if(pre == 0)
			{
				ans += '0';
				continue;
			}
			int wei = log10(pre);
			tmp[wei+1] = '\0';
			while(pre)
			{
				int m = pre%10;
				char c = m+'0';
				tmp[wei--] = c;
				pre	/= 10;
			}
			for(int k = 0; tmp[k]; k++)
				ans += tmp[k];
			//printf("%d", pre+d);
		}
		else
		{
			puts(S);
			return 0;
		}
	}
	cout << ans;
	return 0;
}
