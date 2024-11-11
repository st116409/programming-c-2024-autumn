#include <iostream>
int main(int argc, char* argv[])
{
	int array[100] = { 0 };
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(array + i);
	}

	int odd[100] = { 0 };
	int oCount = 0;
	int even[100] = { 0 };
	int eCount = 0;

	for (int i = 0; i < n; ++i)
	{
		if (*(array + i) % 2 == 1)
		{
			*(odd + oCount) = *(array + i);
			++oCount;
		}
		else {
			*(even + eCount) = *(array + i);
			++eCount;
		}
	}
	
	for (int i = 0; i < oCount; ++i)
	{
		std::cout << *(odd + i) << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < eCount; ++i)
	{
		std::cout << *(even + i) << " ";
	}
	std::cout << std::endl;
	if (oCount <= eCount) std::cout << "YES";
	else std::cout << "NO";
	
	return EXIT_SUCCESS;
}