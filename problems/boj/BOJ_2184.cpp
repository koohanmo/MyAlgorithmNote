#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll N, S, D[1001][1001][2], A[1001];
inline ll min(ll a, ll b) { return a < b ? a : b; }
int solve(ll left, ll right, ll dir) {
	if (left == 0 && right == N - 1) return 0;
	ll& ret = D[left][right][dir];
	if (ret != -1) return ret;
	ll lv = 1e15, rv = 1e15;
	ll nam = (N - (right - left + 1));
	if (left > 0)  lv = solve(left - 1, right, 0) + nam *(dir == 0 ? (A[left] - A[left - 1]) : A[right]- A[left - 1]);
	if (right < N-1) rv = solve(left, right + 1, 1) + nam *(dir == 0 ? (A[right + 1] - A[left]) : A[right + 1] - A[right]);
	return ret = min(lv, rv);
}

int main() {
	memset(D, -1, sizeof(D));
	scanf("%lld %lld", &N, &S);
	for (int i = 0;i < N; i++) scanf("%lld ", &A[i]);
	sort(A, A + N);
	ll Ans = 1e15;
	if (S <= A[0]) 	Ans = solve(0, 0, 1) + (A[0] - S)*N;
	else if (S >= A[N - 1]) Ans = solve(N-1, N-1, 00) + (S-A[N-1])*N;
	else {
		int idx = 0;
		for (; idx < N - 1; idx++) if (A[idx] <= S && A[idx + 1] > S) break;
		Ans = min(solve(idx, idx, 0) + (S - A[idx])*N, solve(idx + 1, idx + 1, 1) + (A[idx + 1] - S)*N);
	}
	printf("%lld\n", Ans);
	return 0;
}