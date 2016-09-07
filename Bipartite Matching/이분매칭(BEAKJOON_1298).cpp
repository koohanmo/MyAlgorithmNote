#include <cstdio>
#include <vector>
using namespace std;
#define NOTE N
vector<int> graph[5120];
int visit[5210];
int match[5210];

bool dfs(int x) {
	if (visit[x] != 0) return false;
	visit[x] = 1;
	for (auto next : graph[x]) {
		if (match[next]==-1 || dfs(match[next])) {
			match[next] = x;
			match[x] = next;
			return true;
		}
	}
	return false;
}


int main() {

	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d",&a,&b);
		graph[a].push_back(NOTE+b);
	}
	int result = 0;
	for (int i = 0; i <= NOTE+M; i++) {
		match[i] = -1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= N + M; j++) visit[j] = 0;
		if (dfs(i)) result++;
	}
	printf("%d", result);

	return 0;
}