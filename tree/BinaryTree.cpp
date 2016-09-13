#include <cstdio>
#define TREESIZE 100

class tree {

	private: int arr[TREESIZE];
			 int size = 1;

	public: 
		tree() {
			for (int i = 0; i < TREESIZE; i++) {
				arr[i] = 0;
			}
		}
		void insert(int n) {
			if (size < TREESIZE) {
				arr[size++] = n;
			}
			else {
				printf("Tree is full!");
			}
		}
		void preorder(int root) {
			if (root <= 0 || root >= size) return;
			printf("%d ",arr[root]);
			preorder(root * 2);
			preorder(root * 2+1);
		}
		
};



int main() {

	tree sampleTree = tree();
	for (int i = 1; i <= 7; i++) sampleTree.insert(i);
	sampleTree.preorder(1);


	return 0;
}