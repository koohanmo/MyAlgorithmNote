#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int max(int a, int b) { return a > b ? a : b; }

int D[31][1001][3];
int T, W, A[1001];
int main() {
	memset(D, 0, sizeof(D));
	scanf("%d %d",&T,&W);
	for (int i = 1; i <= T; i++) {
		scanf("%d", A + i);
		D[0][i][1] = D[0][i - 1][1];
		if (A[i] == 1) D[0][i][1]++;
	}
	for (int i = 1; i <= W; i++) {
		for (int j = 1; j <= T; j++) {
			D[i][j][1] = max(max(D[i - 1][j - 1][2], D[i - 1][j][2]), D[i][j - 1][1]);
			D[i][j][2] = max(max(D[i - 1][j - 1][1], D[i - 1][j][1]), D[i][j - 1][2]);
			if (A[j] == 1) D[i][j][1]++;
			else D[i][j][2]++;
		}
	}
	printf("%d\n",max(D[W][T][1],D[W][T][2]));
	return 0;
}