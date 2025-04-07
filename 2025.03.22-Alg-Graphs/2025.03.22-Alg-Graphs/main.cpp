#include <iostream>
#include "Graph.h"

int main(int argc, int argv[]) {
	Graph t;
	t.readEdgeList();
	t.printAdjencyList();

	return EXIT_SUCCESS;
}