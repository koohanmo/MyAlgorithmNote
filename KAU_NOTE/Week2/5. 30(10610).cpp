
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <functional>
#include <algorithm>
using namespace std;
int main() {
	char S[100001];
	scanf("%s ", S);
	int len = strlen(S),result=0;
	sort(S, S + len, greater<char>());
	for (int i = 0; i < len; i++) result += S[i] - '0';
	if (result%3 != 0 || S[len-1]!='0') printf("-1\n");
	else printf("%s\n", S);
}