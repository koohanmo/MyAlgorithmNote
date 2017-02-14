#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct MaxFlowDinic {

	struct Edge {
		int next, cap, flow;
		Edge* dual;
		Edge(int n, int c) : next(n), cap(c), flow(0) {}
		int spare() { return cap - flow; }
		void addFlow(int f) {
			this->flow += f;
			dual->flow -= f;
		}
	};

	int N,source,sink;
	vector<vector<Edge*>> adj;
	vector<int> level;
	vector<int> work;

	MaxFlowDinic(int source, int sink, int N) {
		this->source = source;
		this->sink = sink;
		this->N = N;
		adj.resize(N);
	}
	
	void AddEdge(int start, int end, int cap) {
		Edge* e1 = new Edge(end,cap);
		Edge* e2 = new Edge(start, 0);
		e1->dual = e2;
		e2->dual = e1;
		adj[start].push_back(e1);
		adj[end].push_back(e2);
	}

	bool AssignLevel() {
		level.assign(N, -1);
		level[source] = 0;

		queue<int> Q;
		Q.push(source);
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			for (Edge* next : adj[cur]) {
				int nextV = next->next;
				if (level[nextV] == -1 && next->spare() > 0) {
					level[nextV] = level[cur] + 1;
					Q.push(nextV);
				}
			}
		}
		return level[sink] != -1;
	}

	int BlockFlow(int cur, int sink, int curFlow) {
		if (cur == sink) return curFlow;

		for (int& i = work[cur]; i < adj[cur].size(); i++) {
			Edge* nextEdge = adj[cur][i];
			int nextV = nextEdge->next;
			if (nextEdge->spare() > 0 && level[nextV] == level[cur] + 1) {
				int minFlow = BlockFlow(nextV, sink, min(nextEdge->spare(), curFlow));
				if (minFlow > 0) {
					nextEdge->addFlow(minFlow);
					return minFlow;
				}
			}
		
		}
		return 0;
	}

	int maxflow() {
		int maxF = 0;
		while (AssignLevel()) {
			work.assign(N, 0);
			while (true) {
				int flow = BlockFlow(source, sink, 1 << 30);
				if (flow == 0) break;
				maxF += flow;
			}
		}
		return maxF;
	}

};
int main() {
	int N; scanf("%d",&N);
	MaxFlowDinic mfd(N, N + 1, N + 2);
	for (int i = 0; i < N; i++) {
		int a; scanf("%d",&a);
		if (a == 1) mfd.AddEdge(N, i, 1<<30);
		else if (a == 2) mfd.AddEdge(i, N + 1, 1<<30);
	}
	for (int i = 0; i < N; i++) for(int j=0;j<N;j++){
		int a; scanf("%d",&a);
		if (i != j) mfd.AddEdge(i, j, a);
	}
	printf("%d\n", mfd.maxflow());

	vector<bool> isA(N + 2,false);
	queue<int> Q;
	Q.push(N);
	isA[N] = true;
	while (!Q.empty()) {
		int curV = Q.front();
		Q.pop();
		for (auto nextEdge : mfd.adj[curV]) {
			int nextV = nextEdge->next;
			if (nextEdge->spare() > 0 && !isA[nextV]) {
				isA[nextV] = true;
				Q.push(nextV);
			}
		}
	}
	
	for (int i = 0; i < N; i++) if (isA[i]) printf("%d ",i+1);
	puts("");
	for (int i = 0; i < N; i++) if (!isA[i]) printf("%d ", i + 1);
	puts("");

	return 0;
}