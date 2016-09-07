#include<iostream>
#include <utility>
#include<vector>
#define INF 1<<30
using namespace std;


int main() {

	vector<pair<int, int>> graph[501];
	int N, M; cin >> N >> M;
		
	int a, b, c;
	for (int i = 0; i < M;i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	//거리를 저장
	vector<int> dist(N + 1,INF);
	//초기화
	dist[1] = 0;
	bool update = false;

	for (int i = 0; i < N; i++) {
		update = false;
		for (int j = 1; j <= N; j++) {
			for (auto k : graph[j]) {
				int next = k.first;
				int weight = k.second;
				if (dist[next] > dist[j] + weight) {
					dist[next] = dist[j] + weight;
					update = true;
				}
			}
		}
		//더이상 업데이트가 필요하지 않다면 탈출
		if (!update) break;
	
	}
	//음의 사이클이 있다면
	if (update) cout << -1 << endl;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) cout << -1 << endl;
			else cout << dist[i] << endl;
		}
	}
	

	return 0;
}