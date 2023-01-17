#include "LinkedList.h"
#include <bits/stdc++.h>

LinkedList::~LinkedList()
{ 
	Node* currNode = head, *nextNode = NULL;
	while (currNode != NULL)
	{   
		nextNode = currNode->next;
		// destroy the current node
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
}

void LinkedList::addNode(item data)
{
  Node *newNode = new Node(data);
    if (tail == NULL) // special case: list is empty
	{  
		tail = newNode;
		head = newNode ;
		return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode ;
}

Node* LinkedList::gethead()
{
  return head ;
}

int LinkedList::getSize() 
{
	int size = 0;
	Node *current = head;
	while (current != NULL) 
	{
		size++;
		current = current->next;
	}
	return size;
}

// Delete a node from a singly linked list

int LinkedList::deleteNode(Node *&node, int index) 
{
	Node *current = node;

	while (current != NULL) 
	{
		if (current->data.getID() == index) 
		{
			if (current->prev != NULL) // if the node is not the head of the list
			{  
				current->prev->next = current->next;
			} 
			else 
			{
				head = current->next;  // update the head of the list
			}
			if (current->next != NULL) // if the node is not the tail of the list
			{  
				current->next->prev = current->prev;
			}
			delete current;
			return 1;
		}
		current = current->next;
	}
	// std::cout << "Node not found" << std::endl;
	return 0 ;
}

// Search for a node in a singly linked list
Node* LinkedList::searchNode(Node *head, int index) 
{
	Node *current = head;
	int i = 0;
	while (current != NULL) 
	{
		i++;
		if (i == index) 
		{
			return current;
		}
		current = current->next;
	}
	return NULL;
}

