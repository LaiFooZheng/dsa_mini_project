#pragma once

#include <iostream>
using namespace std;

class item 
{
    private:
        string name;
        double price;
        int quantity, // total item in inventory
            order_quantity, // order quantity by customer 
            ID;
    public:
        item();
        item(int, string, double, int, int);

        //  setItem();
        void SetQuantity(int);

        //  getItem()   ;
        int getID();
        string getName();
        double getPrice();
        int getQuantity();
        int getOrderQuantity();
        double getTotal() const;
        void PrintItem(int);
};