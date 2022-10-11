#ifndef STACK_H
#define STACK_H

#include <string>
using namespace std;

struct Car {
   string carLicense;
   int numMoves = 0;
   };
   
struct Node {
   Car data;
   Node *next;
   };
   
class Stack {
   private:
   int size = 0;
   
   public:
   Node* top;
   Stack();
   ~Stack();
   void push(Car &d);
   string pop();
   Car peek();
   void search(string d);
   bool isEmpty();
   bool isFull();
   bool isValid;
   };
   
   
#endif