#include <iostream>

int main(int argc, char* argv[])
{
	int array[200] = { 0 };
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(array + i);
	}

	int income = 0;
	int imax = 0;
	int max = *(array);
	for (int k = 0; k < n; ++k) 
	{
		imax = 0;
		max = *(array);
		for (int i = 0; i < n; ++i)
		{
			if (*(array + i) > max)
			{
				max = *(array + i);
				imax = i;
			}
		}
		income += *(array + imax) * (imax + 1);
		for (int i = 0; i < n; ++i)
		{
			*(array + i) = *(array + i + imax + 1);
		}
	}
	std::cout << income;

	return EXIT_SUCCESS;
}