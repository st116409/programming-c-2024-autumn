#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int number;
	
	printf("Enter your number :\n");
	scanf_s("%d", &number);
	printf("%d", number);

	return EXIT_SUCCESS;
}