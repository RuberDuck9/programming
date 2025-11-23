#include <stdio.h>
#include <stdlib.h>

#define knapsack_size 3

struct Items {
	int val;
	int wt;
	double ratio;
	double count;
};

int cmp(const void* a, const void* b) {
	double r1 = ((struct Items*)a)->ratio;
	double r2 = ((struct Items*)b)->ratio;

	if (r1 < r2) {
		return 1;
	}
	else if (r1 > r2) {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {

	struct Items items[knapsack_size];
	int capacity = 50;

	items[0].val = 60;
	items[0].wt = 10;
	items[0].count = 0.0;

	items[1].val = 100;
	items[1].wt = 20;
	items[1].count = 0.0;

	items[2].val = 120;
	items[2].wt = 30;
	items[2].count = 0.0;

	for (int i = 0; i < knapsack_size; i++) {
		items[i].ratio = (double)items[i].val / items[i].wt;
	}	

	qsort(items, knapsack_size, sizeof(struct Items), cmp);

	int j = 0;

	while (capacity > 0 && j < knapsack_size) {

		if (capacity >= items[j].wt) {
			capacity -= items[j].wt;
			items[j].count += 1;
			j++;
		}
		else if (capacity > 0) {
			double remainder = (double)capacity / items[j].wt;
			items[j].count += remainder;
			capacity = 0;
		}

	}

	for (int i = 0; i < knapsack_size; i++) {
		printf("Value %d, Weight %d, Ratio %f, Count %f\n", items[i].val, items[i].wt, items[i].ratio, items[i].count);
	}

	double total = 0.0;

	for (int i = 0; i < knapsack_size; i++) {
		total += items[i].val * items[i].count;
	}

	printf("So, the total stored quantity is %f\n", total);

	return 0;

}
