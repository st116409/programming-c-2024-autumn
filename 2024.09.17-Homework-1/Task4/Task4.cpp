#include <stdio.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
	int number_of_tiles;
	int pile_length;
	int pile_width;
	
	printf("Enter number, length and width of piles:\n");
	scanf_s("%d %d %d", &number_of_tiles, &pile_length, &pile_width);
	
	int total_surface_area = number_of_tiles * pile_length * pile_width * 2;
	
	printf("%d", total_surface_area);

	return EXIT_SUCCESS;
}