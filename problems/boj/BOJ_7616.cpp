#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#define SOURCE 3
#define SINK 4
using namespace std;

struct Edge {
	int next, cap, flow;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int next, int cap) {
		this->next = next;
		this->cap = cap;
		this->flow = 0;
	}
	int spare() { return cap - flow; }
	void addFlow(int f) { 
		flow += f; 
		dual->flow -= f;
	}
};

int main() {
	int caseCnt = 0;
	while (true) {
		caseCnt++;
		int K, M; scanf("%d %d", &K, &M);
		if (K == 0 && M == 0) return 0;
		vector<vector<Edge*>> adj((M+1)*2+1);

		for (int i = 3; i <= M; i++) {
			Edge* e1 = new Edge(i*2+1, 1);
			Edge* e2 = new Edge(i*2, 0);
			e1->dual = e2;
			e2->dual = e1;
			adj[i * 2].push_back(e1);
			adj[i * 2 + 1].push_back(e2);
		}

		for (int i = 1; i <= M; i++) {
			while (1) {
				int a;
				char c;
				scanf("%d%c", &a, &c);
				Edge* e1 = new Edge(a*2, 1);
				Edge* e2 = new Edge(i*2+1, 0);
				e1->dual = e2;
				e2->dual = e1;
				adj[i * 2 + 1].push_back(e1);
				adj[a * 2].push_back(e2);
				if (c == '\n') break;
			}
		}

		bool isCan = true;

		for (int i = 0; i < K; i++) {
			vector<int> prev((M + 1) * 2 + 1, -1);
			vector<Edge*> path(10002, 0);
			queue<int> Q;
			Q.push(SOURCE);
			while (!Q.empty()) {
				int curr = Q.front();
				Q.pop();
				for (Edge *e : adj[curr]) {
					int next = e->next;
					if (e->spare() > 0 && prev[next] == -1) {
						Q.push(next);
						prev[next] = curr;
						path[next] = e;
						if (next == SINK) break;
					}
				}
			}
			if (prev[SINK] == -1) {
				isCan = false;
				break;
			}

			int flow = 1;
			for (int i = SINK; i != SOURCE; i = prev[i])
				path[i]->addFlow(flow);
		}
		printf("Case %d:\n", caseCnt);
		if (!isCan) printf("Impossible\n");
		else {
			for (int i = 0; i < K; i++) {
				int cur = SOURCE;
				printf("%d ",cur/2);
				while (cur != SINK) {
					if(cur%2==0) printf("%d ", cur/2);
					for (auto e : adj[cur]) {
						if (e->flow == 1) {
							e->flow = 0;
							cur = e->next;
							break;
						}
					}
				}
				printf("2\n");
			}
		}
		printf("\n");
	}
	return 0;
}