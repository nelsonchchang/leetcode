#include <stdbool.h>

bool isPalindrome(int x) {
	int tail;
 	int reverse = 0;
	int reverse_tmp = 0;
	int x_orig = x;

	if (x < 0)
		return false;

	while (x != 0) {
		tail = x % 10;
		reverse = reverse_tmp * 10 + tail;
		if ((reverse / 10) != reverse_tmp)	/*overflow*/
			return false;
		reverse_tmp = reverse;
		x = x / 10;
	}

	if (reverse == x_orig)
		return true;
	else
		return false;
}
