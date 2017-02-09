#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

vector<int> A(10001);
vector<int> adj[10001];
int D[10001][2];


int dfs(int cur, int ox, int par) {
	int& ret = D[cur][ox];
	if (ret != 0) return ret;

	int temp = ox==0? 0:A[cur];
	int cnt = 0;
	for (int next : adj[cur]) {
		if (next == par) continue;
		if (ox == 0) //우수마을 X 최소 1개==우수마을?
		{
			int a = dfs(next, 0, cur);
			int b = dfs(next, 1, cur);
			temp += a > b ? a : b;
		}
		else { //cur == 우수마을 == 자식노드 모두 비우수마을
			temp += dfs(next, 0, cur);
		}
	}
	return ret=temp;
}

int main() {

	int N; scanf("%d",&N);
	for (int i = 1; i <= N; i++) scanf("%d ",&A[i]);
	for (int i = 1; i < N; i++) {
		int a, b; scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int Ans1 = dfs(1, 0, -1);
	int Ans2 = dfs(1, 1, -1);
	printf("%d\n", Ans1>Ans2? Ans1:Ans2);
	return 0;
}