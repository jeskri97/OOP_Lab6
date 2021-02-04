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
	int getData();
	void setData(int data);
	Node* getNext();
	void setNext(Node* next);
	Node* getPrev();
	void setPrev(Node* prev);
};