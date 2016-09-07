#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 100000000
using namespace std;

int cmp(int length, int partN, vector<int>& les)
{
	int tot = 0;
	int partial = 0;
	int cnt = 1;
	int i;
	for (i = 0; i < les.size();i++) {
		if (partial + les[i] > length)
		{
			if (les[i] > length) return 0;
			partial = les[i];
			cnt++;
		}
		else partial += les[i];
	}
	if (partN >= cnt) return 1; //length로 partN개 가능
	else return 0; //length가 너무 작음
}


int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> lesson(N);
	for (int i = 0; i < N; i++) scanf("%d", &lesson[i]);
	

	int left = 0;
	int right = MAX;
	int mid;
	int min = 1 << 30;

	while (left<=right) {
		mid = (left + right) / 2;
		//조건을 만족할 경우 -> 더 작은 것을 찾아본다.
		int condition = cmp(mid, M,lesson);		
		if(condition==1){
			min = (min < mid) ? min : mid;
			right = mid - 1;
		}
		//블루레이 시간이 너무 짧아서 mid를 넓힌다.
		else
		{
			left = mid + 1;
		}
	}
	printf("%d\n", min);
	
	


	return 0;
}