#include <cstdio>
using namespace std;
const int MAXN = 1e5+1;
int heap[MAXN], len = 0;
//Min Heap

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insert(int x)
{
	int pos, fa;
	heap[++len] = x;
	pos = len; fa = pos >> 1;
	while (pos != 1 && heap[fa] > heap[pos])
	{
		swap(&heap[fa], &heap[pos]);
		pos >>= 1;
		fa = pos >> 1;
	}
}

int get()
{
	int p = heap[1], pos = 1, lson, rson;
	heap[1] = heap[len];
	len--; lson = pos << 1; rson = lson | 1;
	while ((lson <= len) && (heap[pos] > heap[lson] || heap[pos] > heap[rson]))
	{
		if (heap[lson] < heap[rson])
		{
			swap(&heap[pos], &heap[lson]);
			pos = lson; 
		}
		else
		{
			swap(&heap[pos], &heap[rson]);
			pos = rson;
		}
		lson = pos << 1;
		rson = lson | 1;
	}
	return p;
}

int main()
{
	int n, ans, x;
	//ios::sync_with_stdio(false);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		insert(x);
	}
	for (int i = 1; i <= n; i++)
	{
		ans = get();
		printf("%d ", ans);
	}
	return 0;
}