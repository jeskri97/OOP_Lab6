
#include <iostream>
#include "doublyLinkedList.h"

int main(void) {
	DoublyLinkedList test;
	Node n1(1), n2(2), n3(3), n4(4);
	test.add(&n1, 0);
	test.add(&n2, 1);
	test.displayForward();
	printf("\n");
	test.add(&n3, 1);
	test.displayForward();
	printf("\n");

	test.replace(&n3, &n4);
	test.displayForward();
	printf("\n");

	int i = 1;
	printf("nodeAt(%i) data: %i\n", i, test.nodeAt(i)->getData());

	printf("\nsize() = %i\n\n", test.size());

	test.remove(2);
	test.displayForward();
}