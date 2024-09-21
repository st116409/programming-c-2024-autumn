#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int number;
	
	printf("Enter a 3-digit number:\n");
	scanf_s("%d", &number);

	int ones = number % 10;
	int tens = number / 10 % 10;
	int hundreds = number / 100;
	int summ_of_digits = ones + tens + hundreds;
	
	printf("%d\n", summ_of_digits);

	return EXIT_SUCCESS;
}