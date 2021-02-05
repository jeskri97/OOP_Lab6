
#include <iostream>
#include "doublyLinkedList.h"

int main(void) {
	DoublyLinkedList test;
	Node n1(1), n2(2), n3(3);
	test.add(&n1, 0);
	test.add(&n2, 1);
	test.debugPrint();
	test.add(&n3, 1);
	test.debugPrint();

	test.remove(2);
	test.debugPrint();
}