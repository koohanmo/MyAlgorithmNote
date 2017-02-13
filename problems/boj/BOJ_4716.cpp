#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define SOURCE 0
#define SINK 1
#define A 2
#define B 3
#define NODE 4
using namespace std;

struct Edge{
	int next, flow, cap, weight;
	Edge* dual;
	Edge() : Edge(-1,-1,-1) {}
	Edge(int next, int cap, int weight) {
		this->next = next;
		this->cap = cap;
		this->weight = weight;
		flow = 0;
	}
	int spare() { return cap - flow;}
	void addFlow(int f) {
		this->flow += f;
		dual->flow -= f;
	}
};


int SPFA(vector<vector<Edge*>>& G) {
	int cost = 0, maxFlow = 0;

	while (1) {
		vector<int>prev(G.size(), -1);
		vector<Edge*> path(G.size());
		vector<bool> inQ(G.size(), false);
		vector<int> dist(G.size(), 1 << 30);
		queue<int> Q;
		dist[SOURCE] = 0;
		inQ[SOURCE] = true;
		Q.push(SOURCE);

		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			inQ[cur] = false;
			for (auto next : G[cur]) {
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
		maxFlow += flow;
		for (int i = SINK; i != SOURCE; i = prev[i]) {
			cost += flow*path[i]->weight;
			path[i]->addFlow(flow);
		}
	}
	return cost;

}

int main() {
	while (1) {
		int N, An, Bn; scanf("%d %d %d", &N, &An, &Bn);
		if (N == 0 && An == 0 && Bn == 0) return 0;
		vector<vector<Edge*>> G(N + 5);

		Edge* e1 = new Edge(A, An, 0);
		Edge* e2 = new Edge(SOURCE, 0, 0);
		e1->dual = e2;
		e2->dual = e1;
		G[SOURCE].push_back(e1);
		G[A].push_back(e2);

		e1 = new Edge(B, Bn, 0);
		e2 = new Edge(SOURCE, 0, 0);
		e1->dual = e2;
		e2->dual = e1;
		G[SOURCE].push_back(e1);
		G[B].push_back(e2);

		for (int i = 0; i < N; i++) {
			int k, da, db; scanf("%d %d %d", &k, &da, &db);
			e1 = new Edge(SINK, k, 0);
			e2 = new Edge(NODE + i, 0, 0);
			e1->dual = e2;
			e2->dual = e1;
			G[NODE + i].push_back(e1);
			G[SINK].push_back(e2);

			e1 = new Edge(NODE + i, An, da);
			e2 = new Edge(A, 0, -da);
			e1->dual = e2;
			e2->dual = e1;
			G[A].push_back(e1);
			G[NODE + i].push_back(e2);

			e1 = new Edge(NODE + i, Bn, db);
			e2 = new Edge(B, 0, -db);
			e1->dual = e2;
			e2->dual = e1;
			G[B].push_back(e1);
			G[NODE + i].push_back(e2);
		}

		printf("%d\n", SPFA(G));
	}
	return 0;
}