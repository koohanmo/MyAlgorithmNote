#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
using namespace std;
int N, S,D[1001][1001][2];
pair<int, int> A[1001];
int solve(int left, int right,int dir,int totW) {
	if (left == 0 && right == N - 1) return 0;
	int& ret = D[left][right][dir];
	if (ret != -1) return ret;
	int lv = 1 << 30, rv = 1 << 30;
	if (left > 0)  lv = solve(left - 1, right, 0, totW - A[left - 1].second) + totW *(dir == 0 ? (A[left].first - A[left - 1].first) : A[right].first - A[left - 1].first);
	if (right < N) rv = solve(left, right+1, 1, totW - A[right + 1].second) + totW *(dir == 0 ? (A[right+1].first - A[left].first) : A[right+1].first - A[right].first);
	return ret = min(lv, rv);
}

int main() {
	memset(D,-1,sizeof(D));
	scanf("%d %d",&N,&S);
	int tW=0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &A[i].first, &A[i].second);
		tW += A[i].second;
	}
	int Ans = solve(S-1, S-1, 1, tW - A[S-1].second);
	printf("%d\n",Ans);
	return 0;
}