#include <stdio.h>
#include <stdlib.h>

#define knapsack_size 3

struct Items {
	int val;
	int wt;
	double ratio;
	int count;
};

int cmp(const void* a, const void* b) {
	return (((struct Items*)a)->ratio - ((struct Items*)b)->ratio);
}

int main() {

	struct Items items[knapsack_size];
	int capacity = 55;

	items[0].val = 60;
	items[0].wt = 10;
	items[0].count = 0;

	items[1].val = 100;
	items[1].wt = 20;
	items[1].count = 0;

	items[2].val = 120;
	items[2].wt = 30;
	items[2].count = 0;

	for (int i = 0; i < knapsack_size; i++) {
		items[i].ratio = items[i].val / items[i].wt;
	}	

	qsort(items, knapsack_size, sizeof(struct Items), cmp);

	int j = 0;

	while (capacity >= 0) {

		printf("Capacity %d \n", capacity);

		if (capacity >= items[j].wt) {
			items[j].count += 1;
			capacity -= items[j].wt;
		}
		else if (capacity > 0 && j < knapsack_size) {
			j++;
			double remainder = capacity / items[j].wt;
			items[j].count += 1 * remainder;
			capacity -= items[j].wt * remainder;
		}
		else if (capacity == 0) {
			break;
		}

	}

	for (int i = 0; i < knapsack_size; i++) {
		printf("Value %d, Weight %d, Ratio %f, Count %d \n", items[i].val, items[i].wt, items[i].ratio, items[i].count);
	}
	return 0;

}
