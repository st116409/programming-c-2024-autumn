#include <iostream>
#include "Student.h"
#include <vector>

int power(int a, int n) {
	int res = 1;
	for (int i = 0; i < n; ++i) {
		res *= a;
	}
	return res;
}



std::vector<Student> stgenerate(int n, int hpw, int dmgw, int luckw) {
	std::vector<Student> list(128);

	for (int i = 0; i < 128; ++i) {
		int x[4] = {0,0,0,0};
		for (int i = 0; i < 3; ++i) {
			int sum = 0;
			for (int j = 0; j < i; j++) {
				sum += x[j];
			}
			int maxpoints = 10;
			x[i] = rand() % (maxpoints + 1 - sum);
			if (i == 2) {
				
				x[3] = maxpoints - sum - x[2];
			}
		}

		list[i] = Student(hpw * x[0], 1 + dmgw * x[1], x[2], luckw * x[3], (x[0] > x[1] + 3));
		//list[i] = Student(hpw * 1, dmgw * 2, 3*x[1], luckw * 5, true);

	}
	return list;
}


Student championship(std::vector<Student> list) {
	const int N = 128;
	const int rounds = 7;

	for (int i = 0; i < rounds; ++i) {
		int k = power(2, i);
		for (int j = 0; j < N - k; ++j) {
			
			list[j] = battle(list[j], list[j + k]);
			j+=k;
		}
	}
	
	return list[0];
};


int main(int argc, char* argv[]) {
	srand(time(0));
	std::vector<Student> list = stgenerate(128, 12, 6, 7);
	for (int i = 0; i < 10; i++) {
		list = stgenerate(128, 9, 6, 7);
		championship(list).print();
	}
	
	return EXIT_SUCCESS;
}