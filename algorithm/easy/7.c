#include <stdlib.h>

int reverse(int x) {
	int digit;
 	int x_orig = x;
 	int result = 0;
	int prev_result = 0;

	if (x < 0)
		x = 0 - x;

	while (x > 0) {
		digit = x % 10;
		prev_result = result;
		result = result * 10 + digit;
		if ((result / 10) != prev_result)	/*overflow*/
			return 0;
		x = x / 10;
	}

	if (x_orig < 0)
		result = 0 - result;

	return result;
}
