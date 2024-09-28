#include<cstdio>
#include<cstdlib>


int main(int argc, char* argv[])
{
	int k = 0;
	scanf_s("%d", &k);
	
	int maxage = 0;
	int n = -1;

	for (int i = 0; i < k; i++)
	{
		int age = 0;
		int sex = 0;
		scanf_s("%d %d", &age, &sex);

		if (sex == 1 && age > maxage)
		{
			maxage = age;
			n = i + 1;
		}

	}
	printf("%d", n);



	return EXIT_SUCCESS;
}