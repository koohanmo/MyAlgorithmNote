#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define ll long long
ll min(ll a, ll b) { return a < b ? a : b; }
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		ll N, S, A[110], D[110][110][2];
		memset(D, 0, sizeof(D));
		scanf("%lld %lld", &N, &S);
		for (int i = 1; i <N; i++) {
			scanf("%lld ", A + i);
			A[i] += A[i - 1];
		}
		for (int l = --S; l >= 0; --l)for (int r = S; r < N; ++r) {
			if (l == r) D[l][r][0] = D[l][r][1] = 0;
			else {
				ll n = (N - r + l);
				if(l<S)D[l][r][0] = min(D[l + 1][r][0] +n*(A[l + 1] - A[l]), D[l + 1][r][1] + n*(A[r] - A[l]));
				else D[l][r][0] = 1e15;
				if(S<r)D[l][r][1] = min(D[l][r - 1][0] + n*(A[r] - A[l]), D[l][r - 1][1] + n*(A[r] - A[r - 1]));
				else D[l][r][1] = 1e15;
			}
		}
		printf("%lld\n", min(D[0][N-1][0],D[0][N-1][1]));
	}
	return 0;
}