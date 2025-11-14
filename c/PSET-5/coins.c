#include <stdio.h>
#include <stdlib.h>

int* coinsort(int cents) {

	int coinvalues[] = {25,10,5,1};
	int* coins = (int*)malloc(4 * sizeof(int));

	for (int i = 0; i < 4; i++) {
		coins[i] = 0;
	}

	int j = 0;

	while (cents >= 0) {
		
		if (cents >= coinvalues[j]) {
			coins[j] += 1;
			cents -= coinvalues[j];
		}	
		else if (cents > 0 && j < 4) {
			j++;
		}	
		else if (cents == 0) {
			return coins;
		
		}	
	
	}

}

int main() {

	int cents = 99;	

	int* coins = coinsort(cents);

	printf("%d Quarters\n", coins[0]);
	printf("%d Dimes\n", coins[1]);
	printf("%d Nickels\n", coins[2]);
	printf("%d Pennies\n", coins[3]);

	return 0;

}
