#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int vtoi(vector<int>* vt) {
	int n = 0;
	int t = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 2 && j == 2) break;
			n += (vt[i][j] * t);
			t *= 10;
		}
	}
	return n;
}

pair<int,int> itov(int num, vector<int>* vt) { 
	pair<int, int> XY(-1,-1);
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		vt[i].resize(3);
		for (int j = 0; j < 3; j++) {
			if (i == 2 && j == 2) break;
			vt[i][j] = num % 10;
			num /= 10;
			sum += vt[i][j];
			if (vt[i][j] == 0) {
				XY.first = i;
				XY.second = j;
			}
		}
	}
	vt[2][2] = 36 - sum;
	if (XY.first == -1) XY = pair<int, int>(2, 2);
	return XY;
}

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int main() {
	vector<int> st[3];
	for (int i = 0; i < 3; i++) for(int j=0;j<3;j++){
		int temp;
		scanf("%d ", &temp);
		st[i].push_back(temp);
	
	}

	map<int,int> V;
	V.insert(make_pair(vtoi(st), 0));
	queue<pair<int,int>> Q;
	Q.push(make_pair(vtoi(st),0));
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		vector<int> curV[3];
		auto zero = itov(cur.first,curV);

		for (int i = 0; i < 4; i++) {
			int nextY = zero.first + dir[i][0];
			int nextX = zero.second + dir[i][1];
			if (nextY < 0 || nextY >= 3 || nextX < 0 || nextX >= 3) continue;
			swap(curV[zero.first][zero.second], curV[nextY][nextX]);

			auto visit = V.find(vtoi(curV));
			if (visit == V.end() ||  visit->second > cur.second + 1) {
				int check = vtoi(curV);
				Q.push(make_pair(check, cur.second + 1));
				auto curP = V.find(check);
				if(curP==V.end()) V.insert(make_pair(check, cur.second + 1));
				else curP->second = cur.second + 1;
			}
			swap(curV[zero.first][zero.second], curV[nextY][nextX]);
		}
	}
	if (V.find(87654321) == V.end()) printf("-1\n");
	else printf("%d\n",(*V.find(87654321)).second);
	return 0;
}