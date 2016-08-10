#include <stdio.h>
#include <stdlib.h>

#define CUTOFF 3

void swap(int *n1, int *n2) {
	int tmp;
	tmp = *n1;
	*n1 = *n2;
	*n2 =tmp;
}

void insertSort(int *nums, int left, int right) {
	int size = right - left + 1;
	if(size > 1) {
		int p;
		for(p = 1; p < size; ++p) {
			int tmp = nums[left + p];
			int j;
			for(j = p; j > 0 && nums[left + j - 1] > tmp; --j) {
				nums[left + j] = nums[left + j - 1];
			}
			nums[left + j] = tmp;
		}
	}
}

void medianOf3(int *nums, int left, int right) {
	int mid = (left + right) / 2;
	if(nums[left] > nums[mid])
		swap(&nums[left], &nums[mid]);
	if(nums[left] > nums[right])
		swap(&nums[left], &nums[right]);
	if(nums[mid] > nums[right])
		swap(&nums[mid], &nums[right]);
	swap(&nums[right - 1], &nums[mid]);
}

void qSort(int *nums, int left, int right) {
	if(right - left + 1 <= CUTOFF)
		insertSort(nums, left, right);
	else {
		medianOf3(nums, left, right);
		int i, j;
		i = left;
		j = right - 1;
		while(1) {
			while(nums[++i] < nums[right - 1]);
			while(nums[--j] > nums[right - 1]);
			if(i < j)
				swap(&nums[i], &nums[j]);
			else 
				break;
		}
		swap(&nums[i], &nums[right - 1]);
		qSort(nums, left, i - 1);
		qSort(nums, i + 1, right);
	}
}

void quickSort(int *nums, int size) {
	qSort(nums, 0, size - 1);
}

void printArr(int *nums, int size) {
	int i;
	for(i = 0; i < size; ++i) {
		printf("%d ", nums[i]);
	}
	putchar('\n');
}

int main() {
	int nums[] = {3,1,4,1,5,9,2,6,5,3,5};
	int numsSize = sizeof(nums)/sizeof(nums[0]);

	quickSort(nums, numsSize);
	printArr(nums, numsSize);

	return 0;
}
