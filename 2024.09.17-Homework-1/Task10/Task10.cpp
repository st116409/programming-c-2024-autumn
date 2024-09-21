#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int number_of_cranes;

	printf("Enter a total number of cranes:\n");
	scanf_s("%d", &number_of_cranes);
	printf("%d %d %d\n", number_of_cranes / 6, number_of_cranes / 6 * 4, number_of_cranes / 6);

	return EXIT_SUCCESS;
}