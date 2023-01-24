#pragma once
#include "item.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>
using namespace std;

class buyer 
{
    private:
        string name = "", address = "";  
        int orderID, cash;
        bool pay_status = false;    
        double total_pay, change;

        item itemOrdered;
        vector<item>items;

    public:
        buyer(string);
        buyer();

        string getname();
        string getaddress();
        double getTotalPay() ;
        int getorderID() ;
        void PrintDetail(double&);
        void AddItem(LinkedList&, int, int[], string[], double[], int[]);
        void removeItem(buyer &);
        void PrintOrder(bool);
        void payment();
        bool delivery();
        // void PrintDelivery();

        //overloaded operator
        double operator+(const item &) ;
        double operator-(const item &) ;
};

