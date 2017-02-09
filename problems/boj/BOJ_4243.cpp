#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#define LEFT 0
#define RIGHT 1
#define ll long long
ll min(ll a, ll b) { return a < b ? a : b; }
ll N, C, A[110],D[110][110][2];
ll solve(ll left, ll right, ll dir) {
	if (left == 1 && right == N) return 0;	
	ll& ret = D[left][right][dir];
	if (ret != -1) return ret;
	ll nam = N - (right - left) - 1,lv=1e15,rv=1e15;
	if(left> 1) lv=solve(left - 1, right, LEFT) + (dir == LEFT ? nam*(A[left]-A[left-1]) : nam*(A[right] - A[left-1]));
	if (right < N) rv=solve(left, right + 1, RIGHT) + (dir == RIGHT ? nam*(A[right+1] - A[right]) : nam*(A[right+1] - A[left]));
	return ret = min(lv, rv);	
}
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		memset(D,-1,sizeof(D));
		memset(A, 0, sizeof(A));
		scanf("%lld %lld",&N,&C);
		for (int i = 2; i <= N; i++) {
			scanf("%lld ", A + i);
			A[i] += A[i - 1];
		}
		printf("%lld\n",solve(C,C,LEFT));
	}
	return 0;
}