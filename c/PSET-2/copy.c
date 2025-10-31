#include <stdio.h>
#include <string.h>

char* str_copy(char src[], char dest[]) {

	for (int i = 0; i < strlen(src); i++) {

		dest[i] = src[i];

	}

	return dest;

}

int main() {

	char src[] = {"Hello"};
	char dest[strlen(src)];

	str_copy(src, dest);

	printf("%s \n", src);
	printf("%s \n", dest);

	return 0;

}
