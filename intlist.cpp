// intlist.cpp
// Implements class IntList
// Justin Kim 4/6/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : head = nullptr, tail = nullptr {
    Node* current = source.head;
    while (current != nullptr) {
        push_back(current->info);
        current = current->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sumValue = 0;
    Node* current = head;
    while (current != nullptr) {
        count += current->info;
        current = current->next;
    }
    return sumValue;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* current = head->next;
    int maxValue = head->info;
    if (current == nullptr) {
        return 0;
    }
    while (current != nullptr) {
        if (maxValue < current->info) {
            maxValue = current->info;
        }
        current = current->next;
    }
    return maxValue;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int sums = sum();
    int numNodes = count();
    if (numNodes == 0 || sums == 0) {
        return 0.0;
    }
    double avg = static_cast<double>(sums) / numNodes;
    return avg;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
   int numVals = 0;
   Node* current = head;
   while (current != nullptr){
        numVals++;
        current = current->next;
   }
   return numVals;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    Node* current = head;
    if (this == &source) {
        return *this;
    }
    //DESTRUCTOR PART
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    //RESET PART
    head = nullptr;
    tail = nullptr;

    //CC
    Node* current = head.source;
    while (current != nullptr) {
        push_back(current->data);
        current = current->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList() : head = nullptr, tail = nullptr {}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

