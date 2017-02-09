#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int F, S, G, U, D, V[1000001];
int main() {
	memset(V,-1,sizeof(V));
	scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
	V[S] = 0;
	queue<int> Q;
	Q.push(S);
	while (!Q.empty()) {
		int C = Q.front();
		Q.pop();
		if (C == G) continue;
		if (C + U <= F && (V[C + U] == -1 || V[C + U] > V[C] + 1)) {
			Q.push(C + U);
			V[C + U] = V[C] + 1;
		}
		if (C - D >= 1 && (V[C - D] == -1 || V[C - D] > V[C] + 1)) {
			Q.push(C - D);
			V[C - D] = V[C] + 1;
		}
	}
	if(V[G]!=-1)printf("%d\n",V[G]);
	else printf("use the stairs\n");
	return 0;
}