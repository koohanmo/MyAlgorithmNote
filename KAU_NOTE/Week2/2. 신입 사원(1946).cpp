#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {

	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d ", &n);
		int A[100001],temp1,temp2;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &temp1,&temp2);
			A[temp1] = temp2;
		}
		int m = 1 << 30, Ans = 0;
		for (int i = 1; i <=n; i++) {
			if (A[i] < m) {
				Ans++;
				m = A[i];
			}
		}
		printf("%d\n", Ans);
	}
}