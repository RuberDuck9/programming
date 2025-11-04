#include <stdio.h>

void printarr(int arr[], int size) {

	printf("[ ");
	for (int i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
	printf("]\n");

}

void powerset(int arr[], int size, int index, int subset[], int subsetelements) {

	if (index == size) {
		printarr(subset, subsetelements);
		return;
	}

	//create two recursive iterations: one with the current element, and one without it
	
	//without
	powerset(arr, size, index + 1, subset, subsetelements);

	//with
	subset[subsetelements] = arr[index];
	powerset(arr, size, index + 1, subset, subsetelements + 1);


}

int main() {

	int arr[5] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int subset[size];
        
	powerset(arr, size, 0, subset, 0);	

	return 0;

}
