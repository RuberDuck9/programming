#include <stdio.h>

int binary_search(int arr[], int size) {

	int low,mid,high;
	high = 0;
	low = 0;
	high = size - 1;

	while (low <= high) {

		mid = low + (high - low) / 2;

		if (mid < high && arr[mid] > arr[mid + 1]) {

			return mid;

		}

		if (mid < high && arr[mid] < arr[mid - 1]) {

			return mid - 1;

		}

		if (arr[mid] >= arr[low]) {
		
			low = mid + 1;

		}

		else {

			high = mid - 1;

		}

	}

	return -1;

}

int main() {

	int arr[] = {180, 181, 184, 185, 187, 188, 190, 192, 194, 196, 197, 199, 206, 208, 213, 214, 216, 217, 219, 223, 224, 225, 226, 227, 228, 230, 231, 232, 237, 239, 240, 244, 245, 246, 247, 250, 67, 69, 70, 72, 75, 78, 80, 84, 85, 86, 87, 91, 92, 93, 94, 97, 99, 100, 104, 105, 112, 115, 116, 118, 119, 120, 121, 123, 124, 125, 126, 127, 128, 129, 131, 132, 134, 135, 139, 141, 144, 145, 146, 149, 150, 152, 155, 157, 158, 159, 162, 163, 164, 165, 167, 170, 171, 172, 173, 174, 176, 177, 178, 179};
	int size = sizeof(arr) / sizeof(arr[0]);

	int high = binary_search(arr, size);
	printf("The largest number in the array is %d. \n", arr[high]);
	printf("The second largest number in the array is %d. \n", arr[high - 1]);

}
