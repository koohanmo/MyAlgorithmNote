#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int T[10001][2];
int L[10001][2];
int C[10001][2];
int maxL = 0;

int childN(int cur) {
	if (cur > 10001) return 0;
	if (T[cur][0] != -1) C[cur][0]= childN(T[cur][0]);
	if (T[cur][1] != -1) C[cur][1]= childN(T[cur][1]);
	return C[cur][0] + C[cur][1]+1;
}

void solve(int cur,int level,int left, int right) {
	if (cur > 10001) return;
	if (level > maxL) maxL = level;
	int pos = left+C[cur][0];
	if (L[level][0] == 0 || L[level][0] > pos) L[level][0] = pos;
	if (L[level][1] == 0 || L[level][1] < pos) L[level][1] = pos;

	if (T[cur][0] != -1) solve(T[cur][0], level + 1, left, pos - 1);
	if (T[cur][1] != -1) solve(T[cur][1], level+1, pos+1,right);

}

int main() {
	int N; scanf("%d",&N);
	int root = 0;
	for (int i = 0; i < N; i++) {
		int a, b, c; scanf("%d %d %d",&a,&b,&c);
		if (i == 0) root = a;
		T[a][0] = b;
		T[a][1] = c;
	}
	childN(root);
	solve(root,1,1,N+1);
	int Ans[2] = { -1,-1 };
	for (int i = 1; i <= maxL; i++) {
		if (L[i][1] - L[i][0] + 1 > Ans[1]) {
			Ans[1] = L[i][1] - L[i][0] + 1;
			Ans[0] = i;
		}
	}
	printf("%d %d\n",Ans[0], Ans[1]);
	return 0;
}