#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

//A==1, a==27;
vector<int> arr[52];
int cap[52][52];

int edmon(int start, int end) {
	int ret = 0;

	int parent[52];

	while (true) {//더 이상 경로가 없을 때 까지
		queue<int> qu;
		qu.push(start);

		memset(parent, -1, sizeof(parent));
		parent[start] = start;
		parent[end] = -1;

		//모두 탐색하거나, 마지막 경로를 도착 할 때까지 BFS
		while (!qu.empty() && parent[end]==-1) {
			int cur = qu.front();
			qu.pop();

			for (int nextIdx = 0; nextIdx < arr[cur].size();nextIdx++) {
				int next = arr[cur][nextIdx];
				if (cap[cur][next] > 0 && parent[next] == -1) {
					parent[next] = cur;
					qu.push(next);
				}
			}
		}
		if (parent[end] == -1) break; //Z를 가지 못했으면 ㅂㅇㅂㅇ

		int minFlow = 1 << 30;
		for (int p = end; p != parent[p]; p = parent[p]) {
			minFlow = min(minFlow, cap[parent[p]][p]);
		}

		for (int p = end; p != parent[p]; p = parent[p]) {
			cap[parent[p]][p] -= minFlow;
			cap[p][parent[p]] += minFlow;
		}
		ret += minFlow;
	}
	return ret;
}


inline int Ctoi(char ch) {
	if (ch >= 'a') return ch - 'a' + 26;
	else return ch - 'A';
}

int main() {

	int n; scanf("%d",&n);
	memset(arr, 0, sizeof(arr));
	memset(cap, 0, sizeof(cap));
	for (int i = 0; i < n; i++) {
		char a, b; int t; scanf(" %c %c %d",&a,&b,&t);
		a = Ctoi(a);
		b = Ctoi(b);
		arr[a].push_back(b);
		arr[b].push_back(a);
		cap[a][b] += t;
		cap[b][a] += t;
	}
	printf("%d",edmon(Ctoi('A'),Ctoi('Z')));

	return 0;
}