#include <stdio.h>

void swap(int *a, int *b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

void printarr(int arr[], int size) {

	for (int i = 0; i < size; i++) {

		printf("Element %d is %d \n", i, arr[i]);

	}

}

void selectionsort(int arr[], int size) {

	for (int i = 0; i < size - 1; i++) {

		int min_idx = i;
		for (int j = i + 1; j < size; j++) {

			if (arr[j] < arr[min_idx]) {
				
				min_idx = j;
	
			}

		}

		swap(&arr[min_idx],&arr[i]);

	}

}

int main() {

	int arr[] = {12, 67, 10, 41, 21, 17, 70, 68, 128, 15};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("Unsorted Array: \n");
	printarr(arr, size);

	printf("Sorted Array:   \n");
	selectionsort(arr, size);
	printarr(arr, size);
}
