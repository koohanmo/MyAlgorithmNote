#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main() {
	int N, K; scanf("%d %d",&N,&K);
	queue<int> Q[21];
	char temp[22];
	int len;
	long long Ans = 0;
	for (int i = 0; i < N; i++) {
		scanf("%s ",temp);
		len = strlen(temp);

		while (!Q[len].empty() && i-Q[len].front()>K) {
			Q[len].pop();
		}
		Ans += Q[len].size();
		Q[len].push(i);
	}
	printf("%lld\n",Ans);
}