#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int n, m; scanf("%d %d", &n, &m);
	vector<pair<int, int>> bus[1001];
	int t1, t2, t3;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &t1, &t2, &t3);
		bus[t1].push_back(make_pair(t2,t3));
	}

	int start, end; scanf("%d %d", &start, &end);
	
	vector<int> dist(n+1, 1 << 30);
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0,start));

	while (!pq.empty())
	{
		int weight = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (auto cur : bus[node])
		{
			if (dist[cur.first] > weight + cur.second)
			{
				dist[cur.first] = weight + cur.second;
				pq.push(make_pair(dist[cur.first], cur.first));
			}
		}
	}

	printf("%d\n", dist[end]);


	return 0;
}