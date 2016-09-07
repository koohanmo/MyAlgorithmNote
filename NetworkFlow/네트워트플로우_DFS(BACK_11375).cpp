#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define SOURCE 0
#define SINK N+M+1
using namespace std;

int N, M;
int net[2002][2002];
vector<int> parents(2002);
bool visit[2002];
void backPath(int n) {
	while (n != 0) {
		int child = n;
		n = parents[n];
		//1감소
		net[n][child] --;
		net[child][n] ++;
	}
}

bool dfs(int start) {
	if (start == SINK) return true;
	for (int i = 0; i < N + M + 2;i++) {
		if (net[start][i] <= 0 || visit[i]==true) continue;
		//뺵경로 설정
		parents[i] = start;
		
		visit[i] = true;
		if (dfs(i)) return true;
	}
	return false;
}


int main()
{
	cin >> N >> M;
	memset(net, 0, sizeof(net));
	memset(visit, 0, sizeof(visit));
	int a, b;
	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			net[i][N+b] = 1;
		}
	}
	//SOURCE -> 직원
	for (int i = 1; i <= N; i++) net[0][i] = 2;
	//일 ->SYNC
	for (int i = 1+N; i <= N+M; i++) net[i][SINK] = 1;

	int result = 0;
	while (dfs(0)) {
		result++;
		//빽엣지
		backPath(SINK);
		memset(visit, 0, sizeof(visit));
	}
	cout << result << endl;

	return 0;
}