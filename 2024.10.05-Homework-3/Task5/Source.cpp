#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int cities = 0;
	scanf_s("%d", &cities);
	int roads = 0;
	
	for (int i = 0; i < cities; ++i)
	{
		for (int j = 0; j < cities; ++j)
		{
			int x = 0;
			scanf_s("%d", &x);
			roads += x;
		}
	}
	printf("%d", roads / 2);
	
	
	
	return EXIT_SUCCESS;
}