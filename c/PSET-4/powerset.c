int power(int num, int n) {

	if (n == 0) {
		return 1;
	}

	else if (n == 1) {
		return num;
	}

	int half = power(num, n/2);
	
	if (n % 2 == 0) {	
		return half * half;
	}

	else if (n % 2 != 0) {
		return num * half * half;
	}

}

void powerset(int arr[], int arr_size) {

	int powerset[power(2, arr_size)];

}

int main() {

	int arr[5] = {1,2,3,4,5};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
        
	powerset(arr, arr_size);	

	return 0;

}
