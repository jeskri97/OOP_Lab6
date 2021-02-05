
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
	}
	// Remove tail.
	else if (pos == this->len && this->len != 0) {
		this->tail = this->tail->getPrev();
		this->tail->setNext(nullptr);
	}
	// Remove at pos.
	else {
		//printf("\nremove at pos %i\n", pos);
		Node* currentNode = this->head;
		for (int i = 1; i < pos; i++) {
			currentNode = currentNode->getNext();
		}
		//printf("currentNode data = %i\n", currentNode->getData());
		currentNode->getPrev()->setNext(currentNode->getNext());
		currentNode->getNext()->setPrev(currentNode->getPrev());
	}
}
//bool DoublyLinkedList::replace(Node* oldN, Node* newN) {
//
//}
//int DoublyLinkedList::search(Node* data) {
//
//}
//Node* DoublyLinkedList::nodeAt(int pos) {
//
//}
//void DoublyLinkedList::displayForward() {
//
//}
//void DoublyLinkedList::displayBackward() {
//
//}
//int DoublyLinkedList::size() {
//
//}
void DoublyLinkedList::debugPrint() {
	Node* currentNode = this->head;
	printf("Lenght = %i\n", this->len);
	while (currentNode->getNext() != nullptr) {
		printf("Data = %i\n", currentNode->getData());
		currentNode = currentNode->getNext();
	}
	printf("Data = %i\nDONE\n", currentNode->getData());
}