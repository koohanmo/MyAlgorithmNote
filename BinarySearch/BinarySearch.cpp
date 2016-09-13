#include <cstdio>

int bSearch(int *arr,int size, int value) {

	int left = 0;
	int right = size - 1;
	int mid;

	while (left<right) {
		mid = (left + right) / 2;
		if (arr[mid] == value) return mid;
		else if (arr[mid] > value) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}


int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%d에 %d가 존재합니다.\n", bSearch(arr,10,3),3);
	printf("%d에 %d가 존재합니다.\n", bSearch(arr, 10, 100), 100);
	return 0;
}