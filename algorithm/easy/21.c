#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	struct ListNode *next;
};

struct HeadNode {
	struct ListNode *head;
	struct ListNode *tail;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct HeadNode head;
	struct ListNode *node;

	head.head = NULL;
	head.tail = NULL;

	while ((l1 != NULL) && (l2 != NULL)) {
		node = malloc(sizeof(struct ListNode));
		node->next = NULL;
		if (l1->val <= l2->val) {
			node->val = l1->val;
			l1 = l1->next;
		} else {
			node->val = l2->val;
			l2 = l2->next;
		}
		
		if (head.head == NULL)
			head.head = node;
		if (head.tail != NULL)
			head.tail->next = node;
		head.tail = node;
	}

	while (l1 != NULL) {
		node = malloc(sizeof(struct ListNode));
		node->next = NULL;
		node->val = l1->val;
		l1 = l1->next;
		if (head.head == NULL)
			head.head = node;
		if (head.tail != NULL)
			head.tail->next = node;
		head.tail = node;
	}
	
	while (l2 != NULL) {
		node = malloc(sizeof(struct ListNode));
		node->next = NULL;
		node->val = l2->val;
		l2 = l2->next;
		if (head.head == NULL)
			head.head = node;
		if (head.tail != NULL)
			head.tail->next = node;
		head.tail = node;
	}

	return head.head;
}

int main(void)
{
	struct ListNode *l1, *l2;
	struct ListNode *output;

	l1 = NULL;
	l2 = malloc(sizeof(struct ListNode));
	l2->val =0;
	l2->next = NULL;
	output = mergeTwoLists(l1, l2);
	while (output) {
		printf("%d->\n", output->val);
		output = output->next;
	}

	return 0;
}

