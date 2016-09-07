#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
using namespace std;

int board[101][101] = { 0, };
int num[101] = { 0, };
int lastpush[101] = { 0, };

bool cmp(pair<int, int> p1, pair<int,int> p2)
{
	if (p1.first == p2.first)
	{
		//Á¦Ãâ È½¼ö°¡ °°´Ù¸é
		if (num[p1.second] == num[p2.second])return lastpush[p1.second] < lastpush[p2.second];
		else  return num[p1.second] < num[p2.second];
	}
	else return p1.first > p2.first;
}


int main()
{
	int T; scanf("%d", &T);
	while (T--) {
		
		memset(board,0,sizeof(board));
		memset(num, 0, sizeof(num));
		memset(lastpush, 0, sizeof(lastpush));

		int n, k, id, m;
		scanf("%d %d %d %d",&n, &k, &id, &m);
		
		int t1, t2, t3;
		for (int i = 0; i < m; i++)
		{
			//ÆÀid, ¹®Á¦¹øÈ£, È¹µæÁ¡¼ö
			scanf("%d %d %d", &t1, &t2, &t3);
			if(board[t1][t2]<t3) board[t1][t2] = t3;
			num[t1]++;
			lastpush[t1] = i;
		}

		vector<pair<int, int>> tot(n + 1);
		//ÃÑÇÕ °è»ê
		for (int i = 1; i <= n; i++)
		{
			int t=0;
			for (int j = 1; j <= k; j++)
			{
				t += board[i][j];
			}
			tot.push_back(make_pair(t, i));
		}

		sort(tot.begin(),tot.end(),cmp);
		
		int size = tot.size();
		for (int i = 0; i < size; i++)
		{
			if (tot[i].second == id)
			{
				cout << i + 1 << endl;
				break;
			}
		}

	}
	return 0;
}