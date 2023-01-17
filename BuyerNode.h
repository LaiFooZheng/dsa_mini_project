#pragma once 

#include "buyer.h"

class BuyerNode {

  public:
    buyer data;
    BuyerNode *next;
    BuyerNode *prev;
    BuyerNode(buyer data) : data(data), prev(NULL), next(NULL) {}
    BuyerNode() : data(), prev(NULL), next(NULL) {}
};
