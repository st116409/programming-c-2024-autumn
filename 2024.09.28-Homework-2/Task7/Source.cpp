#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int pan = 0;
	int t = 0;
	int k = 0;

	scanf_s("%d %d %d", &pan, &t, &k);

	if (k <= pan)
	{
		printf("%d", 2 * t);
	}
	else if (k % pan == 0)
	{
		printf("%d", k / pan * 2 * t);
	}
	else if (2 * (pan + k % pan) <= 3 * pan)
	{
		printf("%d", (k / pan - 1) * 2 * t + 3 * t);
	}
	else
	{
		printf("%d", (k / pan + 1) * 2 * t);
	}

	return EXIT_SUCCESS;
}