#pragma once

#include "node.h"

// 
// // class declarations
// 

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int len = 0;
public:
	bool add(Node* data, int pos);
	bool remove(int pos);
	bool replace(Node* oldN, Node* newN);
	int search(Node* data);
	Node* nodeAt(int pos);
	void displayForward();
	void displayBackward();
	int size();
};