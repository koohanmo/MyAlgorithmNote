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


int dobu[4][4] = { {100,70,40,0},
				{ 70,50,30,0 } ,
				{ 40,30,20,0 } ,
				{ 0,0,0,0 } };


int getIdx(char c1) {
	switch (c1) {
		case 'A': return 0;
		case 'B': return 1;
		case 'C': return 2;
		case 'F': return 3;
	}
}
int calW(char c1, char c2) {
	return -dobu[getIdx(c1)][getIdx(c2)];
}

int main() {
	int N; scanf("%d",&N);
	MCMF mcmf(N*N,N*N+1,N*N+2);
	char A[12][12];
	for (int i = 0; i < N; i++) scanf("%s",A[i]);
	for (int i = 0; i < N; i++)for (int j = 0; j< N; j++) {
		if ((i + j) % 2 == 0) {
			mcmf.addEdge(N*N, i*N + j, 1, 0);
			mcmf.addEdge(i*N + j, N*N + 1, 1, 0);
			if (i != 0) mcmf.addEdge(i*N + j, (i - 1)*N + j, 1, calW(A[i][j],A[i-1][j]));
			if (j != N - 1) mcmf.addEdge(i*N + j, i*N + j + 1, 1, calW(A[i][j], A[i][j + 1]));
			if (i != N - 1) mcmf.addEdge(i*N + j, (i + 1)*N + j, 1, calW(A[i][j], A[i + 1][j]));
			if (j != 0) mcmf.addEdge(i*N + j, i*N + j - 1, 1, calW(A[i][j], A[i][j -1]));
		}
		else {
			mcmf.addEdge(i*N+j, N*N+1, 1, 0);
		}
	}
	mcmf.SPFA();
	printf("%d\n",-mcmf.MinCost);
	return 0;
}