#pragma once 
#include "item.h"

class Node
{
public:
	item data;
	Node *next;
	Node *prev;
	Node(item data) : data(data), prev(NULL), next(NULL) {}
	Node() : data(), prev(NULL), next(NULL) {}
};
