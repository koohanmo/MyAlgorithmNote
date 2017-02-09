#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int T; scanf("%d ",&T);
	while (T--) {
		int N, M, DN; scanf("%d %d %d",&N,&M,&DN);
		int S, G, H; scanf("%d %d %d",&S,&G,&H);

		vector < pair<int, int> > adj[2002];
		for (int i = 0; i < M; i++) {
			int a, b, d; scanf("%d %d %d", &a, &b, &d);
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
		}

		vector<int> D(DN, 0);
		for (int i = 0; i < DN; i++) scanf("%d ",&D[i]);
	
	
	}
	return 0;
}