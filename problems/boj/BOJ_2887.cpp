#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#define ll long long
using namespace std;

vector<pair<ll,int>> X,Y,Z;
vector<pair<int,ll>> adj[100001];

ll min(ll a, ll b) { return a < b ? a: b; }

int main() {
	int N; scanf("%d ",&N);
	for (int i = 0; i < N; i++) {
		ll x, y, z;
		scanf("%lld %lld %lld ", &x,&y,&z);
		X.push_back(make_pair(x, i));
		Y.push_back(make_pair(y, i));
		Z.push_back(make_pair(z, i));
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	sort(Z.begin(), Z.end());

	for (int i = 0; i < X.size() - 1; i++) {
		adj[X[i].second].push_back(make_pair(X[i+1].second, abs(X[i].first - X[i + 1].first)));
		adj[X[i + 1].second].push_back(make_pair(X[i].second, abs(X[i].first - X[i + 1].first)));
		
		adj[Y[i].second].push_back(make_pair(Y[i + 1].second, abs(Y[i].first - Y[i + 1].first)));
		adj[Y[i + 1].second].push_back(make_pair(Y[i].second, abs(Y[i].first - Y[i + 1].first)));

		adj[Z[i].second].push_back(make_pair(Z[i + 1].second, abs(Z[i].first - Z[i + 1].first)));
		adj[Z[i + 1].second].push_back(make_pair(Z[i].second, abs(Z[i].first - Z[i + 1].first)));
	}
	
	ll Ans = 0;
	vector<ll> V(N, -1);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	pq.push(make_pair(0, 0));
	int Cnt = 0;
	while (!pq.empty() && Cnt <= N-1) {
		auto cur = pq.top();
		pq.pop();
		if (V[cur.second] != -1) continue;
		V[cur.second] = cur.first;
		Cnt++;
		Ans += cur.first;
		for (auto next : adj[cur.second]) {
			pq.push(make_pair(next.second,next.first));
		}
	}
	printf("%lld\n",Ans);
}
