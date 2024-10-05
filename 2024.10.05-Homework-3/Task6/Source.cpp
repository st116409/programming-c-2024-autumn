#include<cstdio>
#include<cstdlib>

int main(int argc, char* argv[])
{
	int num1 = 0;
	int num2 = 0;
	scanf_s("%d %d", &num1, &num2);
	
	int prod = num1 * num2;
	
	while (num1 > 0 && num2 > 0)
	{
		if (num1 > num2)
		{
			num1 %= num2;
		}
		else
		{
			num2 %= num1;
		}
	}
	printf("%d", prod / (num1 + num2));

	return EXIT_SUCCESS;
}