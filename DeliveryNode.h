#pragma once 

#include "buyer.h"

class DeliveryNode {

  public:
    buyer data;
    DeliveryNode *next;
    DeliveryNode(buyer data) : data(data), next(NULL) {}
    DeliveryNode() : data(), next(NULL) {}
};
