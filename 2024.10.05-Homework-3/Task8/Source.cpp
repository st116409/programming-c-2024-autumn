#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int i = 0;
	int j = 0;
	scanf_s("%d %d", &i, &j);
	
	int gcd = 0;
	{
		int x = i;
		int y = j;
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
	int f1 = 1;
	int f2 = 1;
	for (int k = 3; k < gcd + 1; ++k)
	{
		f2 += f1;
		int t = f1;
		f1 = f2 % 1000000000;
		f2 = t % 1000000000;
	}
	
	printf("%d", f1);

	return EXIT_SUCCESS;
}