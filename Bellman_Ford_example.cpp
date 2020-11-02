#include <cstdio>
#include <vector>
using namespace std;
struct Edge
{
	int from, to, cost;
};
int dist[501];
int inf = 100000000;

int main(int argc, char const *argv[])
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		dist[i] = inf;
	vector<Edge> a(m);
	for (int j = 0; j < m; j++)
	{
		scanf("%d %d %d", &a[j].from, &a[j].to, &a[j].cost);
	}
	dist[1] = 0;
	bool negative_cycle = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = a[j].from;
			int y = a[j].to;
			int z = a[j].cost;
			if (dist[x] != inf && dist[y] > dist[x] + z)
			{
				dist[y] = dist[x] + z;
				if (i == n)
					negative_cycle = true;
			}
		}
	}
	if (negative_cycle)
		printf("-1\n");
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == inf)
				dist[i] = -1;
			printf("%d\n", dist[i]);
		}
	}

	return 0;
}
