#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 int N, M, A[1001], B[1001],C,D[1001][1001];

int solve(int up, int down) {
	if (down == M) return 0;
	if (up == N) return 1 << 30;
	int& ret = D[up][down];
	if (ret != -1) return ret;
	return ret = min(solve(up + 1, down + 1) + abs(A[up] - B[down]), solve(up + 1, down));
}
int main() {
	 scanf("%d %d",&N,&M);
	 for (int i = 0; i < N; i++) scanf("%d ", A + i);
	 for (int i = 0; i < M; i++) scanf("%d ", B + i);
	 sort(A, A + N);
	 sort(B, B + M);
	 if (N < M) { swap(A, B); swap(N, M); }
	 memset(D, -1, sizeof(D));
	 printf("%d\n", solve(0, 0));
	 return 0;
}