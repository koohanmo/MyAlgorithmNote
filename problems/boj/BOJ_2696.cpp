#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int T; scanf("%d ",&T);
	while (T--) {
		priority_queue<int, vector<int>, greater<int>> Rpq;
		priority_queue<int> Lpq;
		vector<int> Ans;
		int N,M; scanf("%d",&N);
		for (int i = 0; i < N; i++) {
			int cur; scanf("%d",&cur);
			if (i%2 ==1) {
				if (cur >= M) {
					Rpq.push(cur);
					Lpq.push(M);
				}
				else {
					Rpq.push(M);
					Lpq.push(cur);
				}
			}
			else {
				if (i == 0) M = cur;
				else {
					if (cur <= Lpq.top()) {
						Lpq.push(cur);
						M = Lpq.top();
						Lpq.pop();
					}
					else {
						Rpq.push(cur);
						M = Rpq.top();
						Rpq.pop();
					}
				}
				Ans.push_back(M);
			}
		}
		printf("%d",Ans.size());
		for (int i = 0; i < Ans.size();++i) {
			if (i % 10 == 0) printf("\n");
			printf("%d ", Ans[i]);
		}
		printf("\n");
	}
}