#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define ll long long 
ll A[1010];
ll D[1010][1010];
ll N, M;

ll min(ll a, ll b) { return a < b ? a : b; }

ll solve(ll curIdx, ll nam) {
	if (curIdx >= N) return 0;
	ll& ret = D[curIdx][nam];
	if (ret != -1) return ret;

	ll cur = solve(curIdx + 1, M - A[curIdx]) + (nam*nam);
	if (nam - A[curIdx] >= 1) cur = min(cur, solve(curIdx + 1, nam - A[curIdx]-1));
	return ret = cur;
}

int main() {
	memset(D, -1, sizeof(D));
	scanf("%lld %lld", &N, &M);
	for (int i = 0; i < N; i++)  scanf("%lld", A + i);
	printf("%lld\n", solve(1, M - A[0]));
	return 0;
}