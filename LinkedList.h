#pragma once

#include "node.h"

class LinkedList 
{
private:
    Node *head;
    Node *tail;

public:
	LinkedList(void) { head = NULL; }
	~LinkedList(void);
	Node* gethead(); 
	void addNode(item data);
	int deleteNode(Node*&, int );
	Node* searchNode(Node* , int);
	int getSize();
};
