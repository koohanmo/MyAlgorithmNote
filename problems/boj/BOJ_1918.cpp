#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

int priority(char a) {
	if (a == '(' || a == ')') return 0;
	else if (a == '*' || a == '/') return 2;
	else return 1;
}

int main() {
	char J[10001]; scanf("%s", J);
	stack<char> S;
	int len = strlen(J);
	for (int i = 0; i <len ; i++) {
		if (J[i] >= 'A' && J[i] <= 'Z') {
			printf("%c",J[i]);
		}
		else if (J[i]=='*' || J[i]=='/' || J[i] == '+' || J[i] == '-') {
			while (!S.empty() && priority(J[i]) <= priority(S.top())) {
				printf("%c",S.top());
				S.pop();
			}
			S.push(J[i]);
		}
		else if (J[i] == '(') {
			S.push('(');
		}
		else { // ==')'
			char cur = S.top(); S.pop();
			while (cur != '(') {
				printf("%c",cur);
				cur = S.top();
				S.pop();
			}
		}
	}
	while (!S.empty()) {
		printf("%c", S.top());
		S.pop();
	}
	return 0;
}