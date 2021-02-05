#pragma once

// 
// // class declarations
// 

class Node {
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(int data);
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
	Node* getPrev();
	void setPrev(Node* prev);
};