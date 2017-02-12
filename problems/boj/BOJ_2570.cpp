#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

vector < vector< pair<int, int> > > T;
vector< vector<int> > adj(20002);
vector <int> nodes;
vector <int> V(20002, -1);
vector <int> M(20002, -1);


bool dfs(int cur) {
	if (V[cur]!=-1) return false;
	V[cur] = 1;
	for (int next : adj[cur]) {
		if (M[next] == -1 || dfs(M[next])) {
			M[next] = cur;
			return true;
		}
	}
	return false;
}


int main() {
	int N, M; scanf("%d %d",&N,&M);
	T.assign(N + 1, vector<pair<int, int>>(N + 1, make_pair(0, 0)));
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d",&a,&b);
		T[a][b] = make_pair(-1, -1);
	}
	int nodeCnt = 0;
	for (int i = 1; i <= N; i++)for (int j = 1; j<= N; j++) {
		if (T[i][j].first == -1) {
			//printf("(-1,-1) ");
			continue;
		}
		if (i == 1) {
			T[i][j] = make_pair(nodeCnt, nodeCnt + 1);
			nodes.push_back(nodeCnt);
			nodeCnt += 2;
		}
		else if (j == 1) {
			nodes.push_back(nodeCnt);
			T[i][j].first = nodeCnt++;
			if (T[i - 1][j + 1].first == -1) T[i][j].second = nodeCnt++;
			else T[i][j].second = T[i - 1][j + 1].second;
		}
		else if (j == N) {
			if (T[i - 1][j - 1].first == -1) {
				nodes.push_back(nodeCnt);
				T[i][j].first = nodeCnt++;
			}
			else T[i][j].first = T[i - 1][j - 1].first;
			T[i][j].second = nodeCnt++;
		}
		else {
			if (T[i - 1][j - 1].first == -1) {
				nodes.push_back(nodeCnt);
				T[i][j].first = nodeCnt++;
			}
			else T[i][j].first = T[i - 1][j - 1].first;
			if (T[i - 1][j + 1].first == -1) T[i][j].second = nodeCnt++;
			else T[i][j].second = T[i - 1][j + 1].second;
		}

		//printf("(%d,%d) ",T[i][j].first,T[i][j].second);
		//if (j == N) puts("");
		adj[T[i][j].first].push_back(T[i][j].second);
	}

	int ret = 0;
	for (int cur : nodes) {
		V.assign(20002, -1);
		if (dfs(cur)) ret++;
	}
	printf("%d\n",ret);
	return 0;
}