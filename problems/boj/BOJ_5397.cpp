#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;
int main() {
	char S[1000001];
	int T; scanf("%d",&T);
	while (T--) {
		stack<char> A, B;
		scanf("%s ",S);
		int len = strlen(S);
		int ansPos = -1;
		for (int i = 0; i < len; ++i) {
			const char cur = S[i];
			if (cur == '<') {
				if (!A.empty()) {
					B.push(A.top());
					A.pop();
				}
			}
			else if (cur == '>') {
				if (!B.empty()) {
					A.push(B.top());
					B.pop();
				}
			}
			else if (cur == '-') {
				if (!A.empty()) {
					A.pop();
				}
			}
			else {
				A.push(cur);
			}
		}
		while (!B.empty()) {
			A.push(B.top());
			B.pop();
		}
		vector<char> Ans;
		while (!A.empty()) {
			Ans.push_back(A.top());
			A.pop();
		}
		for (int i = Ans.size() - 1; i >= 0; --i) printf("%c",Ans[i]);
		printf("\n");
	}
	return 0;
}