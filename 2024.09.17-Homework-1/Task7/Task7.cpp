#include <stdio.h>
#include <cstdlib>

const int MKAD_length = 109;

int main(int argc, char* argv[]) {
	int velocity;
	int time;
	
	printf("Enter a velocity and a time:\n");
	scanf_s("%d %d", &velocity, &time);

	int path = velocity * time;
	int break_kilometer = (1 + path + MKAD_length * (((1 + path) / MKAD_length) * ((1 + path) / MKAD_length) + 1)) % MKAD_length;
	int break_kilimeter_zero_exception = break_kilometer + ((109 - break_kilometer) / 109) * 109;
	
	printf("%d\n", break_kilimeter_zero_exception);

	return EXIT_SUCCESS;
}