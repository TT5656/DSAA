#include <stdio.h>

void insertionSort(int *nums, int n) {
	if(n == 1)
		return;
	int p;
	for(p = 1; p < n; ++p) {
		int tmp = nums[p];
		int j;
		for(j = p; j > 0 && nums[j - 1] > tmp; --j) 
			nums[j] = nums[j - 1];
		nums[j] = tmp;
	}
}

void printArr(int *arr, int n) {
	int i;
	for(i = 0; i < n; ++i) 
		printf("%d ", arr[i]);
	putchar('\n');
}

int main() {
	int arr[] = {3,1,4,1,5,9,2,6,5};
	int size = sizeof(arr)/sizeof(arr[0]);

	insertionSort(arr, size);
	printArr(arr, size);

	return 0;
}
