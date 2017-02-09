#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include <string.h>
#include <vector>
#include <utility>
#define ll long long
#define INF 1e11
using namespace std;

int main() {

	ll F[101][101];
	ll N,S,D,M; scanf("%lld %lld %lld %lld ",&N,&S,&D,&M);
	vector<pair<ll, ll>> graph[101];
	ll a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%lld %lld %lld",&a,&b,&c);
		graph[a].push_back(make_pair(b, c));
		F[a][b] = 1;
	}
	vector<ll> budget(N, 0);
	for (int i = 0; i < N; i++) {
		scanf("%lld ", &budget[i]);
		F[i][i] = 1;
	}

	for (int k = 0; k<N; k++)
		for (int i = 0; i<N; i++)
			for (int j = 0; j<N; j++)
				if (F[i][k] && F[k][j]) F[i][j] = 1;

	bool isM = false;
	vector<ll> dist(101, (ll)INF);
	dist[S] = -budget[S];

	for (int i = 0; i < N; i++) {
		for (ll here = 0; here < N; here++) {
			if (dist[here] == INF) continue;
			for (auto next : graph[here]) {
				ll nextNode = next.first;
				ll nextWeight = next.second-budget[nextNode];
				if (dist[nextNode] > dist[here] + nextWeight) {
					dist[nextNode] = dist[here] + nextWeight;
					if (i == N - 1 && F[nextNode][D]) isM = true;
				}
			}
		}
	}
		
	
	if (dist[D] == INF) printf("gg\n");
	else if (isM) printf("Gee\n");
	else printf("%lld\n",-dist[D]);
	return 0;
}

