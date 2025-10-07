#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char word[]) {

	bool palindrome;
	int word_length = strlen(word);
	for (int i = 0; i < word_length; i++) {
		
		if (word[i] == word[word_length - i - 1] ) {

			palindrome = true;

		}

		else {

			palindrome = false;
			break;

		}

	}

	return palindrome;

}

int main() {
	
	printf("Enter your word. \n");
	char word[100];
	scanf("%s", word);

	if (palindrome(word) == true) {

		printf("Palindrome \n");

	}

	else {

		printf("Not Paldindrome \n");

	}



	return 0;

}
