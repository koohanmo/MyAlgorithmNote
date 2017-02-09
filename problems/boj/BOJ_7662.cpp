#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <cstdio>
using namespace std;

int main() {
	int T; scanf("%d",&T);
	while (T--) {
		multiset<int> ms;
		int K; scanf("%d",&K);
		for (int i = 0; i < K; i++) {
			char c; int v;
			scanf(" %c %d ", &c, &v);
			if (c == 'I') ms.insert(v);
			else if (!ms.empty()) v == -1 ? ms.erase(ms.begin()) : ms.erase(--ms.end());
		}
		ms.empty() ? puts("EMPTY") : printf("%d %d\n", *ms.rbegin(), *ms.begin());
	}
}