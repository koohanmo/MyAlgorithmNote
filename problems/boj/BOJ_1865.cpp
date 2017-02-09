#include<iostream>
#include <string.h>
#include <vector>
#include <utility>
#define INF 1<<30
using namespace std;

int main() {

	int T; cin >> T;
	while (T--) {

		int N, M, W; cin >> N >> M >> W;
		vector<pair<int, int>> graph[600];
		int a, b, c;
		for (int i = 0; i < M; i++) {
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, c));
			graph[b].push_back(make_pair(a, c));

		}
		for (int i = 0; i < W; i++) {
			cin >> a >> b >> c;
			graph[a].push_back(make_pair(b, -c));
		}


		bool update;
		bool isM = false;
		vector<int> dist(501, INF);
		dist[1] = 0;

		for (int i = 0; i < N; i++) {
			update = false;
			for (int here = 1; here <= N; here++) {
				if (dist[here] == INF) continue;
				for (auto next : graph[here]) {
					int nextNode = next.first;
					int nextWeight = next.second;

					if (dist[nextNode] > dist[here] + nextWeight) {
						dist[nextNode] = dist[here] + nextWeight;
						update = true;
						if (i == N - 1) isM = true;
					}
				}
			}
			if (!update) break;
		}

		if (isM)cout << "YES" << endl;
		else cout << "NO" << endl;



	}


	return 0;
}