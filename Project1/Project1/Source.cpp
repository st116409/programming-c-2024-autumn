#include <iostream>


int main()
{
	int n = 10;
	int* a = (int*)malloc(sizeof(int) * n);
	std::cout << a[-4];



	return 0;
}