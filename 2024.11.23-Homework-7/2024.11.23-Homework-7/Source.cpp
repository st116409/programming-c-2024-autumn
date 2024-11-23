#include <iostream>
#include <typeinfo>

void printMenu()
{
	
	std::cout << "0 - randomize array" << std::endl;
	std::cout << "1 - print array" << std::endl;
	std::cout << "2 - add to the beginning" << std::endl;
	std::cout << "3 - add to the end" << std::endl;
	std::cout << "4 - delete the first" << std::endl;
	std::cout << "5 - delete the last" << std::endl;
	std::cout << "6 - exit" << std::endl;
}

int* initIntArray(int len) 
{
	int* res = nullptr;
	res = (int*)malloc(sizeof(int) * len);

	for (int i = 0; res != nullptr && i < len; ++i)
	{
		res[i] = 0;
	}
	return res;
}

void randomizeIntArray(int* p, int len)
{
	if (p != nullptr) {
		for (int i = 0; i < len; ++i)
		{
			p[i] = rand() % 20 - 10;
		}
	}
}

void printIntArray(int* p, int len) 
{
	if (p != nullptr) {
		for (int i = 0; i < len; ++i)
		{
			std::cout << p[i] << " ";
		}
		std::cout << std::endl;
	}
}

void expandIntArray1(int** p, int* len)
{
	if (p != nullptr) {
		int* newArray = initIntArray(*len + 1);
		for (int i = 0; i < *len; ++i)
		{
			newArray[i] = (*p)[i];
		}
		free(*p);
		*p = newArray;
		(*len)++;
	}
}
void expandIntArray2(int** p, int* len)
{
	if (p != nullptr) {
		int* newArray = initIntArray(*len + 1);
		for (int i = 0; i < *len; ++i)
		{
			newArray[i + 1] = (*p)[i];
		}
		free(*p);
		*p = newArray;
		(*len)++;
	}
}

void addEnd(int** p, int* len)
{
	expandIntArray1(p, len);
	std::cout << "Enter element:\n";
	int el = 0;
	std::cin >> el;
	(*p)[*len - 1] = el;
}
void addBeg(int** p, int* len)
{
	expandIntArray2(p, len);
	std::cout << "Enter element:\n";
	int el = 0;
	std::cin >> el;
	(*p)[0] = el;
}
void deleteFromEnd(int** p, int* len)
{
	if (p != nullptr) {
		int* newArray = initIntArray(*len - 1);
		for (int i = 0; i < *len - 1; ++i)
		{
			newArray[i] = (*p)[i];
		}
		free(*p);
		*p = newArray;
		(*len)--;
	}
}
void deleteFromBeg(int** p, int* len)
{
	if (p != nullptr) {
		int* newArray = initIntArray(*len - 1);
		for (int i = 0; i < *len - 1; ++i)
		{
			newArray[i] = (*p)[i + 1];
		}
		free(*p);
		*p = newArray;
		(*len)--;
	}
}

int main(int argc, char* argv[])
{
	bool exit = false;

	int len = 0;
	std::cout << "Enter length of array:";
	len = 0;
	std::cin >> len;
	
	system("cls");
	int* res = initIntArray(len);
	
	printMenu();
	
	while (!exit)
	{
		
		int choice = 0;
		std::cin >> choice;
		
		switch (choice)
		{
		case 0:
			system("cls");
			printMenu();
			randomizeIntArray(res, len);
			std::cout << "Successfully filled\n";
			break;
		case 1:
			system("cls");
			printMenu();
			printIntArray(res, len);
			break;
		case 2:
			system("cls");
			printMenu();
			addBeg(&res, &len);
			std::cout << "Element is added\n";
			printIntArray(res, len);
			break;
			
		case 3:
			system("cls");
			printMenu();
			addEnd(&res, &len);
			std::cout << "Element is added\n";
			printIntArray(res, len);
			break;
		case 4:
			system("cls");
			printMenu();
			deleteFromBeg(&res, &len);
			std::cout << "Element is deleted\n";
			printIntArray(res, len);
			break;
		case 5:
			system("cls");
			printMenu();
			deleteFromEnd(&res, &len);
			std::cout << "Element is deleted\n";
			printIntArray(res, len);
			break;

		case 6:
			exit = true;
			std::cout << "Session finished";
			break;
		}
	
	}

	return EXIT_SUCCESS;
}