#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int *tmpArr, int leftPos, int leftEnd, int rightEnd) {
	int rightPos = leftEnd + 1;
	int tmpIndex = 0;
	int tmpLeftPos = leftPos;
	while(leftPos <= leftEnd && rightPos <= rightEnd) {
		if(arr[leftPos] <= arr[rightPos]) 
			tmpArr[tmpIndex++] = arr[leftPos++];
		else 
			tmpArr[tmpIndex++] = arr[rightPos++];
	}
	while(leftPos <= leftEnd)
		tmpArr[tmpIndex++] = arr[leftPos++];
	while(rightPos <= rightEnd)
		tmpArr[tmpIndex++] = arr[rightPos++];
	int i;
	for(i = 0; i < tmpIndex; ++i) {
		arr[tmpLeftPos + i] = tmpArr[i];
	}
}

void mergeSortRe(int *arr, int *tmpArr, int left, int right) {
	if(left == right)
		return;
	int mid = (left + right) / 2;
	mergeSortRe(arr, tmpArr, left, mid);
	mergeSortRe(arr, tmpArr, mid + 1, right);
	merge(arr, tmpArr, left, mid, right);
}

void mergeSort(int *arr, int n) {
	int *tmpArr = (int *)malloc(sizeof(int) * n);

	if(n < 2)
		return;

	mergeSortRe(arr, tmpArr, 0, n - 1); 
	free(tmpArr);
}

void printArr(int *nums, int size) {
	int i;
	for(i = 0; i < size; ++i) {
		printf("%d ", nums[i]);
	}
	putchar('\n');
}

int main() {
	int nums[] = {3,1,4,1,5,9,2,6};
	int size = sizeof(nums)/sizeof(nums[0]);

	mergeSort(nums, size);
	printArr(nums, size);

	return 0;
}
