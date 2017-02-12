#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> G(1001);
vector<int> M(1001,-1);
vector<bool> V(1001);

bool dfs(int cur) {
	for (auto next : G[cur]) {
		if (V[next]) continue;
		V[next] = true;
		if (M[next] == -1 || dfs(M[next])) {
			M[next] = cur;
			return true;
		}
	}
	return false;
}

int matching(int N) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		fill(V.begin(), V.end(), false);
		if (dfs(i)) ret++;
	}
	return ret;
}
int main() {
	int N, M, K; scanf("%d %d %d",&N,&M,&K);
	for (int i = 0; i < N; i++) {
		int n; scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int c; scanf("%d",&c);
			G[i].push_back(c-1);
		}
	}

	int Ans = matching(N);
	int ano = K;
	while (ano > 0) {
		int curM=matching(N);
		if (curM == 0) break;
		Ans += curM > ano ? ano : curM;
		ano -= curM;
	}
	printf("%d\n",Ans);
}