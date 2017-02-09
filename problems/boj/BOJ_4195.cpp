#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <utility>
using namespace std;

map<string, int> M;
int P[100001], S[100001];
int find(int n) {
	if (P[n] == n) return n;
	else return P[n] = find(P[n]);
}

int uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return S[a];
	P[b] = a;
	return S[a] += S[b];
}

int main() {
	int T; scanf("%d",&T);
	while (T--) {
		memset(P, 0, sizeof(P));
		memset(S, 0, sizeof(S));
		M.clear();
		int N; scanf("%d",&N);
		char buf1[21], buf2[21];
		int nodeN = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s%s",buf1,buf2);
			if (M.find(buf1) == M.end()) {
				P[nodeN] = nodeN;
				S[nodeN] = 1;
				M.insert(make_pair(buf1,nodeN));
				nodeN++;
			}
			if (M.find(buf2) == M.end()) {
				P[nodeN] = nodeN;
				S[nodeN] = 1;
				M.insert(make_pair(buf2, nodeN));
				nodeN++;
			}
			printf("%d\n",uni(M.find(buf1)->second, M.find(buf2)->second));
		}
	}
	return 0;
}