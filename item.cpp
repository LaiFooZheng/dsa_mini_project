#include "item.h"
#include <iomanip>

item::item() 
{
    ID = 0;
    name = " ";
    price = 0;
    quantity = 0;
    order_quantity = 0;
}

item::item(int m_ID, string m_name, double m_price, int m_quantity, int m_order)
    : ID(m_ID), name(m_name), price(m_price), quantity(m_quantity), order_quantity(m_order) {}

void item::SetQuantity(int m_quantity)
{
    quantity = m_quantity;
}

int item::getID()
{
    return ID;
}

string item::getName()
{
    return name;
}

double item::getPrice()
{
    return price;
}

int item::getQuantity()
{
    return quantity;
}

int item::getOrderQuantity()
{
    return order_quantity;
}

double item::getTotal() const
{
    return order_quantity * price;
}

void item::PrintItem(int count)
{
    cout << fixed;
    cout << setprecision(2);

    cout << left << setw(10) << ID << setw(35) << name << setw(25) << price << setw(25) << quantity << endl;
}