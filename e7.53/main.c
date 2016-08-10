#include <stdio.h>
#include <stdlib.h>

int cmp(const void *n1, const void *n2) {
	return *(int*)n1 - *(int*)n2;
}

int main() {
	int nums[] = {4,3,2,5,6,8,9,7};
	int size = sizeof(nums)/sizeof(nums[0]);
	int sum = 10;

	qsort(nums, size, sizeof(int), cmp);

	int i, j;
	i = 0;
	j = size - 1;
	while(i < j) {
		if(nums[i] + nums[j] < sum)
			++i;
		else if(nums[i] + nums[j] > sum)
			--j;
		else 
			printf("[%d,%d]\n", nums[i++], nums[j--]);
	}
}
