#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100001];

int main() {
	int N; scanf("%d",&N);
	
	for (int i = 0; i < N; i++) {
		int a, b; scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> Q;
	vector<bool> V(N + 1, false);
	vector<int> P(N + 1, 0);
	V[1] = true;
	Q.push(1);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();

		for (int next : adj[cur]) {
			if (!V[next]) {
				V[next] = true;
				P[next] = cur;
				Q.push(next);
			}
		}
	}
	for (int i = 2; i <= N; i++) printf("%d\n",P[i]);

	return 0;
}