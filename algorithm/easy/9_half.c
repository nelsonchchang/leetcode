#include <stdbool.h>

bool isPalindrome(int x) {
 	int reverse = 0;

	if ((x < 0) || ((x % 10 == 0) && (x != 0)))
		return false;

	while (reverse < x) {
		reverse = reverse * 10 + (x % 10);
		x = x / 10;
	}

	if ((x == reverse) || (x == (reverse/10)))
		return true;
	else
		return false;
}
