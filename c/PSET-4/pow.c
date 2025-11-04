#include <stdio.h>

int power(int num, int n) {

	if (n == 0) {
		return 1;
	}

	else if (n == 1) {
		return num;
	}

	int half = power(num, n/2);
	
	if (n % 2 == 0) {	
		return half * half;
	}

	else if (n % 2 != 0) {
		return num * power(num, n - 1);
	}

}

int main() {

	int num = power(2,16);
	printf("%d \n", num);
	return 0;

}
