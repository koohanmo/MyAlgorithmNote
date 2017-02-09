#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
using namespace std;

string Ans;
int D[1001][1001];
int dir[3][2] = { { 0,-1 },{ -1,-1 },{ -1,0 } };

int main() {
	string S1, S2; cin >> S1 >> S2;
	for (int i = 0; i < S1.length(); i++) {
		bool is = false;
		for (int j = 0; j < S2.length(); j++) {
			if (S1[i] == S2[j]) {
				D[i + 1][j + 1] = max(max(D[i][j] + 1, D[i][j + 1]), D[i + 1][j]);
				if (D[i][j] == D[i][j + 1] && D[i][j + 1] == D[i + 1][j] && !is) {
					Ans += (S1[i]);
					is = true;
				}
			}
			else D[i + 1][j + 1] = max(D[i][j + 1], D[i + 1][j]);
		}
	}
	printf("%d\n", D[S1.length()][S2.length()]);
	cout << Ans;
}