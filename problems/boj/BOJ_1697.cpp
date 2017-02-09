#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int V[200200];
int main() {
	int N, K; scanf("%d %d",&N, &K);
	memset(V,-1,sizeof(V));
	V[N] = 0;
	queue<int> Q;
	Q.push(N);
	while (!Q.empty()) {
		int C = Q.front();
		Q.pop();
		if (C + 1 <= 200100 && (V[C + 1] == -1 || V[C + 1] > V[C] + 1)) {
			Q.push(C + 1);
			V[C + 1] = V[C] + 1;
		}
		if (C -1 >=0&& (V[C - 1] == -1 || V[C - 1] > V[C] + 1)) {
			Q.push(C - 1);
			V[C - 1] = V[C] + 1;
		}
		if (C * 2 <= 200100 && (V[C *2] == -1 || V[C *2] > V[C] + 1)) {
			Q.push(C *2);
			V[C *2] = V[C] + 1;
		}
	}
	printf("%d\n",V[K]);

	return 0;
}