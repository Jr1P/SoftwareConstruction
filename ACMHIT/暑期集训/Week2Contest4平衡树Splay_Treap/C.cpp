#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int n;
set<int > s;

int main() {
	scanf("%d", &n);
	while(n--) {
		int k;
		char ch = getchar();
		ch = getchar();
		if(ch == 'I') {
			scanf("%d", &k);
			s.insert(k);
		} else if(ch == 'Q'){
			scanf("%d", &k);
			set<int>::iterator it = s.upper_bound(k);
            it--;
			printf("%d\n", *it);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			s.erase(s.lower_bound(l), s.upper_bound(r));
		}
	}
	return 0;
}