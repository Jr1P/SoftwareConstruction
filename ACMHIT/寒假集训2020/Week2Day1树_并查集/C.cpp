#include <cstdio>
#include <cstring>

char pre[30], in[30], post[30];

int find(char ch, char *str) {
	for(int i = 0; str[i]; i++)
		if(str[i] == ch)
			return i;
}

void work(char *pre, char *in, int len) {
	if(!len) return ;
	if(len == 1) {
		putchar(pre[0]);
		return ;
	}
	char rt = pre[0];
	int pos = find(rt, in);
	work(pre + 1, in, pos);
	work(pre + pos + 1, in + pos + 1, len - pos - 1);
	work(pre, in + pos, 1);
}

int main() {
	while(~scanf("%s%s", pre, in)) {
		int l = strlen(pre);
		work(pre, in, l);
		puts("");
	}
	return 0;
}
