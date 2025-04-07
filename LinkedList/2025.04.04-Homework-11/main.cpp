#include "LinkedList.h"
int main(int argc, char* argv[]) {

	LinkedList list;
	for (int i = 0; i < 5; ++i) {
		list.InsertTail(i * 3);
	}
	list.Print();

	return 0;
}