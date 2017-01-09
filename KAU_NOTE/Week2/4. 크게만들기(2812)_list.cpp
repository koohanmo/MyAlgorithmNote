#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
int main() {
	int N, K; scanf("%d %d ", &N, &K);
	char S[500010]; scanf("%s ", S);
	int len = strlen(S);
	list<int> L;
	for (int i = 0; i < len; i++) L.push_back(S[i] - '0');
	auto it = L.begin();
	auto nit = L.begin();
	nit++;
	for (int i = 0; i < K; i++) {
		while (nit != L.end() && *it >= *nit) it++, nit++;
		L.erase(it);
		if (nit == L.begin()) {
			it = nit;
			++nit;
		}
		else {
			it = --nit;
			++nit;
		}
	}
	for (auto i : L) printf("%d", i);

}