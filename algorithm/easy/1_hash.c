/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define HASH_TBL_SIZE	100

struct hash_struct {
	int key;
	int idx;
	int count;
	struct hash_struct *next;
};

struct hash_struct hash_table[HASH_TBL_SIZE];

void hash_init(struct hash_struct hash_table[], int tbl_size)
{
	int i;

	for (i = 0; i < tbl_size; i++) {
		hash_table[i].next = NULL;
		hash_table[i].count = 0;
	}
}

bool hash_insert(int key, int idx)
{
	int index;
	struct hash_struct *hash_node, *hash_node_prev;
	int key_idx = key;

	if (key < 0)
		key_idx = 0 - key;

	index = key_idx % HASH_TBL_SIZE;
	hash_node = hash_table[index].next;
	hash_node_prev = &hash_table[index];

	while (hash_node != NULL){
		hash_node_prev = hash_node;
		hash_node = hash_node->next;
	}
	
	hash_node = malloc(sizeof(struct hash_struct));
	hash_node->next = NULL;
	hash_node->key = key;
	hash_node->idx = idx;
	hash_node_prev->next = hash_node;

	hash_table[index].count++;

	return true;
}

bool hash_delete(int key)
{
	int index;
	struct hash_struct *hash_node, *hash_node_prev;
	bool ret = false;

	index = key % HASH_TBL_SIZE;
	hash_node = hash_table[index].next;
	hash_node_prev = hash_node;

	while (hash_node != NULL) {
		if (hash_node->key == key) {
			hash_node_prev->next = hash_node->next;
			free(hash_node);
			hash_table[index].count--;
			ret = true;
			break;
		} else {
			hash_node_prev = hash_node;
			hash_node = hash_node->next;
		}
	}

	return ret;
}

bool hash_search(int key, int *idx)
{
	int index;
	struct hash_struct *hash_node;
	int key_idx = key;

	if (key < 0)
		key_idx = 0 - key;

	index = key_idx % HASH_TBL_SIZE;

	if (hash_table[index].count == 0)
		return false;

	hash_node = hash_table[index].next;

	while (hash_node != NULL) {
		if (hash_node->key == key) {
			*idx = hash_node->idx;
			return true;
		} else {
			hash_node = hash_node->next;
		}
	}

	return false;
}

int* twoSum(int* nums, int numsSize, int target) {
	int i;
	int complement;
	int idx;
	int *solution = malloc(sizeof(int) * 2);

	hash_init(hash_table, HASH_TBL_SIZE);

	for (i = 0; i < numsSize; i++) {
		complement = target - nums[i];
		if (hash_search(complement, &idx)) {
			solution[0] = idx;
			solution[1] = i;
			return solution;
		} else {
			hash_insert(nums[i], i);
		}
	}

	return 0;
}

int main(void)
{
	int nums[4] = {0, -3, -4, 0};
	int target = -7;
	int *solution;

	solution = twoSum(nums, 4, target);

	printf("solution[0]=%d, solution[1]=%d\n", solution[0], solution[1]);

	return 0;
}
