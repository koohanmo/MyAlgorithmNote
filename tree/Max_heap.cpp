#include <iostream>
using namespace std;

//Max_heap
class Heap {
private:
	int* heap;
	int capacity;
	int currentSize;


	void swap(int* a, int *b) {
		int t = *a;
		*a = *b;
		*b = t;
	}


public :

	//힙 생성자
	Heap(int Capacity)  : capacity(Capacity){
		heap = new int[Capacity];
		currentSize = 0;
	}
	//힙 파괴자
	~Heap() {
		delete[] heap;
	}


	//삽입
	void Insert(int val) {
		//Heap Size Check
		if (currentSize >= capacity) {
			printf("Heap is full!");
			return;
		}
		//마지막에 원소 삽입
		int mPos = currentSize++;
		heap[mPos] = val;
		//부모값보다 내가 크다면 교환 교환 교환
		int parPos = (mPos - 1) / 2;
		while (heap[mPos]>heap[parPos]) {
			swap(&heap[mPos], &heap[parPos]);
			mPos = parPos;
			parPos = (mPos - 1) / 2;
		}
	}
	//삭제, 추출
	int pop() {
		if (currentSize <= 0) {
			printf("Heap is Empty!!!\n");
			return NULL;
		}
		int returnVal = heap[0];
		//1. root와 가장 마지막 노드 교환
		swap(&heap[0],&heap[currentSize-1]);
		//2. 교환된 마지막 노드 삭제
		heap[currentSize - 1] = NULL;
		currentSize--;
		//3. 새로운 root노드 자리 찾아가기.
		int root = 0;
		int leftChild;
		int rightChild;

		while (root<=currentSize-1) {
			leftChild = (root + 1) * 2 - 1;
			rightChild = (root + 1) * 2;

			if (leftChild >= currentSize) {
				//Child 존재 X
				break;
			}
			else if (rightChild >=currentSize) {
				//왼쪽 Child만 존재
				if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else break;
			}
			else {
				//양쪽 Child 존재
				if (heap[leftChild] > heap[root] && heap[rightChild] > heap[root]) {
					if (heap[leftChild]<heap[rightChild]) {
						swap(&heap[rightChild], &heap[root]);
						root = rightChild;
					}
					else {
						swap(&heap[leftChild], &heap[root]);
						root = leftChild;
					}
				}
				else if (heap[leftChild] > heap[root]) {
					swap(&heap[leftChild], &heap[root]);
					root = leftChild;
				}
				else if (heap[rightChild] > heap[root]) {
					swap(&heap[rightChild], &heap[root]);
					root = rightChild;
				}
				else {
					break;
				}
			}

		}
		return returnVal;
		
	}
	int GetTop() {
		if(currentSize>=1)	return heap[0];
		else return -1;
	}

};


int main() {

	Heap heap = Heap(100);
	for (int i = 1; i <= 8; i++) heap.Insert(i);
	for (int i = 1; i <= 8; i++) heap.Insert(8-i+1);
	for (int i = 1; i <= 16; i++) printf("%d ", heap.pop());


	return 0;
}
