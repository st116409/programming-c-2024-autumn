#include <stdio.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
	int number;
	
	printf("Enter a number:\n");
	scanf_s("%d", &number);
	printf("The next number for the number %d is %d.\n", number, number + 1);
	printf("The previous number for the number %d is %d.\n", number, number - 1);

	return EXIT_SUCCESS;
}