#include <stdio.h>

int binary_search(int arr[], int size, int target) {

	int low,mid,high;
	low = 0;
	high = size - 1;

	int iterations = 0;

	while (low <= high) {

		mid = low + (high - low) / 2;

		if (arr[mid] == target) {

			printf("Binary Search Finished in %d Iterations \n", iterations);
			return mid;		

		}

		if (arr[mid] > target) {

			high = mid - 1;
			iterations++;

		}

		if (arr[mid] < target) {

			low = mid + 1;
			iterations++;

		}


	}

	printf("Binary search failed after %d Iterations. Expected position is %d. \n", iterations, high + 1);

	return -1;

}
int main() {

	int arr[] = {100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,131,132,133,134,135,136,138,139,140,141,142,143,144,145,146,147,148,149,150};
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 137;

	int pos = binary_search(arr, size, target);

	if (pos == -1) {

	}

	else {

		printf("Using binary search %d is at position %d \n", target, pos);

	}
}
