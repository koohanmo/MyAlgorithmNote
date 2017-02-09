#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXC 10
using namespace std;

vector<int> adj[100001];
int D[100001][MAXC];

int dfs(int cur, int color,int par) {
	int& ret = D[cur][color];
	if (ret != 0) return ret;
	ret = color;
	for (int next : adj[cur]) {
		if (next == par) continue;
		int temp = 1 << 30;
		for (int i = 1; i <= MAXC; i++) {
			if (color == i) continue;
			int v = dfs(next, i, cur);
			if (temp > v)  temp = v;
		}
		ret += temp;
	}
	return ret;
}

int main() { 
	int N; scanf("%d",&N);
	for (int i = 0; i < N - 1; i++) {
		int a, b; scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int Ans = 1 << 30;
	for (int i = 1; i <= MAXC; i++) {
		int t=dfs(1, i, -1);
		Ans = Ans > t ? t : Ans;
	}
	printf("%d\n",Ans);
	return 0;
}