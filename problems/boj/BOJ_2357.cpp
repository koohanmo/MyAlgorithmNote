#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <utility>
#define ll long long
using namespace std;

vector<pair<ll,ll>> T(1 << 18);
vector<ll> A(100010);

ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a > b ? b : a; }

pair<ll, ll> initTree(int node, int start, int end) {
	if (start == end) return T[node] = make_pair(A[start],A[start]);
	auto left = initTree(node * 2, start, (start + end) / 2);
	auto right = initTree(node * 2 + 1, (start + end) / 2 + 1, end);
	return T[node] = make_pair(min(left.first, right.first), max(left.second, right.second));
}

pair<ll, ll> query(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return make_pair((ll)1000000001, 0);
	if (left <= start && end <= right) return T[node];
	auto L = query(node * 2, start, (start + end) / 2, left, right);
	auto R = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return make_pair(min(L.first, R.first), max(L.second, R.second));
}

int main() {
	int N, M; scanf("%d %d",&N,&M);
	for (int i = 0; i < N; i++) scanf("%lld",&A[i]);
	initTree(1, 0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b; scanf("%d %d",&a,&b);
		auto Ans = query(1, 0, N - 1, a-1, b-1);
		printf("%lld %lld\n",Ans.first,Ans.second);
	}
	return 0;
}