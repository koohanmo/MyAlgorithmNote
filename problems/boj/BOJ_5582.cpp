#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
char S1[4001], S2[4001];
int D[4001][4001];
int main() {
	scanf("%s %s",S1,S2);
	int l1 = strlen(S1), l2 = strlen(S2),Ans=0;
	for (int i = 0; i <l1; i++) for (int j = 0; j < l2; j++) {
		if (S1[i] == S2[j]) {
			if (i!=0 && j!=0) {
				D[i][j] = D[i - 1][j - 1] + 1;
				Ans = Ans > D[i][j] ? Ans : D[i][j];
			}
			else D[i][j] = 1;
		}
	}
	printf("%d\n",Ans);
	return 0;
}