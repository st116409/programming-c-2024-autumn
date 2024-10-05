#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int guests = 0;
	int oranges = 0;
	scanf_s("%d %d", &guests, &oranges);
	int gcd = 0;;
	{
		int x = guests;
		int y = oranges;
		while (y > 0 && x > 0)
		{
			if (y > x)
			{
				y %= x;
			}
			else
			{
				x %= y;
			}
		}
		gcd = x + y;
	}
	printf("%d", guests / gcd);
	return EXIT_SUCCESS;
}