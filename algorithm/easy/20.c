#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct par_node {
	char *par_content;
	struct par_node *prev;
	struct par_node *next;
	struct par_node *tail;
};

static void insert_tail_node(struct par_node *head, struct par_node *node) {
	if (head->next != NULL) {
		node->prev = head->tail;
		head->tail->next = node;
	} else {
		node->prev = head;
		head->next = node;
	}
	head->tail = node;
}

static void free_tail_node(struct par_node *head) {
	struct par_node *node;

	node = head->tail;
	head->tail = node->prev;
	head->tail->next = NULL;
	free(node);
}

char revert_par(char input)
{
	if (input == '}')
		return '{';
	else if (input == ']')
		return '[';
	else if (input == ')')
		return '(';
	else
		return '\0';
}

bool isValid(char* s) {
	struct par_node *head;
	struct par_node *node;
	bool ret = false;
	int i = 0;

	head = malloc(sizeof(struct par_node));
	head->next = NULL;
	head->tail = NULL;

	while (s[i] != '\0') {
		if ((s[i] == '{') || (s[i] == '[') || (s[i] == '(')) {
			node = malloc(sizeof(struct par_node));
			node->par_content = &s[i];
			node->next = NULL;
			insert_tail_node(head, node);
		} else {
			if (head->next == NULL) {
				ret = false;
				goto free_nodes;
			}

			if (revert_par(s[i]) == *(head->tail->par_content)) {
				free_tail_node(head);
			} else { 
				ret = false;
				goto free_nodes;
			}
		}
		i++;
	}

	if (head->next == NULL)
		ret = true;
	else
		ret = false;

free_nodes:
	/* free all nodes */
	while (head->next != NULL) {
		node = head->tail;
		head->tail = node->prev;
		node->prev->next = NULL;
		free(node);
	}
	free(head);

	return ret;
}

