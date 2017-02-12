#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

char A[102][102];
vector<vector<pair<int, int>>> T(101,vector<pair<int,int>>(101,make_pair(0,0)));
vector<vector<int>> adj(20002);
vector<int>  seroNodes;
vector<bool> V(20002, false);
vector<int> M(20002, -1);
int dfs(int cur) {
	if (V[cur]) return false;
	V[cur] = true;
	for (int next : adj[cur]) {
		if (M[next] ==-1  || dfs(M[next])) {
			M[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){

	int N; scanf("%d",&N);
	for (int i = 0; i < N; i++)	scanf("%s", A[i]);
	int nodeCnt = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		if (A[i][j] == 'X') {
			T[i][j] = make_pair(-1, -1);
			continue;
		}
		if (i != 0) {//세로
			if (T[i - 1][j].first == -1) {
				T[i][j].first = nodeCnt++;
				seroNodes.push_back(nodeCnt - 1);
			}
			else T[i][j].first = T[i - 1][j].first;
		}
		else {
			T[i][j].first = nodeCnt++;
			seroNodes.push_back(nodeCnt - 1);
		}
		if (j != 0) {//가로
			if (T[i][j-1].second == -1) {
				T[i][j].second = nodeCnt++;
			}
			else T[i][j].second = T[i][j-1].second;
		}
		else T[i][j].second = nodeCnt++;
		adj[T[i][j].first].push_back(T[i][j].second);
		//printf("%d,%d ",T[i][j].first, T[i][j].second);
		//if (j == N - 1) puts("");
	}
	int ret = 0;
	for (int cur : seroNodes) {
		V.assign(20002, false);
		if (dfs(cur))ret++;
	}
	printf("%d\n",ret);


	return 0;
}