#include "BuyerLinkedList.h"
#include <bits/stdc++.h>


BuyerLinkedList::~BuyerLinkedList()
{ 
  BuyerNode* currNode = head, *nextNode = NULL;
  while (currNode != NULL)
  {   
    nextNode = currNode->next;
    // destroy the current node
    delete currNode;
    currNode = nextNode;
  }
  head = NULL;
}

void BuyerLinkedList::addNode(buyer data) {
  BuyerNode *newNode = new BuyerNode;
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;
  if (head != NULL) {
    head->prev = newNode;
  }
  head = newNode;
}


BuyerNode* BuyerLinkedList::gethead(){

  return head ;
}

int BuyerLinkedList::getSize() {
  int size = 0;
  BuyerNode *current = head;
  while (current != NULL) {
    size++;
    current = current->next;
  }
  return size;
}

BuyerNode* BuyerLinkedList::searchNode(BuyerNode *head, int index) {
  BuyerNode *current = head;
  int i = 0 ;
  while (current != NULL) {
    i++ ;
    if (current->data.getorderID() == index) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

