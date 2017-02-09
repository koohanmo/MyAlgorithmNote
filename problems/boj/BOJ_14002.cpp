#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> D[1002];
int A[1002];
int main() {
	int N,Ans=0,AnsIdx=0; scanf("%d",&N);
	for (int i = 1; i <= N; i++) scanf("%d",A+i);
	A[0] = -(1 << 30);
	D[0].first = 0;
	D[0].second = 0;
	for (int i = 1; i <= N; i++) for (int j = 0; j < i; j++) if (D[j].first >= D[i].first && A[j] < A[i]) {
		D[i].first = D[j].first + 1;
		D[i].second = j;
		if (Ans < D[i].first) {
			Ans = D[i].first;
			AnsIdx = i;
		}
	}
	printf("%d\n",Ans);
	vector<int> re;
	for (int x = AnsIdx; x != 0; x = D[x].second) re.push_back(A[x]);
	reverse(re.begin(),re.end());
	for (int x : re) printf("%d ",x);
	return 0;
}