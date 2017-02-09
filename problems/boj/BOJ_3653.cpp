#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void update(vector<ll>&T,ll node, ll start, ll end, ll idx, ll diff) {
	if (idx < start || idx >end) return;
	T[node] += diff;
	if (start != end) {
		update(T,node * 2, start, (start + end) / 2, idx, diff);
		update(T,node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

ll query(vector<ll>& T,ll node, ll start, ll end, ll left, ll right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return T[node];
	return query(T,node * 2, start, (start + end) / 2, left, right) +
		query(T,node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	int T; scanf("%d", &T); 
	while(T--){
		ll N, M; scanf("%lld %lld", &N, &M);
		vector<ll> A(N+M+1, 0);
		vector<ll> T(1 << 20, 0);
		for (int i = 0; i <N; ++i) {
			A[i] = N-i-1;
			update(T, 1, 0, N+M, A[i], 1);
		}
		for(int i=0;i<M;i++){
			ll a;
			scanf("%lld", &a); a--;
			printf("%lld ", query(T, 1, 0, N+M, A[a]+1, N+M));
			update(T, 1, 0, N+M, A[a], -1);
			A[a] = N + i;
			update(T, 1, 0, N+M, A[a], 1);
		}
		printf("\n");
	}
	return 0;
}