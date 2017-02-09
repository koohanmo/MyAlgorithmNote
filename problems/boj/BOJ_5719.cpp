#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#include <cstring>
using namespace std;

int N, M;
int S, D;
vector<pair<int, int>> adj[501];
int V[501][501];

vector<int> dijk(int start, vector<pair<int,int>>* adj) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N,1e9);
	dist[S] = 0;
	pq.push(make_pair(0, S));
	while (!pq.empty()) {
		auto cur = pq.top();
		int curV = cur.second;
		int curDist = cur.first;
		pq.pop();
		if (curDist > dist[curV]) continue;

		for (auto next : adj[cur.second]) {
			int nextDist = curDist + next.second;
			int nextV = next.first;

			if (V[curV][nextV] == -1) continue;
			if (nextDist < dist[nextV]) {
				pq.push(make_pair(nextDist, nextV));
				dist[nextV] = nextDist;
			}
		}
	}
	return dist;
}

int main() {
	while (1) {
		for (int i = 0; i < 501; i++) adj[i].clear();
		memset(V, -1, sizeof(V));

		scanf("%d %d ",&N,&M);
		if (N == 0 && M == 0) return 0;
		scanf("%d %d ",&S,&D);

		for (int i = 0; i < M; i++) {
			int U, v, P; scanf("%d %d %d",&U,&v,&P);
			adj[U].push_back(make_pair(v, P));
			V[U][v] = P;
		}

		vector<int> fDist = dijk(S,adj);
		int firstSP = fDist[D];
		if(firstSP!=1e9) {
			//BFS
			queue<int> Q;
			vector<int>visit(N + 1, -1);
			Q.push(D);
			visit[D] = 1;
			while (!Q.empty()) {
				int curV = Q.front();
				Q.pop();

				for (int i = 0; i < N; i++) if(V[i][curV]!=-1 && fDist[curV]-fDist[i]==V[i][curV]){
					V[i][curV] = -1;
					Q.push(i);
				}
				
			}
			fDist = dijk(S,adj);
		}
		if (fDist[D] == 1e9) printf("-1\n");
		else printf("%d\n", fDist[D]);

	}

}