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


	MCMF(int source, int sink,int n) : SOURCE(source), SINK(sink), N(n) {
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
		MinCost= 0, Maxflow = 0;

		while (1) {
			vector<int>prev(N+1, -1);
			vector<Edge*> path(N+1);
			vector<bool> inQ(N+1, false);
			vector<int> dist(N+1, 1 << 30);
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


struct sun {
	int x1, x2, y1, y2, w;
};


int main() {
	int T; scanf("%d",&T);
	while (T--) {
		int N, M; scanf("%d %d",&N,&M);
		vector<sun> A(N);
		vector<sun> B(M);
		MCMF mcmf(N + M+1, N + M + 2, N + M + 3);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d %d", &A[i].x1, &A[i].y1, &A[i].x2, &A[i].y2, &A[i].w);
			mcmf.addEdge(N + M + 1, i, 1, 0);
		}
		for (int i = 0; i < M; i++) {
			scanf("%d %d %d %d %d", &B[i].x1, &B[i].y1, &B[i].x2, &B[i].y2, &B[i].w);
			mcmf.addEdge(N+i, N+M+2, 1, 0);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sun garo = A[i];
				if (garo.x1 > garo.x2) swap(garo.x1, garo.x2);
				sun sero = B[j];
				if (sero.y1 > sero.y2) swap(sero.y1, sero.y2);
				if (sero.x1 >= garo.x1 && sero.x1 <= garo.x2  && garo.y1 >=sero.y1 && garo.y1 <=sero.y2 ) {
					mcmf.addEdge(i, N + j,1, -sero.w*garo.w);
				}
			}
		}
		mcmf.SPFA();
		printf("%d %d\n",mcmf.Maxflow, -mcmf.MinCost);
	}
	return 0;
}