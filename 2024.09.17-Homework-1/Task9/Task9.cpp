#include <stdio.h>
#include <cstdlib>


int main(int argc, char* argv[]) {
	int bar_height;
	int step_up;
	int step_down;

	printf("Enter height of bar, day lifting and night rollback:\n");
	scanf_s("%d %d %d", &bar_height, &step_up, &step_down);

	int days = (bar_height - step_up) / (step_up - step_down) + ((bar_height - step_up) % (step_up - step_down) + step_up) / (step_up + 1) + 1;

	printf("%d", days);

	return EXIT_SUCCESS;
}