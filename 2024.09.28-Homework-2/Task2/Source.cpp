#include<cstdio>
#include<cstdlib>


int main(int argc, char* argv[])
{
	int x = 0;
	int y = 0;

	scanf_s("%d %d", &x, &y);
	
	if (x == 1 && y == 1)
	{
		printf("0");
	}
	else if (x == y)
	{
		printf("2");
	}
	else
	{
		printf("1");
	}

	return EXIT_SUCCESS;
}