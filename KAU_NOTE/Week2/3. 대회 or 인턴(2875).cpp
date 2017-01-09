#include <cstdio>
int main() {
	int N, M, K; scanf("%d %d %d", &N, &M, &K);
	int S = N + M - K, Ans = 0;
	while (S > 2 && N > 1 && M > 0) {
		N -= 2; M--; S -= 3; Ans++;
	}
	printf("%d\n", Ans);
}