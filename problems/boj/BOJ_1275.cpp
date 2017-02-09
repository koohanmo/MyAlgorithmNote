#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

vector<ll> A(100010,0);
vector<ll> T(1 << 18,0);

void update(ll node, ll start, ll end, ll idx, ll diff) {
	if (idx < start || idx >end) return;
	T[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2+1, (start + end) / 2+1,end, idx, diff);
	}
}

ll query(ll node, ll start, ll end, ll left, ll right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return T[node];
	return query(node * 2, start, (start + end) / 2, left, right)+
		query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main() {
	ll N, M; scanf("%lld %lld",&N,&M);
	for (int i = 0; i < N; i++) {
		scanf("%lld ", &A[i]);
		update(1, 0, N - 1, i, A[i]);
	}
	while (M--) {
		ll a, b, c, d; scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if (a > b) swap(a, b);
		printf("%lld\n",query(1,0,N-1,a-1,b-1));
		update(1, 0, N - 1, c - 1, d - A[c - 1]);
		A[c - 1] = d;
	}
	return 0;
}