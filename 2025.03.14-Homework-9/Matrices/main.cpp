#include <iostream>
#include "Matrix.h"


int main(int argc, char* argv[]) {
	Matrix m(3);
	for (int i = 0; i < m.getR(); ++i) {
		for (int j = 0; j < m.getC(); ++j) {
			int k = 0;
			std::cin >>k;
			m.set(i, j, k);
		}
	}
	


	m.print(std::cout);
	reverse(m).print(std::cout);
	add(m, m).print(std::cout);
	mult(m, m).print(std::cout);

	return EXIT_SUCCESS;
}