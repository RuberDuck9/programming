#include <stdio.h>

void printarr(int arr[], int size) {

	for (int i = 0; i < size; i++) {

		printf("Element %d is %d \n", i, arr[i]);

	}

}

void insertion_sort(int arr[], int size) {

	for(int i = 1; i < size; i ++) {

		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {

			arr[j + 1] = arr[j];
			j = j - 1;

		}

		arr[j + 1] = key;

	}

}

int main() {

	int arr[] = {12, 67, 10, 41, 21, 17, 70, 68, 128, 15};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("Unsorted Array: \n");
	printarr(arr, size);

	printf("Sorted Array:   \n");
	insertion_sort(arr, size);
	printarr(arr, size);
	
}
