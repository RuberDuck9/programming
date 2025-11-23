#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return(*(int*)a - *(int*)b);
}

int mincost(int arr[], int size) {

	qsort(arr, size, sizeof(int), cmp);
	return ( (size - 1) * arr[0]);

}

int main() {

	int arr[] = {4,3,2};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("The minimum cost is %d\n", mincost(arr,size));
	
	return 0;
}
