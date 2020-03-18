#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;

const string s[6] = {"FILL(2)", "FILL(1)", "DROP(2)", "DROP(1)", "POUR(2,1)", "POUR(1,2)"};

int a, b, c;
bool vis[150][150];

struct node {
	int va, vb;
	vector<int> v;
	node() {}
	node(int a, int b) {
		va = a; vb = b; v.clear();
	}
};

queue<node > q;

void bfs() {
	while(!q.empty())
		q.pop();
	node now(0, 0);
	q.push(now);
	vis[0][0] = 1;
	while(!q.empty()) {
		now = q.front();
		q.pop();
		int x = now.va, y = now.vb;
		for(int i = 0; i < 6; i++) {
			x = now.va, y = now.vb;
			switch(i) {
				case 0: {
					if(y == b) continue;
					y = b;
					break;
				}
				case 1: {
					if(x == a) continue;
					x = a;
					break;
				}
				case 2: {
					if (y == 0) continue;
					y = 0;
					break;
				}
				case 3: {
					if(x == 0) continue;
					x = 0;
					break;
				}
				case 4: {
					if(y == 0) continue;
					if(a-x >= y){
						x = x+y;
						y = 0;
					} else {
						y = y-(a-x);
						x = a;
					}
					break;
				}
				case 5: {
					if(x == 0) continue;
					if(b-y >= x) {
						y = y+x;
						x = 0;
					} else {
						x = x-(b-y);
						y = b;
						
					}
					break;
				}
			}
			node tmp;
			tmp.va = x; tmp.vb = y; tmp.v = now.v;
			tmp.v.push_back(i);
			if(vis[x][y]) continue;
			q.push(tmp);
			vis[x][y] = 1;
			if(tmp.va == c || tmp.vb == c) {
				printf("%d\n", tmp.v.size());
				for(unsigned i = 0; i < tmp.v.size(); i++)
					cout << s[tmp.v[i]] << endl;
				return ;
			}
		}
	}
	puts("impossible");
}

int main() {
	scanf("%d%d%d", &a, &b, &c);
	bfs();
	return 0;
}