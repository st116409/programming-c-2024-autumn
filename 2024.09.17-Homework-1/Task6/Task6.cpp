#include <stdio.h>
#include <cstdlib>

int main(int argc, char* argv[]) {
	int Harrys_cans;
	int Larrys_cans;

	printf("Enter number of shot cans by Harry and Larry:\n");
	scanf_s("%d %d", &Harrys_cans, &Larrys_cans);
	printf("%d %d", Larrys_cans - 1, Harrys_cans - 1);

	return EXIT_SUCCESS;
}