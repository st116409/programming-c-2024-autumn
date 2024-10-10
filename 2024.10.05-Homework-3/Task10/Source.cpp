#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int n = 0;
	int max = 0;
	int row = 0;

	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int x = 0;
		scanf_s("%d", &x);
		if (x > 0)
		{ 
			++row;
			if (row > max)
			{
				max = row;
			}
		}
		else
		{
			row = 0;
		}
	}
	printf("%d", max);
	return EXIT_SUCCESS;
}