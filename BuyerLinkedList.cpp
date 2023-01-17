#include "BuyerLinkedList.h"
#include <bits/stdc++.h>

// Brian Queue
// class Queue
// {
// 	public:
// 		Node *backPtr, *frontPtr;
		
// 		Queue()
// 		{
// 			frontPtr = backPtr = NULL;
// 			return;
// 		}
		
// 		void enQueue(BuyerNode d)
// 		{	
// 			Node* newNode = new Node;
// 			newNode->data = d;

// 			if(backPtr == NULL)
// 			{
// 				frontPtr = backPtr = newNode;
// 				return;
// 			}
			
// 			else
// 			{
// 				backPtr->next = newNode;
// 				backPtr = newNode;
// 			}
// 		}
		
// 		void deQueue()
// 		{
// 			if(frontPtr == NULL)
// 				return;
				
// 			Node *temp = frontPtr;
// 			frontPtr = frontPtr->next;
			
// 			if(frontPtr == NULL)
// 				backPtr == NULL;
				
// 			delete temp;
// 		}
		
		// int display()
		// {
		// 	char contin;
		// V:	if(frontPtr != NULL)
		// 	{
		// 		cout<<"\nBrand : "<<frontPtr->data.getBrand()<<endl;
	  //       	cout<<"Price : RM"<<frontPtr->data.getPrice()<<endl;
	  //           cout<<"Model : "<<frontPtr->data.getModel()<<endl<<endl;
	  //           deQueue();
	  //           cout<<"Press n for next racket order..: ";
	  //           cin>>contin;
	  //           if(contin == 'n' || contin == 'N')
	  //       	{
	  //       		goto V;
		// 		}
	  //           else
	  //           	return 3;
		// 	}
		// 	else
		// 	{
		// 		cout<<"No more racket to be process...\n\n";
		// 		return 2;
		// 	}
		// }
// };

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

