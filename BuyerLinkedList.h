#pragma once 

#include "BuyerNode.h"

class BuyerLinkedList {
  private:
    BuyerNode *head;
    BuyerNode *tail ;
  public:
    
    BuyerLinkedList(void) { head = NULL; }
    ~BuyerLinkedList(void);
    BuyerNode* gethead(); 
    void addNode(buyer data);
    void deleteNode(int data);
    BuyerNode* searchNode(BuyerNode*, int );
    int getSize();
};
