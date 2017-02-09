#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>> adj[10002];

int main() {

	int N; scanf("%d",&N);
	for (int i = 0; i < N; i++) {
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}

	auto nV = make_pair(1, -1);
	vector<int> V(N+1,-1);
	queue<int> Q;
	V[1] = 0;
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto next : adj[cur]) {
			int nextV = next.first;
			int nextW = next.second;
			if (V[nextV]==-1) {
				V[nextV]= V[cur] + nextW;
				if (V[nextV] > nV.second) {
					nV.first = nextV;
					nV.second = V[nextV];
				}
				Q.push(nextV);
			}
		}
	}

	nV.second = 0;
	V = vector<int>(N + 1, -1);
	V[nV.first] = 0;
	Q.push(nV.first);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto next : adj[cur]) {
			int nextV = next.first;
			int nextW = next.second;
			if (V[nextV]==-1) {
				V[nextV] = V[cur] + nextW;
				if (V[nextV] > nV.second) {
					nV.first = nextV;
					nV.second = V[nextV];
				}
				Q.push(nextV);
			}
		}
	}
	printf("%d\n",nV.second);
	return 0;
}