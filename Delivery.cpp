#include "Delivery.h"

#include <iomanip>


DeliveryQueue::DeliveryQueue() {
        this->head = nullptr;
        this->tail = nullptr;
    }

// function to add an element to the delivery queue
void DeliveryQueue::enqueue(buyer x) {
    DeliveryNode* temp = new DeliveryNode;
    temp->data = x;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp = nullptr;
    } else {
        tail->next = temp;
        tail = temp;
    }

    cout << "\nOrder has been added to the delivery list\n" ;
}

// function to remove an element from the delivery queue
buyer DeliveryQueue::dequeue() {
    DeliveryNode* temp = new DeliveryNode;
    if (head == nullptr) {
        cout << "Delivery Queue is empty" << endl;
        return buyer();
    }
    temp = head;
    head = head->next;
    return temp->data;
}

// function to check if the delivery queue is empty
bool DeliveryQueue::isEmpty() {
    return (head == nullptr);
}

// function to return the front element of the delivery queue
buyer DeliveryQueue::front() {
    if (head == nullptr) {
        cout << "Delivery Queue is empty" << endl;
        return buyer();
    }
    return head->data;
}

// function to return the rear element of the delivery queue
buyer DeliveryQueue::rear() {
    if (tail == nullptr) {
        cout << "Delivery Queue is empty" << endl;
        return buyer();
    }
    return tail->data;
}

void DeliveryQueue::display() {
        if (head == nullptr) {
            cout << "Delivery Queue is empty" << endl;
            return;
        }
        DeliveryNode* temp = head;
        while (temp != nullptr) {
            cout << left << "\nAddress : " << setw(40) <<  temp->data.getaddress()  << "Name: " << temp->data.getname()<< endl ;
            temp->data.PrintOrder(false);
            temp = temp->next;
        }
        cout << endl;
    }