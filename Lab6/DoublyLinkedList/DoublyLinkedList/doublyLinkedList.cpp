
#include <iostream>
#include "doublyLinkedList.h"

// 
// // class definitions
// 

bool DoublyLinkedList::add(Node* data, int pos) {
	// return false if data is a nullptr
	// or if invalid position is incerted.
	if (data == nullptr || pos > this->len)
		return false;
	else if (pos == 0) {
		this->head = data;
	}
	else {
		Node* currentNode = this->head;
		Node* nextNode;
		Node* prevNode;
		for (int i = 0; i < pos; i++) {
			currentNode = currentNode->getNext();
		}
		nextNode = currentNode->getNext();
		nextNode->setPrev(data);
		prevNode = currentNode->getPrev();
		prevNode->setNext(data);
		data->setNext(nextNode);
		data->setPrev(prevNode);
		currentNode = nullptr;
	}
	this->len++;
	return true;
}
bool DoublyLinkedList::remove(int pos) {

}
bool DoublyLinkedList::replace(Node* oldN, Node* newN) {

}
int DoublyLinkedList::search(Node* data) {

}
Node* DoublyLinkedList::nodeAt(int pos) {

}
void DoublyLinkedList::displayForward() {

}
void DoublyLinkedList::displayBackward() {

}
int DoublyLinkedList::size() {

}