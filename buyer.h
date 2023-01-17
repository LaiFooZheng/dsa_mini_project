#pragma once
#include "item.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

class buyer 
{
    private:
        string name = " ";
        int orderID, cash;
        bool pay_status = false;
        double total_pay, change;

        item itemOrdered;
        vector<item>items;

    public:
        buyer(string);
        buyer();

        string getname();
        double getTotalPay() ;
        int getorderID() ;
        void PrintDetail(double&);
        void AddItem(LinkedList&, int, int[], string[], double[], int[]);
        void removeItem();
        void PrintOrder(bool);
        void payment();

        //overloaded operator
        int operator+(const item &) ;
};

