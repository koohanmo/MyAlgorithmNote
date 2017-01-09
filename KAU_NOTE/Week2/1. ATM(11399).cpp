#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int A[1001], Ans = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)scanf("%d ", A + i);
	sort(A, A + n);
	for (int i = 0; i < n; ++i) Ans += (A[i] * (n - i));
	printf("%d\n", Ans);
	return 0;
}