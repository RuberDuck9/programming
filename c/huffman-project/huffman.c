#include <stdio.h>
#include <stdlib.h>

struct node {
	char character;    
	int frequency;    
	struct node *left;
	struct node *right;
};

struct heap {
	int size;	
	int capacity;
	struct node **array; 
};

void print_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}

	printf("\n");
}

struct node *new_node(char character, int frequency) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	(*temp).left = (*temp).right = NULL;
	(*temp).character = character;
	(*temp).frequency = frequency;

	return temp;

}

struct heap *create_minimum_heap(int capacity) {
	struct heap *heap = (struct heap *)malloc(sizeof(struct heap));

	(*heap).size = 0;
	(*heap).capacity = capacity;
	(*heap).array = (struct node **)malloc((*heap).capacity * sizeof(struct node *));
	return heap;

}

void swap_node(struct node **a, struct node **b) {
	struct node *temp = *a;
	*a = *b;
	*b = temp;
}

void organize_minimum_heap(struct heap *heap, int index) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (*heap).size && (*((*heap).array[left])).frequency < (*((*heap).array[smallest])).frequency) {
		smallest = left;
	}

	if (right < (*heap).size && (*((*heap).array[right])).frequency < (*((*heap).array[smallest])).frequency) {
		smallest = right;
	}

	if (smallest != index) {
		swap_node(&(*heap).array[smallest], &(*heap).array[index]);
		organize_minimum_heap(heap, smallest);
	}

}

int is_size_one(struct heap *heap) {
	return ((*heap).size == 1);
}

struct node *extract_min(struct heap *heap) {
	struct node *temp = (*heap).array[0];
	(*heap).array[0] = (*heap).array[(*heap).size - 1];
	(*heap).size --;
	organize_minimum_heap(heap, 0);

	return temp;

}

void insert_minimum_into_heap(struct heap *heap, struct node *node) {
	(*heap).size++;
	int i = (*heap).size - 1;

	while (i && (*node).frequency < heap->array[(i - 1) / 2]->frequency) {
		(*heap).array[i] = (*heap).array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	(*heap).array[i] = node;

}

void build_minimum_heap(struct heap *heap) {
	int n = (*heap).size - 1;
	
	for (int i = (n - 1) / 2; i >= 0; i--) {
		organize_minimum_heap(heap, i);
	}

}

int is_leaf(struct node *root) {
	return !((*root).left) && !((*root).right);
}

struct heap *create_and_build_minimum_heap(char text[], int frequencies[], int size) {
	struct heap *heap = create_minimum_heap(size);

	for (int i = 0; i < size; i++) {
		(*heap).array[i] = new_node(text[i], frequencies[i]);
	}

	(*heap).size = size;
	build_minimum_heap(heap);

	return heap;
}

struct node *build_huffman_tree(char text[], int frequencies[], int size) {
	struct node *top;  
	struct node *left;
	struct node *right;

	struct heap *heap = create_and_build_minimum_heap(text, frequencies, size);

	while (!is_size_one(heap)) {
		left = extract_min(heap);
		right = extract_min(heap);

		top = new_node('@', (*left).frequency + (*right).frequency);

		(*top).left = left;
		(*top).right = right;

		insert_minimum_into_heap(heap, top);

	}

	return extract_min(heap);

}

char *huffman_table[256];

void store_huffman_codes(struct node *root, int arr[], int top) {

	if ((*root).left != NULL) {
		arr[top] = 0;
		store_huffman_codes((*root).left, arr, top + 1);
	}
	if ((*root).right != NULL ) {
		arr[top] = 1;
		store_huffman_codes((*root).right, arr, top + 1);
	}
	if (is_leaf(root)) {
		char *huffman_codes = malloc(top + 1);
		for (int i = 0; i < top; i++) {
			huffman_codes[i] = arr[i] + '0';
		}
		huffman_codes[top] = '\0';
		huffman_table[(unsigned char)(*root).character] = huffman_codes;

		printf("    \"%c\"    | ", (*root).character);
		print_array(arr, top);
	}

}

void store_to_file(char *file_buffer) {
	FILE *file = fopen("output.txt", "w");
	if (file == NULL) { 
		printf("Failed to open file for writing");
		return;
	}

	for (int i = 0; file_buffer[i] != '\0'; i++) {
		unsigned char character = file_buffer[i];
		fprintf(file, "%s", huffman_table[character]);
	}

	fclose(file);
	printf("Encoded output saved to \"output.txt\" \n");

}

void huffman_codes(char text[], int frequencies[], int size) {
	struct node *root = build_huffman_tree(text, frequencies, size);
	int arr [100];
	int top = 0;

	printf(" Character | Huffman Code \n");
	printf("------------------------- \n");
	store_huffman_codes(root, arr, top);
}

int *calculate_frequency(char text[]) {

	int *frequencies = (int*)calloc(256, sizeof(int));

	for (int i = 0; text[i] != '\0'; i++) {
		unsigned char index = (unsigned char)text[i];
		frequencies[index]++;
	}

	return frequencies;

}

int main() {

	FILE *file = fopen("input.txt","r");
	if (file == NULL) {
		printf("Unable to open input.txt");
		return 1;
	}

	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	rewind(file);

	char *file_buffer = malloc(file_size + 1);
	if (file_buffer == NULL) {
		printf("Unable to allocate memory for file buffer");
		fclose(file);
		return 1;
	}

	fread(file_buffer, 1, file_size, file);
	file_buffer[file_size] = '\0';

	int *frequencies = calculate_frequency(file_buffer);
	
	int total_unique_characters = 0;
	for (int i = 0; i < 256; i++) {
		if (frequencies[i] > 0) {
			total_unique_characters++;
		}
	}

	char *unique_characters = malloc(total_unique_characters * sizeof(char));
	int *unique_frequencies = malloc(total_unique_characters * sizeof(int));

	int j = 0;
	for (int i = 0; i < 256; i++) {
		if(frequencies[i] > 0) {
			unique_characters[j] = (char)i;
			unique_frequencies[j] = frequencies[i];
			j++;
		}
	}

	huffman_codes(unique_characters, unique_frequencies, total_unique_characters);
	store_to_file(file_buffer);

	fclose(file);
	free(file_buffer);

	return 0;

}
