#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define D 0
#define S 1
#define L 2
#define R 3
using namespace std;
int main() {
	int T; scanf("%d",&T);
	while (T--) {
		int A, B; scanf("%d %d",&A, &B);
		vector<pair<int,pair<int,int>>> V(10000, make_pair(1<<30,make_pair(-1,-1)));
		queue<int> Q;
		V[A] = make_pair(0, make_pair(-1,-1));
		Q.push(A);
		while (!Q.empty()) {
			int cur = Q.front();
			Q.pop();
			//D
			if (V[cur * 2 % 10000].first > V[cur].first + 1) {
				V[cur * 2 % 10000].first = V[cur].first + 1;
				V[cur * 2 % 10000].second = make_pair(cur,D);
				Q.push(cur * 2 % 10000);
			}
			//S
			int s = cur == 0 ? 9999 : cur - 1;
			if (V[s].first > V[cur].first + 1) {
				V[s].first = V[cur].first + 1;
				V[s].second = make_pair(cur, S);
				Q.push(s);
			}
			//L
			int temp = cur / 1000;
			int l = (cur - temp * 1000)*10+temp;
			if (V[l].first > V[cur].first + 1) {
				V[l].first = V[cur].first + 1;
				V[l].second = make_pair(cur, L);
				Q.push(l);
			}
			//R
			int temp2 = cur % 10;
			int r = (cur / 10) + temp2*1000;
			if (V[r].first > V[cur].first + 1) {
				V[r].first = V[cur].first + 1;
				V[r].second = make_pair(cur, R);
				Q.push(r);
			}
		}
		vector<char> Ans;
		for (int v = B; v != -1; v = V[v].second.first) {
			switch (V[v].second.second) {
				case D: Ans.push_back('D'); break;
				case S: Ans.push_back('S'); break;
				case L: Ans.push_back('L'); break;
				case R: Ans.push_back('R'); break;
			}
		}
		reverse(Ans.begin(), Ans.end());
		for (char ch : Ans) printf("%c",ch);
		printf("\n");
	}
	return 0;
}