#include <stdio.h>

int factorial(int n) {

	if (n == 0) {
	
		return 1;

	}

	return n * factorial(n - 1);

}

void merge(int arr[], int left, int mid, int right) {

	int i,j,k; //used to merge the arrays at the end

	int leftSize = mid - left + 1; //left subarray size
	int rightSize = right - mid; //right subarray size

	int l[leftSize], r[rightSize]; //temporary arrays

	//project the left hand size of arr to l and the right hand side of arr to r
	for(i = 0; i < leftSize; i++) {
	
		l[leftSize] = arr[l + i];

	}

	for(i = 0; i < leftSize; i++) {
		
		r[rightSize] = arr[mid + 1 + j]; //we use this index because we are starting from 1 after the midpint

	}

	//merge the temporary arrays back into arr
	// if {3,6,4,9,1} and r {2,5,8} its always going to plug in the smaller value of the two comparisons
	i,j = 0;
	k = left; //this is counting the actual array

	while (i < leftSize && j < rightSize) {
	
		//comparison step
		if(l[i] <= r[j] {

			arr[k] = l[i];
			i++;

		}

		else if(l[i] <= r[j] {

			arr[k] = r[j];
			j++;

		}

	}

	//if we have anything left in l and r, just dump them back in
	while (i < leftSize) {

		arr[k] = l[i];
		i,k++;

	}

	while (i < rightSize) {

		arr[k] = r[i];
		i,k++;

	}

}

void mergesort(int arr[], int left, int right) {

	if (left < right) { // base case, check to make sure the array is not size 1

		int mid = left + (right - left) / 2;
		merge_sort(arr,left,mid);
		merge_sort(arr,mid + 1,right);
		merge(arr,left,mid,right);
	}

}


int main() {

	return 0;

}
