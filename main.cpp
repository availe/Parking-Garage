#include<iostream>
#include"Garage.h"
#include <fstream>

using namespace std;

int main(){
   // set up program
   Garage *garage = new Garage();
   fstream inFile;
   string fileName;
   cin >> fileName;
   inFile.open(fileName);
   if (!inFile.is_open()) {
      cout << "file is notopen" << endl;   
      return 0;
   }
   
   // program starts here
   
   string getLicense;
   while(getline(inFile, getLicense)) {
      if (getLicense[0] == 'A') {
         garage->isArriving(getLicense);
         }
      else {
         garage->isDeparting(getLicense);
      }
   }
   
   return 0;   
}