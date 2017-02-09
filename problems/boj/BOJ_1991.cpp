#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
char T[1 << 26];
int I[28];
void preorder(int cur) {
	if (cur > (1 << 27) || T[cur] == 0) return;
	printf("%c",T[cur]);
	preorder(cur * 2);
	preorder(cur * 2+1);
}

void inorder(int cur) {
	if (cur > (1 << 27) || T[cur] == 0) return;
	inorder(cur * 2);
	printf("%c", T[cur]);
	inorder(cur * 2 + 1);
}

void postorder(int cur) {
	if (cur > (1 << 27) || T[cur] == 0) return;
	postorder(cur * 2);
	postorder(cur * 2 + 1);
	printf("%c", T[cur]);
}

int main() {
	memset(I,-1,sizeof(I));
	I[0] = 1;
	T[1] = 'A';
	int N; scanf("%d ",&N);
	for (int i = 0; i < N; i++) {
		char a, b, c; scanf(" %c %c %c " ,&a, &b, &c);
		if (b != '.') {
			int idx = I[a - 'A'] * 2;
			T[idx] = b;
			I[b - 'A'] = idx;
		}
		if (c != '.') {
			int idx = I[a - 'A'] * 2+1;
			T[idx] = c;
			I[c - 'A'] = idx;
		}
	}
	preorder(1); puts("");
	inorder(1); puts("");
	postorder(1); puts("");

	return 0;
}