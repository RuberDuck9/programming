#include <stdio.h>
#include <stdlib.h>

void min_subset(int arr[], int size) {

	int positives = 0;
	int negatives = 0;
	int zeros = 0;

	int smallest_positive = 0;
	int smallest_positive_pos;
	int largest_positive = 0;
	int largest_positive_pos;
	int smallest_negative = 0;
	int smallest_negative_pos;
	int largest_negative = 0;
	int largest_negative_pos;

	for (int i = 0; i < size; i++) {
	
		if (arr[i] > 0) {
			positives++;
			if (smallest_positive == 0 || arr[i] < smallest_positive) {
				smallest_positive = arr[i];
				smallest_positive_pos = i;
			}
			if (largest_positive == 0 || arr[i] > largest_positive) {
				largest_positive = arr[i];
				largest_positive_pos = i;
			}
		}
		
		else if (arr[i] == 0) {
			zeros++;
		}
		
		else if (arr[i] < 0) {
			negatives++;
			if (smallest_negative == 0 || abs(arr[i]) < smallest_negative) {
				smallest_negative = arr[i];
				smallest_negative_pos = i;
			}
			if (largest_negative == 0 || abs(arr[i]) > largest_negative) {
				largest_negative = arr[i];
				largest_negative_pos = i;
			}
		}
	}

	printf("For the array [");
	for (int i = 0; i < size; i++) {
		if (i + 1 >= size) {
			printf("%d", arr[i]);
		}
		else {
			printf("%d, ", arr[i]);
		}
	}
	printf("], ");	

	if (size == 1) {
		printf("the most optimal subset is [%d]\n", arr[0]);
	}
	else if (zeros > 0 && negatives == 0) {
		printf("the most optimal subset is [%d]\n", 0);
	}
	else if (negatives == 0 && zeros == 0 && positives > 0) {
		printf("the most optimal subset is [%d]\n", smallest_positive);
	}
	else if (positives == 0 && zeros == 0 && negatives > 0 && negatives % 2 == 1) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (i + 1 >= size) {
				printf("%d", arr[i]);
			}
			else {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
	else if (positives == 0 && zeros == 0 && negatives > 0 && negatives % 2 == 0) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (i == smallest_negative_pos) {
				continue;
			}
			else if (i + 1 >= size || i + 1 == smallest_negative_pos) {
				printf("%d", arr[i]);
			}
			else if (i + 1 != smallest_negative_pos) {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
	else if (positives > 0 && zeros == 0 && negatives > 0 && negatives % 2 == 1) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (i + 1 >= size) {
				printf("%d", arr[i]);
			}
			else {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
	else if (positives > 0 && zeros == 0 && negatives > 0 && negatives % 2 == 0) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (i == largest_negative_pos) {
				continue;
			}
			else if (i + 1 >= size || i + 1 == smallest_negative_pos) {
				printf("%d", arr[i]);
			}
			else if (i + 1 != smallest_negative_pos) {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
	else if (zeros > 0 && positives > 0 && negatives % 2 == 0) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (arr[i] == 0) {
				continue;
			}
			else if (i == smallest_negative_pos) {
				continue;
			}
			else if (i + 1 >= size || i + 1 == smallest_negative_pos) {
				printf("%d", arr[i]);
			}
			else if (i + 1 != smallest_negative_pos) {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
	else if (zeros > 0 && positives > 0 && negatives % 2 == 1) {
		printf("the most optimal subset is [");
		for (int i = 0; i < size; i++) {
			if (arr[i] == 0) {
				continue;
			}
			else if (i + 1 >= size) {
				printf("%d", arr[i]);
			}
			else {
				printf("%d, ", arr[i]);
			}
		}
		printf("]\n");
	}
}

int main() {

	int arr0[] = {3,4,2};
	int arr1[] = {-1,-2,-3,-4};
	int arr2[] = {0,-1,2,-3,4};
	int arr3[] = {1,-1,-2,-3};
	int arr4[] = {0,5,10};
	int arr5[] = {-1};
	int arr6[] = {0,2,-3,4};

	min_subset(arr0, sizeof(arr0)/sizeof(arr0[0]));
	min_subset(arr1, sizeof(arr1)/sizeof(arr1[0]));
	min_subset(arr2, sizeof(arr2)/sizeof(arr2[0]));
	min_subset(arr3, sizeof(arr3)/sizeof(arr3[0]));
	min_subset(arr4, sizeof(arr4)/sizeof(arr4[0]));
	min_subset(arr5, sizeof(arr5)/sizeof(arr5[0]));
	min_subset(arr6, sizeof(arr6)/sizeof(arr6[0]));

}
