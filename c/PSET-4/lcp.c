#include <stdio.h>
#include <stdbool.h>

void printarr(char arr[], int size) {

	printf("The LCP is: ");
	for (int i = 0; i < size; i++) {
		printf("%c",arr[i]);
	}
	printf("\n");

}


void lcp(char word1[], char word2[], int size) {

	char lcp[size];
	int i;

	while (true) {

		if (word1[i] == word2[i]) {
			lcp[i] = word1[i];	
			i++;
		}
		else {
			printarr(lcp, i);
			return;
		}

	}

}

int main() {

	char word1[] = {"Technique"};	
	char word2[] = {"Technician"};
	int size = sizeof(word1);
	
	lcp(word1, word2, size);

	return 0;

}
