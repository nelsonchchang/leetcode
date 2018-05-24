#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
	int i;
	int ret = 1;
	int current_num = nums[0];
	int prev_pointer = 1, cur_pointer = 1;

	if (numsSize == 0)
		return numsSize;

	for (i = 1; i < numsSize; i++) {
		if (nums[cur_pointer] != current_num) {
			if (cur_pointer != prev_pointer) {
				nums[prev_pointer] = nums[cur_pointer];
			}
			current_num = nums[prev_pointer];
			prev_pointer++;
			ret++;
		}
		cur_pointer++;
	}

	return ret;
}

int main(void)
{
	int nums[10] = {0,0,1,1,2,2,2,3,4,5};
	int numSize = sizeof(nums) / sizeof(int);
	int ret = removeDuplicates(nums, numSize);
	int i;

#if 0
	printf("numSize=%d:\n", numSize);
	for (i = 0; i < numSize; i++)
		printf("%d,", nums[i]);
	printf("\n");
#endif

	printf("array[%d]:\n", ret);
	for (i = 0; i < ret; i++)
		printf("%d,", nums[i]);
	printf("\n");

	return 0;
}
