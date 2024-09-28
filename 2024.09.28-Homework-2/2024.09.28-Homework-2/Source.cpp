#include<cstdio>
#include<cstdlib>


int main(int argc, char* argv[])
{
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);

	if (x1 == x2 || y1 == y2)
	{
		printf("YES\n");
	}
	else if ((y2 - y1) / (x2 - x1) == 1 || (y2 - y1) / (x2 - x1) == -1)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return EXIT_SUCCESS;
}


