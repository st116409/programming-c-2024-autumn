#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int number_of_colors;
	
	printf("Enter a number of beads' colors:\n");
	scanf_s("%d", &number_of_colors);
	printf("%d", number_of_colors + 1);

	return EXIT_SUCCESS;
}