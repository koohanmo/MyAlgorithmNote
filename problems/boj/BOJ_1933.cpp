#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <vector>
#include <tuple>
using namespace std;

int main() {
	int N; scanf("%d",&N);
	vector<tuple<int, int, int>> LHR;
	for (int i = 0; i < N; i++) {
		LHR.push_back(make_tuple(0, 0, 0));
		scanf("%d %d %d", &get<0>(LHR[i]), &get<1>(LHR[i]), &get<2>(LHR[i]));
		printf("%d %d %d\n",get<0>(LHR[i]), get<1>(LHR[i]), get<2>(LHR[i]));
	}
	

	return 0;
}