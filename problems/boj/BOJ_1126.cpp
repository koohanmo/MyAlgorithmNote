#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
int N,A[52], D[52][500001];
int sol(int cur, int dif){
	if (cur == N) return !dif?0:-(1<<30);
	int& ret = D[cur][dif];
	if (ret != -1) return ret;
	return ret = std::max(std::max(sol(cur + 1, dif + A[cur])+A[cur], sol(cur + 1, abs(dif - A[cur]))+((dif-A[cur])>0?0:A[cur]-dif)),sol(cur+1,dif));
}
int main() {
	memset(D,-1,sizeof(D));
	scanf("%d", &N); for (int i = 0; i < N; i++)scanf("%d",A+i);
	printf("%d\n",sol(0,0) <= 0 ? -1:sol(0,0));
	return 0;
}