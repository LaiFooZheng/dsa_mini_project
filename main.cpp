// SECJ2013-5 STRUKTUR DATA DAN ALGORITMA (DATA STRUCTURE AND ALGORITHM)
// SEMESTER 1 2022/2023
// Assignment 1
// LAI FOO ZHENG (A21EC0040)
// MUHAMMAD ADAM BIN YAACOB (A21EC0060)
// ANG WEI LONG (A21EC0162)

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include<bits/stdc++.h>
#include <limits>
#include "item.h"
#include "buyer.h"
#include "seller.h"
#include "node.h"
#include "Buyernode.h"
#include "LinkedList.h"
#include "BuyerLinkedList.h"
#include "Delivery.h"

using namespace std;

void clearConsole(); // Pause and clear console
void clearBuffer(); // Clear buffer for cin
bool mainMenu(int, int[], string[], double[], int[]);

// Sorting 
// Simple Sort (Bubble Sort)
void bubbleSortAsc(Node *&);
void bubbleSortDes(Node *&);

// Advance Sort (Quick Sort)
void quickSortAsc(Node *&, Node *);
Node* partitionAsc(Node *&, Node *);
void quickSortDes(Node *&, Node *);
Node* partitionDes(Node *&, Node *);

// Seller
void sellerMenu(int);

// Buyer
void buyerMenu(int, int[], string[], double[], int[]);

void displayMenu();
void displayList();
void displayInputList();
void makeOriList();

// LinkedList declaration;
LinkedList items ;
BuyerLinkedList buyers;
vector<item>items_copy;
Seller s;
DeliveryQueue q ;

int main()
{
    bool loop = true;
    int count = 0;

    fstream infile;
    infile.open("inventory.txt");
    string content;

    if (!infile)
        cout << "Input file does not exist\n";
    else
    {
        while (getline(infile, content))
            count++;

        // Resets the file after getting the count
        infile.close();
        infile.open("inventory.txt");

        int* item_id = new int[count];
        string* item_name = new string[count];
        double* item_price = new double[count];
        int* item_quantity = new int[count];

        for (int i = 0; i < count; i++)
        {
            infile >> item_id[i] >> item_name[i] >> item_price[i] >> item_quantity[i];
            item seller_item(item_id[i], item_name[i], item_price[i], item_quantity[i], 0);
            items.addNode(seller_item);
            items_copy.push_back(seller_item);
        }

        do
        {
            loop = mainMenu(count, item_id, item_name, item_price, item_quantity);
        } while (loop);

        // Free memory
        delete[] item_id;
        delete[] item_name;
        delete[] item_price;
        delete[] item_quantity;

        return 0;
    }
}

void clearConsole() 
{
    system("pause");
    system("cls");
}

void clearBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

bool mainMenu(int count, int id[], string name[], double price[], int quantity[])
{
    int choice;
    bool loop = true;

    do 
    {
        cout << "SHOPPING SYSTEM\n\n"
            << "Main Menu\n"
            << "Please select your role:\n"
            << "1. Seller\n"
            << "2. Buyer\n"
            << "3. Exit Program\n"
            << "> ";

        cin >> choice;

        // Pauses every time when input is made
        clearConsole();

        if (choice == 1)
        {
            sellerMenu(count);
        }
        else if (choice == 2)
        {
            buyerMenu(count, id, name, price, quantity);
        }
        else if (choice == 3)
        {
            loop = false;
            break;
        }
        else
        {
            clearBuffer();
            cout << "Invalid Input\n";
            clearConsole();
        }
    } while (true);

    return loop;
}

// Simple Sort (Bubble Sort)

void bubbleSortAsc(Node *&head) {
  bool sorted = false;  // flag to track if the list is sorted
  while (!sorted) {
    sorted = true;  // assume the list is sorted until proven otherwise
    Node *current = head;  // start at the beginning of the list
    while (current->next != NULL) {  // stop before the end of the list
      if (current->data.getQuantity() > current->next->data.getQuantity()) {  // if the current element is greater than the next element
        item temp = current->data;  // swap the elements
        current->data = current->next->data;
        current->next->data = temp ;
        sorted = false;  // mark the list as not sorted
      }
      current = current->next;  // move to the next element
    }
  }
}
void bubbleSortDes(Node *&head) {
  bool sorted = false;  // flag to track if the list is sorted
  while (!sorted) {
    sorted = true;  // assume the list is sorted until proven otherwise
    Node *current = head;  // start at the beginning of the list
    while (current->next != NULL) {  // stop before the end of the list
      if (current->data.getQuantity() < current->next->data.getQuantity()) {  // if the current element is greater than the next element
        item temp = current->data;  // swap the elements
        current->data = current->next->data;
        current->next->data = temp ;
        sorted = false;  // mark the list as not sorted
      }
      current = current->next;  // move to the next element
    }
  }
}


// Advance Sort (Quick Sort)
void quickSortAsc(Node *&head, Node *end) {
  if (head == NULL || head == end) {
    return;  // base case: list is empty or has only one element
  }
  Node *pivot = partitionAsc(head, end);  // partition the list around the pivot
  quickSortAsc(head, pivot);  // sort the left half of the list
  quickSortAsc(pivot->next, end);  // sort the right half of the list
}

Node* partitionAsc(Node *&head, Node *end) {
  Node *pivot = end;                            // choose the last element as the pivot
  Node *current = head;
  Node *prev = NULL;
  while (current != pivot) {
    if (current->data.getPrice() < pivot->data.getPrice()) {          // if the current element is smaller than the pivot
      if (prev != NULL) {                       // if the current element is not the head of the list
        prev->next = current->next;             // remove the current element from the list
      } else {
        head = current->next;                   // update the head of the list
      }
      current->next = pivot->next;              // insert the current element after the pivot
      pivot->next = current;
      current = prev;                           // move the current element back to the previous position
    }
    prev = current;                             // move to the next element
    current = current->next;
  }
  return pivot;                                 // return the pivot element
}
void quickSortDes(Node *&head, Node *end) {
  if (head == NULL || head == end) {
    return;  // base case: list is empty or has only one element
  }
  Node *pivot = partitionDes(head, end);  // partition the list around the pivot
  quickSortDes(head, pivot->prev);  // sort the left half of the list
  quickSortDes(pivot->next, end);  // sort the right half of the list
}

Node* partitionDes(Node *&head, Node *end) {
  Node *pivot = end;                                        // choose the last element as the pivot
  Node *current = head;
  while (current != pivot) {
    if (current->data.getPrice() < pivot->data.getPrice()) {    // if the current element is smaller than the pivot
      if (current->prev != NULL) {                              // if the current element is not the head of the list
        current->prev->next = current->next;                    // remove the current element from the list
      } else {
        head = current->next;                                   // update the head of the list
      }
      current->next->prev = current->prev;
      current->prev = pivot->prev;                              // insert the current element before the pivot
      pivot->prev = current;
      current->next = pivot;
      current = current->prev;                                  // move the current element back to the previous position
    } else {
      current = current->next;                                  // move to the next element
    }
  }
  return pivot;                                                 // return the pivot element
}


// Seller Menu Functionality
void sellerMenu(int count)
{
    int choice;
    
    do
    {
        cout << "Seller Menu\nSelect Option\n"
            << "1. View Inventory\n2. View Sale\n3. Delete item\n4. Add item\n5. Find buyer order details\n6. Display Delivery List\n7. Update the delivery list of an item that has been shipped. \n8. Back to Main Menu\n> ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nCurrent Inventory\n";
            s.Inventory(items, count);
            displayMenu();
        }
        else if (choice == 2)
        {   
            system("cls") ;
            s.PaymentInfo(buyers);
            clearConsole();
        }
        else if (choice == 3)
        {   
            system("cls") ;
            s.DeleteItem(items, count) ;
            // return;
        }
        else if (choice == 4)
        {   
            system("cls") ;
            s.AddItem(items, count) ;
            displayList() ;
            // return;
        }
        else if (choice == 5)
        {
            if(buyers.getSize() == 0){
                system("cls") ;
                cout << "No buyer yet !! \n" ;
            }
            else{
                    int choice_ ;
                do{
                    system("cls") ;
                    cout << "BUYER ORDER DETALS " ;
                    s.FindOrder(buyers) ;

                    do{
                    cout << "\nFind another order details ? \n1. YES 2. NO" ;
                    cout << "\n>" ;
                    cin >> choice_ ;
                    }while(choice_ != 1 && choice_ != 2) ;
                }while(choice_ == 1) ;
            }
            clearConsole() ;
            // break;
        }
        else if (choice == 6)   // display delivery list
        {   
            system("cls") ;
            q.display() ;
            clearConsole() ;
            
        }
        else if (choice == 7)   // display delivery list
        {   
            system("cls") ;
            
            if(q.isEmpty() == false){
                DeliveryNode temp = q.front() ;
                cout << "Name : " << temp.data.getname() << endl<< "Order ID : " << temp.data.getorderID() << endl << "has been successfully shipped to " << temp.data.getaddress() << endl ;
            }
            q.dequeue() ;
            q.display() ;
            clearConsole() ;
        }
        else if (choice == 8)
        {
            clearConsole();
            return;
        }
        else 
        {
            clearBuffer();
            cout << "Invalid Input\n";
            clearConsole();
        }
    } while (true);
}

// Buyer Menu Functionality
void buyerMenu(int count, int id[], string name[], double price[], int quantity[])
{
    int choice;
    do
    {
        cout << "Buyer Menu\nSelect Option\n"
            << "1. Sort & Display List\n2. Make an Order\n3. Make Payment\n4. Back to Main Menu\n> ";
        cin >> choice;

        if (choice == 1)
        {
            displayMenu();
        }
        else if (choice == 2)
        {
            cout << "Place your order based on the menu" << endl;
            displayList();

                string cus_name;
            while(cus_name.empty()){
                cout << "\nPlease enter the details of your order";
                cout << "\nName: ";
                cin.ignore() ;
                getline(cin,cus_name);

                if(cus_name.empty())
                    cout << "\nInvalid input. Please try again." << endl ;
            }
            buyer cus = buyer(cus_name);
            cus.AddItem(items, count, id, name, price, quantity);
            buyers.addNode(cus);

            bool delivery = cus.delivery() ;

            if(delivery == true ){

                
                q.enqueue(cus);

                
            }

            clearConsole();
        }
        else if (choice == 3)
        {   
            BuyerNode *current = buyers.gethead();
            if (buyers.getSize() == 0)
                return;
            int index = 0;
            bool status = true;
            if (buyers.getSize() > 1) {
                string name;
                do {
                    cout << "Enter Name: ";
                    cin >> name;
                    
                    while (current != NULL) {

                        if (name == current->data.getname()) {
                            status = false;
                            break;
                        }
                        current = current->next ;
                    }
                    if (status)
                        cout << "Invalid Name\n";
                } while (status);
            }

            current->data.payment();
            clearConsole();
            return;
        }
        else if (choice == 4)
        {
            clearConsole();
            return;
        }
        else
        {
            clearBuffer();
            cout << "Invalid Input\n";
            clearConsole();
        }
    } while (true);
}

void displayMenu()
{
    int choice;
    Node *head = items.gethead();  // pointer to the head of the linked list
    Node* last = items.gethead() ;
    do
    {
        clearConsole();
        cout << "Select Option\n"
            << "1. Display the current list\n"
            << "2. Sort the list based on Price (Ascending / Descending) -- Uses Quick Sort\n"
            << "3. Sort the list based on Quantity (Ascending / Descending) -- Uses Bubble Sort\n"
            << "4. Display the list as how it was originally in the Input File\n"
            << "5. Back\n"
            << "> ";
        cin >> choice;

        if (choice == 1)
        {
            displayList();
        }
        else if (choice == 2)
        {   
            cout << "\nWe will implement this soon ;D" << endl ;
            // int sort_choice;
            // do
            // {
            //     cout << "1. Ascending\n"
            //         << "2. Descending\n"
            //         << "3. Back\n"
            //         << "> ";
            //     cin >> sort_choice;
            //     if (sort_choice == 1)
            //     {
            //         cout << "\nSorted the list in Ascending Order based on Price\n\n";
                    
            //         quickSortAsc(head, NULL);  // sort the linked list

            //         displayList();
            //         break;
            //     }
            //     else if (sort_choice == 2)
            //     {   
            //         while (last->next != NULL)
            //             last = last->next;
            //         cout << "\nSorted the list in Descending Order based on Price\n\n";
            //         quickSortDes(head, last) ;
            //         // quickSortDes(items, items.getSize() - 1);
            //         displayList();
            //         break;
            //     }
            //     else if (sort_choice == 3)
            //     {
            //         break;
            //     }
            //     else
            //     {
            //         clearBuffer();
            //         cout << "Invalid Input\n";
            //         break;
            //     }
            // } while (true);
        }
        else if (choice == 3)
        {
            int sort_choice;
            do
            {
                cout << "1. Ascending\n"
                    << "2. Descending\n"
                    << "3. Back\n"
                    << "> ";
                cin >> sort_choice;
                if (sort_choice == 1)
                {
                    cout << "\nSorted the list in Ascending Order based on Quantity\n\n";
                    bubbleSortAsc(head);
                    displayList();
                    break;
                }
                else if (sort_choice == 2)
                {
                    cout << "\nSorted the list in Descending Order based on Quantity\n\n";
                    bubbleSortDes(head);
                    displayList();
                    break;
                }
                else if (sort_choice == 3)
                {
                    break;
                }
                else
                {
                    clearBuffer();
                    cout << "Invalid Input\n";
                    break;
                }
            } while (true);
        }
        else if (choice == 4)
        {
            int list_choice;
            displayInputList();
            cout << "\nDo you wish to sort the list to how it was originally in the Input File?\n 1. Yes\n 2. No\n" << endl;
            cout << "> ";
            cin >> list_choice;

            if (list_choice == 1)
            {
                makeOriList();
                clearConsole();
            }
            else if (list_choice == 2)
            {
                continue;
            }
            else
            {
                clearBuffer();
                cout << "Invalid Input\n";
            }
        }
        else if (choice == 5)
        {
            clearConsole();
            return;
        }
        else
        {
            clearBuffer();
            cout << "Invalid Input\n";
        }
    } while (true);
}

void displayList()
{   
    Node *current = items.gethead(); 
    cout << left << setw(10) << "ID" << setw(35) << "Item Name" << setw(25) << "Price (RM)" << setw(25) << "Quantity" << endl;
    cout << "===============================================================================\n";
    cout << fixed;
    cout << setprecision(2);
    while (current != NULL)
    {
        cout << left << setw(10) << current->data.getID() << setw(35) << current->data.getName() << setw(25) << current->data.getPrice() << setw(25) << current->data.getQuantity() << endl;
        current = current->next;
    }
}

void displayInputList()
{
    cout << left << setw(10) << "ID" << setw(35) << "Item Name" << setw(25) << "Price (RM)" << setw(25) << "Quantity" << endl;
    cout << "===============================================================================\n";
    cout << fixed;
    cout << setprecision(2);
    for (int i = 0; i < items_copy.size(); i++)
    {
        cout << left << setw(10) << items_copy[i].getID() << setw(35) << items_copy[i].getName() << setw(25) << items_copy[i].getPrice() << setw(25) << items_copy[i].getQuantity() << endl;
    }
}

void makeOriList()
{   
    Node *current = items.gethead(); 
    int i = 0 ;

    cout << "List was sorted back to how it was originally in the Input File";
    cout << left << setw(10) << "ID" << setw(35) << "Item Name" << setw(25) << "Price (RM)" << setw(25) << "Quantity" << endl;
    cout << "===============================================================================\n";
    cout << fixed;
    cout << setprecision(2);
    while (current != NULL)
    {
        current->data = items_copy[i];
        cout << left << setw(10) << current->data.getID() << setw(35) << current->data.getName() << setw(25) << current->data.getPrice() << setw(25) << current->data.getQuantity() << endl;
        current = current->next;
    }
}