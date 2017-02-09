#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
int main() {
	int N,A[30],len; char S[100001];
	stack<double> st;
	scanf("%d %s", &N, S); len = strlen(S);
	for (int i = 0; i < N; i++) scanf("%d ",A+i);
	for (int i = 0; i < len; i++) {
		if (S[i] >= 'A' && S[i] <= 'Z') {
			st.push(A[S[i] - 'A']);
			continue;
		}
		double b = st.top(); st.pop();
		double a = st.top(); st.pop();
		if (S[i]=='+') 	st.push(a + b);
		else if (S[i] == '-') 	st.push(a - b);
		else if (S[i] == '*') 	st.push(a * b);
		else if (S[i] == '/') 	st.push(a / b);
	}
	printf("%.2lf",st.top());
	return 0;
}