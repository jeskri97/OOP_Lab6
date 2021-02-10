
#include <iostream>
#include "doublyLinkedList.h"

// 
// // class definitions
// 

bool DoublyLinkedList::add(Node* data, int pos) {
	if (data == nullptr || pos > this->len) {
		// return false if data is a nullptr
		// or if invalid position is incerted.
		//printf("return false;\n");
		return false;
	}
	// List is empty
	else if (pos == 0 && this->len == 0) {
		//printf("Empty list\n");
		this->head = data;
		this->tail = data;
	}
	// List not empty
	// Change head
	else if (pos == 0 && this->len != 0) {
		//printf("change head\n");
		this->head->setPrev(data);
		data->setNext(this->head);
		this->head = data;
	}
	// List not empty
	// Change tail
	else if (pos == this->len && this->len != 0) {
		//printf("change tail\n");
		this->tail->setNext(data);
		data->setPrev(this->tail);
		this->tail = data;
	}
	// List not empty
	// add at pos
	else {
		//printf("add at pos\n");
		Node* currentNode = this->head;
		for (int i = 0; i < pos; i++) {
			currentNode = currentNode->getNext();
		}
		//printf("\ncurrentNode data = %i\n", currentNode->getData());
		data->setPrev(currentNode->getPrev());
		data->setNext(currentNode);
		currentNode->getPrev()->setNext(data);
		currentNode->setPrev(data);
	}
	this->len++;
	return true;
}
bool DoublyLinkedList::remove(int pos) {
	if (pos > this->len || this->len == 0) {
		// return false if invalid pos.
		return false;
	}
	// Remove head.
	else if (pos == 0) {
		Node* oldHead = this->head;
		Node* newHead = oldHead->getNext();
		newHead->setNext(oldHead->getNext()->getNext());
		this->head = newHead;
		oldHead->~Node();
	}
	// Remove tail.
	else if (pos == this->len && this->len != 0) {
		Node* oldTail = this->tail;
		Node* newTail = oldTail->getPrev();
		newTail->setPrev(oldTail->getPrev()->getPrev());
		newTail->setNext(nullptr);
		this->tail = newTail;
		oldTail->~Node();
	}
	// Remove at pos.
	else {
		//Node* currentNode = this->nodeAt(pos);
		//if (currentNode == nullptr) {
		//	return false;
		//}
		//currentNode->getPrev()->setNext(currentNode->getNext());
		//currentNode->getNext()->setPrev(currentNode->getPrev());
		//currentNode->~Node();

		//printf("\nremove at pos %i\n", pos);
		Node* currentNode = this->head;
		for (int i = 1; i < pos; i++) {
			currentNode = currentNode->getNext();
		}
		//printf("currentNode data = %i\n", currentNode->getData());
		currentNode->getPrev()->setNext(currentNode->getNext());
		currentNode->getNext()->setPrev(currentNode->getPrev());
		currentNode->~Node();
	}
	this->len--;
	return true;
}
bool DoublyLinkedList::replace(Node* oldN, Node* newN) {
	if (oldN == nullptr || newN == nullptr) {
		// return false if any input is invalid.
		return false;
	}
	Node* currentNode = this->head;
	while (currentNode != nullptr) {
		// Found old Node.
		if (currentNode == oldN) {
			// Old node is head.
			if (oldN == this->head) {
				newN->setNext(currentNode->getNext());
				newN->setPrev(nullptr);
				currentNode->getNext()->setPrev(newN);
			}
			// Old node is tail.
			else if (oldN == this->tail) {
				newN->setNext(nullptr);
				newN->setPrev(currentNode->getPrev());
				currentNode->getPrev()->setNext(newN);
			}
			// Old node is neither head nor tail.
			else {
				newN->setNext(currentNode->getNext());
				newN->setPrev(currentNode->getPrev());
				currentNode->getPrev()->setNext(newN);
				currentNode->getNext()->setPrev(newN);
			}
			// Deallocate the old Node.
			oldN->~Node();
			return true;
		}
		currentNode = currentNode->getNext();
	}
	// Did not find old Node.
	return false;
}
int DoublyLinkedList::search(Node* data) {
	if (data == nullptr) {
		return -1;
	}
	// return index if node is found.
	else if (data == this->head) {
		return 0;
	}
	else if (data == this->tail) {
		return this->len;
	}
	else {
		Node* currentNode = this->head;
		//int index = 0;
		for (int i = 0; i < this->len; i++) {
			if (currentNode == data) {
				return i;
			}
			currentNode = currentNode->getNext();
		}
	}
	// return -1 if node not found.
	return -1;
}
Node* DoublyLinkedList::nodeAt(int pos) {
	if (pos > this->len || this->len == 0) {
		// returns a nullptr if invalid pos.
		return nullptr;
	}
	else {
		Node* currentNode = this->head;
		for (int i = 0; i < pos; i++) {
			currentNode = currentNode->getNext();
		}
		return currentNode;
	}
}
void DoublyLinkedList::displayForward() {
	Node* currentNode = this->head;
	printf("Lenght = %i\n", this->len);
	while (currentNode->getNext() != nullptr) {
		printf("Data = %i\n", currentNode->getData());
		currentNode = currentNode->getNext();
	}
	printf("Data = %i\nDONE\n", currentNode->getData());
}
void DoublyLinkedList::displayBackward() {
	Node* currentNode = this->tail;
	printf("Lenght = %i\n", this->len);
	while (currentNode->getPrev() != nullptr) {
		printf("Data = %i\n", currentNode->getData());
		currentNode = currentNode->getPrev();
	}
	printf("Data = %i\nDONE\n", currentNode->getData());
}
int DoublyLinkedList::size() {
	return this->len;
}