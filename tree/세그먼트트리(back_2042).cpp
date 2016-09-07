#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

#define MAXNODE 1000000
#define ll long long

typedef struct Tree {
	ll value, lazy;
}Tree;

ll arr[MAXNODE];
Tree tree[MAXNODE * 4];


ll initTree(int node, int start, int end) {
	if (start == end)
		return tree[node].value = arr[start];
	else
		return tree[node].value = 
		initTree(node * 2, start, (start + end) / 2) + 
		initTree(node * 2 + 1, (start + end) / 2 + 1, end);
}


//left ~right 구간에 value의 변화.
void updateTree(int node, ll value, int start, int end, int left, int right) {
	
	if (tree[node].lazy != 0) {//lazy propagation 할 것이 있다면,
		tree[node].value += (end - start+1)*tree[node].lazy; //자식의 갯수 *기록된 laze;
		if (start != end) //말단 노드가 아니면 전파
		{
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2+1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	//범위 밖
	if (right < start || end < left) return;
	if (left <= start && end <= right) {//범위안에 존재할 경우
		tree[node].value += (end - start+1)*value; 
		if (start != end) //말단 노드가 아니면 전파
		{
			tree[node * 2].lazy += value;
			tree[node * 2 + 1].lazy += value;
		}
		return;
	}

	updateTree(node * 2, value, start, (start + end) / 2, left, right);
	updateTree(node * 2+1, value, (start + end) / 2+1,end, left, right);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}


ll findSum(int node, int start, int end,int left, int right) {

	if (tree[node].lazy != 0) {//lazy propagation 할 것이 있다면,
		tree[node].value += (end - start+1)*tree[node].lazy; //자식의 갯수 *기록된 laze;
		if (start != end) //말단 노드가 아니면 전파
		{
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}

	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node].value;
	return findSum(node*2,start,(start+end)/2,left,right) + findSum(node*2+1,(start+end)/2+1,end,left,right);

}

int main() {

	int N, M, K;//노드수, 변경횟수,구간합횟수
	scanf("%d %d %d", &N,&M, &K);

	for (int i = 1; i <= N; i++) {
		scanf("%lld", &arr[i]);
	}
	initTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {//업데이트
			int node;
			ll value;
			scanf("%d %lld", &node, &value);
			updateTree(1, value -arr[node], 1, N, node, node);
			arr[node] = value;
		}
		else {//합 출력
			int left, right; scanf("%d %d", &left, &right);
			printf("%lld\n", findSum(1,1,N,left,right));
		}
	}

	return 0;
}