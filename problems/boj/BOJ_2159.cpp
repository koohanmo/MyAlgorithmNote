#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <cstring>
#include <algorithm>
#define ll long long
#define pii pair<ll,ll> 
using namespace std;
ll N,curY,curX;
pii T[100002];
ll dir[5][2] = { {0,0}, {0,1},{0,-1},{1,0},{-1,0} };
ll D[100001][5];
inline ll dis(pii a, pii b) { return abs(a.first - b.first) + abs(a.second - b.second); }
int main() {
	
	scanf("%lld", &N);
	for (int i = 0; i <= N; i++) {
		scanf("%lld %lld", &T[i].first, &T[i].second);
		for (int j = 0; j < 5; j++) D[i][j] = 1e10;
	}
	D[0][0] = 0;
	for (int i = 0; i < 4; i++) D[0][i + 1] = 1;
	for (int i = 1; i <= N; i++) for (int j = 0; j<5; j++) for(int k=0;k<5;k++){
		pii pre = T[i-1];
		pre.first += dir[j][0];
		pre.second += dir[j][1];
		pii now = T[i];
		now.first += dir[k][0];
		now.second += dir[k][1];
		D[i][k] = min(D[i][k], D[i-1][j]+dis(pre, now));
	}
	ll Ans = 1e10;
	for (int i = 0; i < 5; i++)  Ans = min(Ans, D[N][i]);
	printf("%lld\n",Ans);
	return 0;
}