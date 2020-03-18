#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050
#define M 100050
const int Q = (N<<1)+M; 

struct Query {
	int type, idx, val; //type-操作种类, idx-位置, val-加上的值
	bool operator < (const Query &rhs) const {
		return idx == rhs.idx ? type < rhs.type : idx < rhs.idx;
	}
}q[Q];  //type == 1表示操作为修改, 将idx位置的数加上val
//type == 2表示操作为查询的左端点, 故idx为l-1, val表示"是第几个查询", 3类似

int n, que, qidx = 0, aidx;
int ans[Q], s[N]; //s-前缀和, ans-答案
Query tmp[Q];

void cdq(int L, int R) {
	if(R-L <= 1)
		return ;
	int m = (L+R)>>1;
	cdq(L, m); cdq(m, R);
	int sum = 0, i = L, j = m, o = 0;
	while(i < m && j < R) {
		if(q[i] < q[j]) {
			if(q[i].type == 1) sum += q[i].val;
			tmp[o++] = q[i++];
		}
		else {
			if(q[j].type == 2) ans[q[j].val] -= sum;
			else if(q[j].type == 3) ans[q[j].val] += sum;
			tmp[o++] = q[j++];
		}
	}
	while(i < m) tmp[o++] = q[i++];
	while(j < R) {
		if(q[j].type == 2) ans[q[j].val] -= sum;
		else if(q[j].type == 3) ans[q[j].val] += sum;
		tmp[o++] = q[j++];
	}
	for(int i = 0; i < o; i++) q[i+L] = tmp[i];
}

int main()
{
	scanf("%d%d", &n, &que);
	for(int i = 1; i <= n; i++) {
		q[qidx].idx = i; q[qidx].idx = 1;
		scanf("%d", &q[qidx].val); ++qidx;
	}
	for(int i = 1; i <= que; i++) {
		int type, idx, val;
		scanf("%d", &type);
		q[qidx].type = type;
		if(type == 1)//操作1
			scanf("%d%d", &q[qidx].idx, &q[qidx].val);
		else {
			int l, r;
			scanf("%d%d", &l, &r);
			q[qidx].idx = l-1; q[qidx].val = aidx; ++qidx;
			q[qidx].type = 3; q[qidx].idx = r; q[qidx].val = aidx; ++aidx;
		}
		++qidx;
	}
	cdq(0, qidx);
	for(int i = 0; i < aidx; i++) printf("%d\n", ans[i]);
	return 0;
}