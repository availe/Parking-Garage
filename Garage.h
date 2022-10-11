#include "Stack.h"
#ifndef GARAGE_H
#define GARAGE_H

#include <string>
using namespace std;

class Garage {
   private:
   void display(int displayValue);
/*   Stack lane1;
   Stack lane2;
   Stack street;*/
   string tempLicense;
   int tempMoves;
   
   public:
   Garage();
   ~Garage();
   void isArriving(string getLicense);
   void isDeparting(string getLicense);
   int displayValue;
   Stack lane1;
   Stack lane2;
   Stack street;
   };


#endif