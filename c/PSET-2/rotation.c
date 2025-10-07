#include <stdio.h>
#include <string.h>

int* rotate(int arr[], int index, int size) {

	int temp[size + 1];

	for (int i = 0; i < index; i++ ) {

		for (int i = 0; i < size; i++) {

			temp[i + 1] = arr[i];

		}

		temp[0] = arr[size - 1];

		for (int i = 0; i < size; i++) {

			arr[i] = temp[i];

		}

	}

	return arr;

}

int main() {

	int arr[21] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int index;
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("How many times would you like to rotate the array? \n");
	scanf("%d", &index);

	printf("Original Array: \n");

	for (int i = 0; i < size; i++) {

		printf("%d, ", arr[i]);

	}

	printf("\n");

	rotate(arr, index, size);

	printf("Rotated %d Times: \n", index);

	for (int i = 0; i < size; i++) {

		printf("%d, ", arr[i]);
	
	}
	
	printf("\n");

	return 0;

}
