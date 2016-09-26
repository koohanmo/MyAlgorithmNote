#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int source = 0;
const int sink = 201;
const int sujum = 100;

vector<int> adj[202];
int d[202][202], c[202][202], f[202][202];

int main() {
	int n, m; scanf("%d %d",&n,&m);

	//PERSON -> SINK
	for (int i = 1; i <= n; i++) {
		scanf("%d",&c[i][sink]);
		adj[sink].push_back(i);
		adj[i].push_back(sink);
	}

	//SOURCE ->BOOKSTORE 
	for (int i = 1; i <= m; i++) {
		scanf("%d", &c[source][i+sujum]);
		adj[source].push_back(i+sujum);
		adj[i+sujum].push_back(source);
	}

	//PERSON -> BOOKSTORE
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		int t; scanf("%d",&d[i+sujum][j]);
		d[j][i + sujum] = -d[i + sujum][j];
		
		adj[i+sujum].push_back(j);
		adj[j].push_back(i + sujum);
		c[i+sujum][j] = 1<<30;
	}

	int result = 0;
	while (true) {
		int prev[202],dist[202];
		bool inQ[202] = {0,};

		fill(prev, prev + 202, -1);
		fill(dist, dist + 202, 1 << 30);

		inQ[source] = true;
		dist[source] = 0;
		queue<int> Q;
		Q.push(source);

		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			inQ[curr] = false;

			for (auto next : adj[curr]) {
				if (c[curr][next]-f[curr][next]>0 && dist[next] > dist[curr]+d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next];
					prev[next] = curr;
					if (!inQ[next]) {
						Q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		
		if (prev[sink] == -1) break;

		int flow = 1 << 30;
		for (int i = sink; i != source; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = sink; i != source; i = prev[i]) {
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}		
	}
	printf("%d",result);


	return 0;
}
