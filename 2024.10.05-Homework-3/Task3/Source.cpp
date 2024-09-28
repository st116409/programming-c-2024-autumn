#include<cstdio>
#include<cstdlib>

const int BUS = 437;

int main(int argc, char* argv[])
{
	bool isCrashed = false;
	int k = 0;
	scanf_s("%d", &k);

	for (int i = 0; i < k; i++)
	{
		int x = 0;
		scanf_s("%d", &x);

		if (x <= BUS)
		{
			isCrashed = true;
			printf("Crash %d", i + 1);
			break;
		}
	}
	if (!isCrashed)
	{
		printf("No crash");
	}


	return EXIT_SUCCESS;
}
