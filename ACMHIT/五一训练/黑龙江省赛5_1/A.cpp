#include <cstdio>
#include <iostream>
#include <cstring>
const int MAXL = 2e5+1;

int t;
long long ans, len, p;
//int num[26];
char ch[MAXL];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		/*
		memset(num, 0, sizeof(num));
		scanf("%s", ch);
		len = strlen(ch);
		p = 0;
		ans = 0;
		for(p; p < len; p++)
			num[ch[p]-'a']++;
		for(int i = 0; i < 26; i++)
			ans += num[i]*(num[i]+1)>>1;
		printf("%lld\n", ans);*/
		scanf("%s", ch);
		len = strlen(ch);
		p = 0;
		ans = 0;
		while(p < len)
		{
			char c = ch[p];
			long long l1 = 0, i = p;
			while(ch[i] == c) 
			{
				l1++;
				i++;
			}
			ans += l1*(l1+1)>>1;
			p += l1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}