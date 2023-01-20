#pragma once 

#include "DeliveryNode.h"

class DeliveryQueue {

  private:

    DeliveryNode* head ;
    DeliveryNode* tail ;
  
  public:

    DeliveryQueue() ;
    void enqueue(buyer) ;
    buyer dequeue() ;
    bool isEmpty() ;
    buyer front() ;
    buyer rear() ;
    void display() ;

};
