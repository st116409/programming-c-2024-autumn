#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int A;
	int B;
	
	printf("Enter two integer numbers:\n");
	scanf_s("%d %d", &A, &B);
	printf("%d\n", A + B);

	return EXIT_SUCCESS;
}