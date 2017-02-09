#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
int T[101][101];
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int main() {
	int N; scanf("%d",&N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d ",&T[i][j]);
	int Ans = 0;
	for (int H = 0; H <= 100; H++) {
		int V[101][101];
		memset(V,-1,sizeof(V));
		int cA = 0;
		for (int i = 0; i < N; i++) for(int j=0;j<N;j++){
			if (V[i][j] != -1 || T[i][j] <H) continue;
			cA++;
			queue< pair<int, int> > Q;
			V[i][j] = 1;
			Q.push(make_pair(i, j));
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int k = 0; k < 4; k++) {
					int nextY = cur.first + dir[k][0];
					int nextX = cur.second + dir[k][1];
					if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || V[nextY][nextX]==1 || T[nextY][nextX]<H) continue;
					Q.push(make_pair(nextY, nextX));
					V[nextY][nextX] = 1;
				}
			}
		}
		Ans = Ans < cA ? cA : Ans;
	}
	printf("%d\n",Ans);
	return 0;
}