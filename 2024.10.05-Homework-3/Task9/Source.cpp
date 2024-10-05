#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	scanf_s("%d %d %d %d", &a, &b, &c, &d);

	
	for (int x1 = -100; x1 < 101; ++x1)
	{
		for (int x2 = x1; x2 < 101; ++x2)
		{
			for (int x3 = x2; x3 < 101; ++x3)
			{
				if (a * (x1 + x2 + x3) == -b && a * (x1 * x2 + x1 * x3 + x2 * x3) == c && a * x1 * x2 * x3 == -d)
				{
					printf("%d", x1);
					if (x1 != x2)
					{
						printf(" %d", x2);
						if (x1 != x3 && x2 != x3)
						{
							printf(" %d", x3);
						}
						
					}
					else if (x1 != x3)
					{
						printf(" %d", x3);
					}
					return EXIT_SUCCESS;
				}
			}
		}
	}
	return EXIT_SUCCESS;
}