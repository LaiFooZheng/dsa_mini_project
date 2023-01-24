#pragma once

#include <iostream>
#include "item.h"
#include "buyer.h"
#include <vector>
#include "LinkedList.h"
#include "BuyerLinkedList.h"
using namespace std;

class Seller {
    private:
        //   string s_name, Shopname, Location;
        //   int seller_id ;
        item sell_item;
        vector<item> items;

    public:
        // Seller(string, string, string, int) ;
        Seller();
        void Inventory(LinkedList&, int);
        void AddItem(LinkedList&, int );
        void DeleteItem(LinkedList&, int) ;
        void FindOrder(BuyerLinkedList & ) ;

        void PrintSellerItem();

        void PaymentInfo(BuyerLinkedList&);
};
