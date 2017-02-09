#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main() {
	int N; scanf("%d ",&N);
	char S[110][110];
	for (int i = 0; i < N; ++i) scanf("%s",&S[i]);
	int RGB[110][110],GB[110][110];
	memset(RGB,-1,sizeof(RGB));
	memset(GB, -1, sizeof(GB));
	
	int AR = 0, AG = 0;
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		if (RGB[i][j] != -1) continue;
		AR++;
		queue<pair<int,int>> Q;
		Q.push(make_pair(i, j));
		RGB[i][j] = 1;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int k = 0; k < 4; k++) {
				int nextY = cur.first + dir[k][0];
				int nextX = cur.second + dir[k][1];
				if (nextY <0 || nextY > N || nextX<0 || nextX>N || RGB[nextY][nextX] != -1)  continue;
				if (S[nextY][nextX] == S[cur.first][cur.second]) {
					Q.push(make_pair(nextY, nextX));
					RGB[nextY][nextX] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)for (int j = 0; j < N; j++) {
		if (GB[i][j] != -1) continue;
		AG++;
		queue<pair<int, int>> Q;
		Q.push(make_pair(i, j));
		GB[i][j] = 1;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			for (int k = 0; k < 4; k++) {
				int nextY = cur.first + dir[k][0];
				int nextX = cur.second + dir[k][1];
				if (nextY <0 || nextY > N || nextX<0 || nextX>N || GB[nextY][nextX] != -1)  continue;
				
				char ch = S[cur.first][cur.second];
				if (ch == 'R' || ch=='G') {
					if (S[nextY][nextX] == 'R' || S[nextY][nextX] =='G') {
						Q.push(make_pair(nextY, nextX));
						GB[nextY][nextX]=1;
					}
				}
				else {
					if (S[nextY][nextX] == 'B') {
						Q.push(make_pair(nextY, nextX));
						GB[nextY][nextX]=1;
					}
				}
				
			}
		}
	}

	printf("%d %d\n", AR,AG);
	return 0;
}