#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N, M, K;
vector<pair<int, int>> adj[230000];
vector<int> dijk(int start) {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist((N+1)*(K+1), 1e9);
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		auto cur = pq.top();
		int curV = cur.second;
		int curDist = cur.first;
		pq.pop();
		if (curDist > dist[curV]) continue;

		for (auto next : adj[curV]) {
			int nextDist = curDist + next.second;
			int nextV = next.first;

			if (nextDist < dist[nextV]) {
				pq.push(make_pair(nextDist, nextV));
				dist[nextV] = nextDist;
			}
		}
	}
	return dist;
}

int main() {
	scanf("%d %d %d",&N,&M,&K);
	for (int i = 0; i < M; i++) {
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		adj[a*(K+1)].push_back(make_pair(b*(K+1), c));
		adj[b*(K + 1)].push_back(make_pair(a*(K + 1), c));
	}
	for (int i = 1; i <= N; i++) {
		for (int k=0; k<adj[i*(K+1)].size();k++){
			auto cur = adj[i*(K + 1)][k];
			if (cur.second == 0)continue;
			for (int j = 0; j <= K; j++) {
				if (j != 0) adj[i*(K+1) + j].push_back(make_pair(cur.first+j,cur.second));
				if (j != K) adj[i*(K+1) + j].push_back(make_pair(cur.first + j + 1,0));
			}
		}
	}
	vector<int>dist = dijk(1*(K+1));
	int Ans = 1e9;
	for (int i = N*(K + 1); i <= N*(K + 1) + K; i++) Ans = Ans < dist[i] ? Ans : dist[i];
	printf("%d\n",Ans);

}