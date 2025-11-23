#include <stdio.h>

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

int min_jumps(int arr[], int size) {

	if (size == 0) {
		return -1;
	}
	else if (size == 1) {
		return 0;
	}
	else if (arr[0] == 0) {
		return -1;
	}

	int jumps = 0;
	int end = 0;
	int furthest = 0;

	for (int i = 0; i < size - 1; i++) {
		furthest = max(furthest, i + arr[i]);
		if (furthest <= i) {
			return -1;
		}
		else if (i == end) {
			jumps++;
			end = furthest;
			if (end >= size - 1) {
				break;
			}
		}
	}
	
	return jumps;
	
}

int main() {
	
	int arr[] = {1,3,2,2,1,4,6};
	int size = sizeof(arr)/sizeof(arr[0]);

	printf("The minimum number of jumps to reach the end is %d.\n", min_jumps(arr,size));

	return 0;

}
