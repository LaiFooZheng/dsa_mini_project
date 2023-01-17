#include "seller.h"
#include "item.h"
#include "buyer.h"
#include <iomanip>
#include <fstream>
#include <iostream>
// #include <bits/stdc++.h>

using namespace std;

Seller::Seller() {}

void Seller::Inventory(LinkedList& storage, int count) 
{
    cout << left << setw(10) << "ID" << setw(35) << "Item Name" << setw(25) << "Price (RM)" << setw(25) << "Quantity" << endl;
    cout << "===============================================================================\n";

    Node *current = storage.gethead();
    while (current != NULL) 
    {
    current->data.PrintItem(count) ;  // print the value of the current node
    current = current->next;  // move to the next node in the list
    }


    // for (int i = 0; i < count; i++)
    // {
    //     storage[i].PrintItem(count);
    // }
}

void Seller::PaymentInfo(BuyerLinkedList& buyers)
{
    double sale = 0;
    cout << left << setw(40) << "Customer's Name" << setw(20) << "Total Amount/RM" << setw(20) << "Cash/RM" << setw(20) << "Change/RM" << setw(10) << "Status" << setw(10) << "Paid/RM" << endl;

    if (buyers.getSize() == 0)
    {
        cout << "There is no customer yet." << endl;
    }
    else
    {
        BuyerNode *current = buyers.gethead();
        while (current != NULL)  
        {

            current->data.PrintDetail(sale);
            current = current->next;
        }
        cout << right << setw(110) << "TOTAL: RM" << setw(1) << sale << endl;
    }
}

void Seller::DeleteItem(LinkedList& storage, int index, int count)
{
    int choice = 1, result;

    do
    {
        Inventory(storage, count);
        cout << "\nChoose item to be deleted: \nEnter ID: ";

        Node *head = storage.gethead();
        result = storage.deleteNode(head, index);
        system("cls");

        Inventory(storage, count);
        if(result == 1)
            cout << "\nItem ID: " << index << " has been successfully deleted";
        else
            cout << "\nItem ID: " << index << " not found";

        do
        {
            cout << "\n\nDelete another item ? \n1. YES 2. NO\n";
            cout << "> ";
            cin >> choice;
        } while (choice != 1 && choice != 2);
        system("cls");
    
    } while (choice != 2);

}

void Seller::AddItem(LinkedList & items, int count){

    int choice, ID, quantity; 
    double price;
    string name;

    do
    { 
        Inventory(items, count);
        cout << "Enter Item ID: "; 
        cin >> ID ; 
        cout << "Enter Item Name : "; 
        cin >> name ; 
        cout << "Enter Item Price : "; 
        cin >> price ; 
        cout << "Enter Item Quantity : "; 
        cin >> quantity ; 
        item newItem(ID, name, price, quantity, 0);
        
        system("cls");
        items.addNode(newItem);
        Inventory(items, count);
        cout << "\nItem ID : " << ID << " has been successfully added";
        
        do
        {
            cout << "Do you want to add another item ? \n1. YES 2. NO ";
            cout << "\n>";
            cin >> choice; 
        } while (choice != 1 && choice != 2 );
        system("cls");

    } while (choice != 2 );
   
}

void Seller::FindOrder(BuyerLinkedList & buyer )
{
    int index;

    cout << "\nEnter Order ID: ";
    cin >> index;

    BuyerNode *current = buyer.gethead();
    current = buyer.searchNode(current, index);

    if (current == NULL)
        cout << "Item Not Found"; 
    else  
        current->data.PrintOrder(false);      
    
}