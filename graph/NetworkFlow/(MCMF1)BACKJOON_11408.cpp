#include <cstdio>
#include <vector>
#include <queue>
#include<algorithm>
#define SOURCE 0
#define SINK 801
#define JOB 400
using namespace std;

int c[802][802],f[802][802],d[802][802];
vector<int> adj[802];

int main() {

	int n, m; scanf("%d %d",&n, &m);
	for (int i = 1; i <= n; i++) {
		int t; scanf("%d",&t);
		for (int j = 0; j < t; j++) {
			int job, we; scanf("%d %d",&job,&we);
			adj[i].push_back(job+JOB);
			adj[job + JOB].push_back(i);
			c[i][job + JOB] = 1;			
			d[job + JOB][i] = -we;
			d[i][job + JOB] = we;
		}
	}
	for (int i = 1; i <= n; i++) {
		adj[SOURCE].push_back(i);
		adj[i].push_back(SOURCE);
		c[SOURCE][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		adj[SINK].push_back(i+JOB);
		adj[i+JOB].push_back(SINK);
		c[i+JOB][SINK] = 1;
	}

	//MCMF
	int cnt = 0;
	int result = 0;
	while (1) {
		int prev[802], dist[802];
		bool inQ[802] = {0,};
		queue<int> qu;
		fill(prev, prev + 802, -1);
		fill(dist, dist + 802, 1 << 30);
		
		dist[SOURCE] = 0;
		inQ[SOURCE] = true;
		qu.push(SOURCE);

		while (!qu.empty()) {
			int curr = qu.front();
			qu.pop();
			inQ[curr] = false;
			for (int next : adj[curr]) {
				if (c[curr][next] - f[curr][next] > 0 && dist[next] > dist[curr] + d[curr][next]) {
					dist[next] = dist[curr] + d[curr][next]; //Update
					prev[next] = curr; //기록

					if (!inQ[next]) {
						qu.push(next);
						inQ[next] = true;
					}
				}
			}
		}

		if (prev[SINK] == -1) break; //마지막점에 도달하지 못했다면

		int flow = 1 << 30;
		for (int i = SINK; i != SOURCE; i = prev[i]) {
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		}

		for (int i = SINK; i != SOURCE; i = prev[i]) {
			result += flow * d[prev[i]][i];
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		cnt++;
		
	}
	printf("%d\n%d",cnt,result);
	

	
	return 0;
}
