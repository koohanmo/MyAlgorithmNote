#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define ll long long
#define MOD 1000000000
int main() {
	ll D[210][210];
	memset(D, 0, sizeof(D));
	int N, K; scanf("%d %d",&N,&K);
	for (int i = 0; i <= K; i++) {D[i][0] = 1;}
	for (int i = 1; i <= K; i++) for (int j = 1; j <= N; j++)D[i][j] = (D[i - 1][j] + D[i][j - 1]) % MOD;
	printf("%lld\n",D[K][N]);
	return 0;
}