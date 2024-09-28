#include<cstdio>
#include<cstdlib>
#include<cmath>

int main(int argc, char* argv[])
{
	int k = 0;
	int w = 0;
	int w1 = 0;
	int c1 = 0;
	int w2 = 0;
	int c2 = 0;
	int w3 = 0;
	int c3 = 0;

	scanf_s("%d %d %d %d %d %d %d %d", &k, &w, &w1, &c1, &w2, &c2, &w3, &c3);

	if (w1 + w2 + w3 <= w && c1 + c2 + c3 >= k)
	{
		printf("YES");
	}
	else if (w1 + w2 <= w && c1 + c2 >= k || w2 + w3 <= w && c2 + c3 >= k || w1 + w3 <= w && c1 + c3 >= k)
	{
		printf("YES");
	}
	else if (w1 <= w && c1 >= k || w2 <= w && c2 >= k || w3 <= w && c3 >= k)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}



	return EXIT_SUCCESS;
}