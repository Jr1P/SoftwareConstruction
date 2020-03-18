#include <iostream>
using namespace std;

int main()
{
	short T;
	unsigned long long weight = 0, Edge, ME, Node;
	cin >> T;
	for(int i = 0; i < T ; i++)
	{
		cin >> Node >> Edge;
		ME = Node * (Node - 1) / 2 ;
		if(Edge < Node - 1)
		{
			unsigned long long subEdge = (Edge + 1) * Edge / 2;
			weight = Edge * 2 + (subEdge - Edge) * 4 + (ME - subEdge) * 2 * Node;
		}
		else if (Edge < ME)
			weight = Edge * 2 + (ME - Edge) * 4;
		else
			weight = ME * 2;
		cout << weight << '\n';
	}
	return 0;
}