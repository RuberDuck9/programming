#include <stdio.h>
#include <stdlib.h>

int* coinsort(int cents) {

	int coinvalues[] = {0,25,10,5,1};
	int* coins = (int*)malloc(4 * sizeof(int));
	int i = i;

	while (cents > 0) {
		
		if (cents > coinvalues[i]) {
			coins[i] += 1;
			cents -= coinvalues[i];
		}	
		else if (cents > 0 && i <= 4 ) {
			i++;
		}	
		else if (cents == 0 ) {
			return coins;
		
		}	
	
	}

}

int main() {

	int cents = 63;	

	int* coins = coinsort(cents);

	for (int i = 0; i < 4; i++) {
		printf("%d \n", coins[i]);
	}

	return 0;

}
