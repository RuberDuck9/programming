#include <stdio.h>

int binary_search(int arr[], int size, int target) {

	int low,mid,high;

	for (int i = 0; i < size; i++) {

		int complement = target - arr[i];
		low = 0;
		high = size - 1;

		while (low <= high) {

			mid = low + (high - low) / 2;

			if (arr[mid] == complement) {

				printf("The two numbers that addd up to %d are %d and %d, at positions %d and %d. \n", target, arr[mid], arr[i], mid, i);
				return 0;
			}

			if (arr[mid] > complement) {

				high = mid - 1;

			}

			if (arr[mid] < complement) {

				low = mid + 1;

			}


		}


	}

}

int main() {

	int arr[] = {4,7,8,9,13,14,17,21,22,24,25,28,29,31,33,36,41,42,43,44,46,47,48,49,51,52,54,55,57,59,60,61,63,64,66,71,76,77,79,81,84,85,88,89,90,91,92,97,98,100};
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 72;

	int a = binary_search(arr, size, target);

}
