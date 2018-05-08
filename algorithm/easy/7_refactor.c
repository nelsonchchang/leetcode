#include <stdlib.h>

int reverse(int x) {
	int digit;
 	int result = 0;
	int prev_result = 0;

	while (x != 0) {
		digit = x % 10;
		prev_result = result;
		result = result * 10 + digit;
		if (((result - digit) / 10) != prev_result)	/*overflow*/
			return 0;
		x = x / 10;
	}

	return result;
}
