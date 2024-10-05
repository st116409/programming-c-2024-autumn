#include<cstdio>
#include <cstdlib>


int main(int argc, char* argv[])
{
	int coins = 0;
	int tails = 0;
	int heads = 0;

	scanf_s("%d", &coins);

	for (int i = 0; i < coins; ++i)
	{
		int x = 0;
		scanf_s("%d", &x);
		if (x == 1)
		{
			++tails;
		}
		else
		{
			++heads;
		}
	}
	if (tails > heads)
	{
		printf("%d",heads);
	}
	else
	{
		printf("%d", tails);
	}
	return EXIT_SUCCESS;
}