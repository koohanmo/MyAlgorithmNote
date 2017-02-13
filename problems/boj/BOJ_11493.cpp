#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct MCMF {
	struct Edge {
		int flow, cap, next, weight;
		Edge* dual;
		Edge(int next, int cap, int weight) {
			this->next = next;
			this->cap = cap;
			this->weight = weight;
			flow = 0;
		}
		int spare() { return cap - flow; }
		void addFlow(int f) {
			this->flow += f;
			dual->flow -= f;
		}
	};

	int SOURCE;
	int SINK;
	vector<vector<Edge*>> adj;
	int N;
	int Maxflow = 0;
	int MinCost = 0;


	MCMF(int source, int sink, int n) : SOURCE(source), SINK(sink), N(n) {
		adj.assign(n + 1, vector<Edge*>());
	}

	void addEdge(int start, int end, int cap, int weight) {
		Edge* e1 = new Edge(end, cap, weight);
		Edge* e2 = new Edge(start, 0, -weight);
		e1->dual = e2;
		e2->dual = e1;
		adj[start].push_back(e1);
		adj[end].push_back(e2);
	}

	void SPFA() {
		MinCost = 0, Maxflow = 0;

		while (1) {
			vector<int>prev(N + 1, -1);
			vector<Edge*> path(N + 1);
			vector<bool> inQ(N + 1, false);
			vector<int> dist(N + 1, 1 << 30);
			queue<int> Q;
			dist[SOURCE] = 0;
			inQ[SOURCE] = true;
			Q.push(SOURCE);

			while (!Q.empty()) {
				int cur = Q.front();
				Q.pop();
				inQ[cur] = false;
				for (auto next : adj[cur]) {
					if (next->spare() > 0 && dist[next->next] > dist[cur] + next->weight) {
						dist[next->next] = dist[cur] + next->weight;
						prev[next->next] = cur;
						path[next->next] = next;
						if (!inQ[next->next]) {
							Q.push(next->next);
							inQ[next->next] = true;
						}
					}
				}
			}
			if (prev[SINK] == -1) break;

			int flow = 1 << 30;
			for (int i = SINK; i != SOURCE; i = prev[i]) {
				flow = min(flow, path[i]->spare());
			}
			Maxflow += flow;
			for (int i = SINK; i != SOURCE; i = prev[i]) {
				MinCost += flow*path[i]->weight;
				path[i]->addFlow(flow);
			}
		}
	}
};


int main() {
	int T; scanf("%d",&T);
	while (T--) {
		int N, M; scanf("%d %d",&N,&M);
		vector<vector<int>> MA(N+1, vector<int>(N+1,1<<29));
		for (int i = 1; i <= N; i++) MA[i][i] = 0;
		for (int i = 0; i < M; i++) {
			int a, b; scanf("%d %d",&a,&b);
			MA[a][b] = 1;
			MA[b][a] = 1;
		}
		for (int k = 1; k <= N; k++) for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++) {
			MA[i][j] = min(MA[i][j], MA[i][k] + MA[k][j]);
		}

		MCMF mcmf(N + 1, N + 2, N + 3);

		vector<int> V(N + 1);
		vector<int> D(N + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &V[i]);//정점
			if (V[i] == 1) mcmf.addEdge(i, N + 2, 1, 0);
		}
		for (int i = 1; i <= N; i++){
			scanf("%d", &D[i]); //동전
			if (D[i] == 1) {
				mcmf.addEdge(N + 1, i, 1, 0);
				for (int j = 1; j <= N; j++) {
					if (V[j] == 1 && MA[i][j]>=0) mcmf.addEdge(i, j, 1, MA[i][j]);
				}
			}
		}
		mcmf.SPFA();
		printf("%d\n",mcmf.MinCost);
	}
	return 0;
}