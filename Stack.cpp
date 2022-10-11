#include "Stack.h"
#include<iostream>
using namespace std;

// Constructor and destructor

Stack::Stack(){   
   top = nullptr;
}

Stack::~Stack(){   
   while(!isEmpty()) {
      Node *temp = top;
      top = temp->next;
      delete temp;
   }
}

// Push and pop

void Stack::push(Car &d) {
   Node *temp = new Node;
   temp->data = d;
   temp->next = top;
   top = temp;
   size++;
   }
   
string Stack::pop() {
   if (!isEmpty()) {
   string popValue = top->data.carLicense;
   Node *temp = top;
   top = temp->next;
   delete temp;
   size--;
   return popValue;
   }
   else {
   cout << "You can't pop an empty stack" << endl;
   exit(1);
   }
   }
   
Car Stack::peek() {
   Car peekValue;
   if (!isEmpty()) {
   peekValue.carLicense = top->data.carLicense;
   peekValue.numMoves = top->data.numMoves;
   }
   return peekValue;
   }

// isFull and is Empty

bool Stack::isEmpty() {
   if (top == nullptr) {
      return true;
      }
   return false;
   }
   
bool Stack::isFull() {
   if (size == 10) {
      return true;
      }
   return false;
   }
   
// search algorithm
   
void Stack::search(string d) {
   string searchValue = d;
   Node *temp = new Node;
   temp = top;
   
   //cout << "searchValue: " << searchValue << endl;
   
   for (int i = 0; i < size; i++) {
      //cout << "temp = " << temp->data.carLicense << endl;
      if (searchValue == temp->data.carLicense) {
         //cout << "isValid == true" << endl;
         isValid = true;
         return;
         }
      temp = temp->next;
      }
      //cout << "isValid == false" << endl;
      isValid = false;
   }