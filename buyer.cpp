#include "buyer.h" 
#include <iomanip>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <limits>

using namespace std;

buyer::buyer(string m_name) : name(m_name), orderID(0), total_pay(0), cash(0), change(0), pay_status(false) {}
buyer::buyer() : name(""), orderID(0), total_pay(0), cash(0), change(0), pay_status(false) {}

string buyer::getname() 
{
    return name;
}
int buyer::getorderID() {
    return orderID ;
}

double buyer::getTotalPay(){
    return total_pay ;
}
//operator overloading 
int buyer::operator+(const item &orderitem){

    
    return this -> total_pay + orderitem.getTotal() ;
}

void buyer::PrintDetail(double& sale)
{
    cout << setw(40) << name << setw(20) << total_pay << setw(20) << fixed << setprecision(2) << cash << setw(20) << fixed << setprecision(2) << change;

    if (pay_status)
    {
        sale += total_pay;
        cout << left << setw(10) << "Paid" << setw(20) << total_pay << endl;
    }
    else
    {
        cout << left << setw(10) << "Unpaid" << setw(20) << 0 << endl;
    }

}
void buyer::AddItem(LinkedList& storage, int count, int id[], string name[], double price[], int quantity[])
{   
    buyer b ;
    int choice, total_order = 0;
    bool pay = true;
    Node *ref = storage.gethead();  // head is a pointer to the head of the linked list
    Node *current = storage.gethead();  // head is a pointer to the head of the linked list
    do 
    {
        int ID, m_quantity, targetIndex = -1 ;
        do 
        {
            cout << "Item ID: ";
            cin >> ID;

            //clearing buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            //item identification
            current = storage.searchNode(ref, ID) ;         

            if (current == NULL)
                cout << "Invalid item id" << endl;
            
            else 
            {   
                cout << "\nItem Name: " << name[ID - 1] << "\nPrice: " << price[ID - 1];

                cout << "\nQuantity: ";
                cin >> m_quantity;
                cout << endl;
            }
        } while (current == NULL);

        //checking item in inventory
        if (current->data.getQuantity() - m_quantity < 0)
            cout << "Item is out of stock\n" << endl;
        else 
        {
            total_order = 1;
            //updating total item in inventory
            current->data.SetQuantity(current->data.getQuantity() - m_quantity);

            item itemOrdered = item(id[ID - 1], name[ID - 1], price[ID - 1], quantity[ID - 1], m_quantity);

            //updating subtotal
            total_pay =  b + itemOrdered ;
            items.push_back(itemOrdered);

            total_order++;
        }

        //generate order ID
        srand(time(0));
        orderID = 1 + (rand() % 100);

        //add more item
        if (total_order > 0) 
        {
            do 
            {
                cout << "Do you wish to\n1. Add another item \n2. Remove item \n3. Print Order" << endl;
                cout << "> ";
                cin >> choice;

                //clearing buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                if (choice == 2) 
                {
                    system("pause");
                    system("cls");
                    removeItem();
                    //refresh page
                    system("pause");
                    system("cls");
                    cout << "Please place your order based on the menu" << endl;
                    cout << left << setw(20) << "Item ID" << setw(40) << "Item Name" << setw(20) << "Price/RM" << endl;
                    for (int i = 0; i < count; i++) 
                    {
                        cout << left << setw(20) << id[i] << setw(40) << name[i] << setw(20) << price[i] << endl;
                    }
                }

                if (choice != 1 && choice != 2 && choice != 3)
                {
                    cout << "Invalid Input\n\n";
                }
            } while (choice != 1 && choice != 3);
        }
        else 
        {
            do 
            {
                cout << "\nDo you wish to add another item into your order list?\n 1. Yes\n 2. No" << endl;
                cout << "> ";
                cin >> choice;
            } while (choice != 1 && choice != 2);
        }
    } while (choice == 1);
    system("pause");
    system("cls");

    PrintOrder(pay);
    // cout << "\nOrder ID: " << orderID << endl << endl ;
}

void buyer::removeItem() {
    int num, index , choice;
    bool pass = false;
    bool pay = false;
    PrintOrder(pay);
    do 
    {   //confirmation
        do{
        cout << "Continue removing item?\n 1. Yes\n 2. No" << endl ;
        cout << "> ";
        cin >> choice ;
        }while (choice != 1 && choice != 2);

        if(choice == 2)
            return ;


        cout << "Please enter item No. to be removed\nItem No.: ";
        cin >> num;

        //clearing buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        if (num > 0 && num <= items.size())
        {
            pass = true;
            index = num;
        }
    } while (pass == false);

    //updating total
    total_pay -= items[index - 1].getTotal();
    num -= 1;
    items.erase(next(items.begin(), num));
    system("pause");
    system("cls");
    PrintOrder(pay);
}
void buyer::PrintOrder(bool _pay) 
{
    cout << "Order ID: " << orderID << endl;
    cout << "Order List" << endl;
    cout << "----------" << endl;
    cout << left << setw(10) << "No" << setw(20) << "ID" << setw(40) << "Name" << setw(20) << "Unit Price/RM" << setw(20) << "Quantity" << setw(20) << "Total Price/RM" << endl;

    for (int j = 0; j < items.size(); j++)
    {
        cout << left << setw(10) << j + 1 << setw(20) << items[j].getID() << setw(40) << items[j].getName();
        cout << left << setw(20) << fixed << setprecision(2) << items[j].getPrice() << setw(20) << items[j].getOrderQuantity();
        cout << left << setw(20) << fixed << setprecision(2) << items[j].getTotal() << endl;
    }
    cout << endl << "Subtotal: RM" << fixed << setprecision(2) << total_pay << endl << endl;

    if (_pay == true) 
    {
        int pay;
        do 
        {
            cout << "Do you want to continue with payment?";
            cout << "\n1: YES   2: NO\n";
            cout << "Choice: ";
            cin >> pay;

            //clearing buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if (pay == 1) 
            {
                system("pause");
                system("cls");
                payment();
            }
            else if (pay == 2)
                return;
            else
                cout << "Invalid input !\n\n";
            
        } while (pay != 1 && pay != 2);
    }
}

void buyer::payment() 
{
    int insert;
    if (pay_status == true) // Checking whether the order has been made payment or not
    {
        cout << "You have made payment for this order." << endl;
    }
    else
    {
        cout << "Order ID: " << orderID << endl;
        cout << "Total amount payable: RM " << total_pay << endl;
        cout << "This machine can only receive \n1. RM 1\n2. RM 5\n3. RM 10\n4. RM 50\n5. RM 100 \nnotes" << endl << endl;

        do
        {
            cout << "Note inserted: RM";
            cin >> insert;
            cout << "\nTotal amount inserted : RM" << insert << endl;

            if (insert != 1 && insert != 5 && insert != 10 && insert != 50 && insert != 100)
            {
                cout << "Invalid note inserted" << endl;
            }
            cash += insert;
        } while (cash < total_pay);

        change = cash - total_pay;
        pay_status = true;
        cout << "Cash: " << "RM " << fixed << setprecision(2) << cash << endl;
        cout << "Change: " << "RM " << fixed << setprecision(2) << change << endl;
    }
}