#include <stdio.h>

int binary_search(int arr[], int size, int target) {

	int low,mid,high;
	low = 0;
	high = size - 1;

	while (low <= high) {

		mid = low + (high - low) / 2;

		if (arr[mid] == target && arr[mid - 1] == 0) {
			return mid;		
		}
		else if (arr[mid] == target) {
			high = mid - 1;
		}
		else if (arr[mid] == 0) {
			low = mid + 1;
		}

	}

	return -1;

}

int main() {

	int arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int size = sizeof(arr) / sizeof(arr[0]); 
	int index = binary_search(arr, size, 1);

	printf("There are %d ones in the array \n", size - index);

	return 0;

}
