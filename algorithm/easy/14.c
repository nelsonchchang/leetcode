#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	bool find_next = false;
	int index = 0;
	char *output;
	int i;

	if (strsSize <= 0) {
		output = malloc(sizeof(char));
		output[0] = '\0';
		return output;
	}
	
	if (strsSize == 1)
		return strs[0];

	do {
		for (i = 1; i < strsSize; i++) {
			if (strs[0][index] == strs[i][index]) {
				find_next = true;
			} else {
				find_next = false;
				break;
			}
		}

		index++;

	} while (find_next);

	output = malloc(sizeof(char) * index);
	memcpy(output, strs[0], index);
	output[index-1] = '\0';

	return output;
}
