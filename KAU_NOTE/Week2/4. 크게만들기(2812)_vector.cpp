#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int N, K; scanf("%d %d ", &N, &K);
	char S[500010]; scanf("%s ", S);
	int len = strlen(S);
	vector<char> SV;
	int cntPop = 0;
	for (int i = 0; i < N; ++i) {
		while (!SV.empty() && SV.back() < S[i] && cntPop < K) {
			SV.pop_back();
			++cntPop;
		}
		SV.push_back(S[i]);
	}
	
	for (char c : SV) printf("%c",c);
}