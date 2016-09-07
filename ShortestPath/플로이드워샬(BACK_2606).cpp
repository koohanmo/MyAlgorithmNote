#include<iostream>
#define MIN(a,b) a<b? a:b
#define INF 1<<30
using namespace std;


int main()
{
	int graph[102][102]; for (int i = 0; i < 101; i++) for (int j = 0; j < 101;j++) graph[i][j] = INF;
	int N; cin >> N;
	int T; cin >> T;
	int v1,v2;
	while (T--) {
		cin >> v1 >> v2;
		graph[v1][v2] = 1;
		graph[v2][v1] = 1;
	}

	for (int i = 1; i <= N; i++) graph[i][i] = 1;
	for (int k = 1; k <=N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k]!=INF && graph[k][j]!=INF)
					graph[i][j] =MIN(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}

	int result=0;
	for (int i = 2; i <=N; i++) {		
			if (graph[1][i]!=INF) result++;
	}
	cout << result;

	return 0;
}