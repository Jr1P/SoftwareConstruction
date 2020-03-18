#include <stdio.h>
using namespace std;
const int maxCampNum = 50000 + 5;
const int maxP = 100000 + 5;
//'I'----Increase, 'D'----Dec, 'Q'----Query;

int main()
{
	int campNum, edgeNum, queryNum, enemyNum[maxCampNum], u[maxCampNum], v[maxCampNum], C, C1, C2, K; //edgeNum = campNum - 1;
	char ch;
	while (!EOF)
	{
		scanf("%d %d %d", &campNum, &edgeNum, &queryNum);
		for (int i = 1; i <= campNum; i++)
			scanf("%d", &enemyNum[i]);
		for (int i = 1; i <= edgeNum; i++)
			scanf("%d %d", &u[i], &v[i]);
		for (int i = 1; i <= queryNum; i++)
		{
			scanf("%c", &ch);
			if (ch == 'I')
			{
				scanf("%d %d %d", &C1, &C2, &K);
				
			}
			else if (ch == 'Q')
			{
				scanf("%d", &C);
			}
			else
			{
				scanf("%d %d %d", &C1, &C2, &K);
			}
		}
	}
	return 0;
}