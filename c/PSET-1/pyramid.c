#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main() {

	int rows = 0;
	int terminal_width = 100;
	int wait_time = 450 - (terminal_width * 4);
	bool flipping = false;


	while (true) {


		for (int i = terminal_width - rows; i > 0; i--) {

			printf(" ");
			usleep(wait_time);
			
		}

		for (int i = 1 + (2 * rows); i > 0; i--) {

			printf("*");
			usleep(wait_time);
		}
		

		for (int i = terminal_width - rows; i > 0; i--) {
		
			printf(" ");
			usleep(wait_time);
		}		

		printf("\n");

		if (flipping == false) {

			rows++;

		}
		else {

			rows--;

		}

		if (rows == terminal_width) {

			flipping = true;

		}
		else if (rows == 0) {

			flipping = false;

		}

	}

}

