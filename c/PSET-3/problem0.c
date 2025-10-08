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

	return -1;

}

int linear_search(int arr[], int size, int target) {

	int iterations = 0;

	for (int i = 0; i < size; i++ ) {

		if (arr[i] == target) {

			printf("Linear Search Finished in %d Iterations \n", iterations);
			return i;

		}

		iterations++;

	}


}

int main() {

	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 73;

	int pos = linear_search(arr, size, target);
	printf("Using linear search %d is at position %d \n", target, pos);

	pos = binary_search(arr, size, target);
	printf("Using binary search %d is at position %d \n", target, pos);
}
