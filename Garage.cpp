#include"Garage.h"
#include<iostream>
using namespace std;

// constructor and deconstructor

Garage::Garage() {
   }
   
Garage::~Garage() {
   /*delete Stack lane1;
   delete lane2;
   delete street;*/
   }

// isArriving and isDeparting

void Garage::isArriving(string getLicense) {
   Car car;
   tempLicense = getLicense.erase(0, 2);
   car.carLicense = tempLicense;
   //cout << "carLicense = " << car.carLicense << endl;
   if (!lane1.isFull()) {
      lane1.push(car);
      displayValue = 0;
      display(displayValue);
      return;
      }
   if (lane1.isFull() && !lane2.isFull()) {
      lane2.push(car);
      displayValue = 1;
      display(displayValue);
      return;
      }
   if (lane1.isFull() && lane2.isFull()) {
      displayValue = 2;
      display(displayValue);
      }
   }
   
void Garage::isDeparting(string getLicense) {
   tempLicense = getLicense.erase(0, 2);
   Car car;
   int counter = 0;
   
   //cout << "lane1.search ";
   lane1.search(tempLicense);
   //cout << "lane2.search ";
   lane2.search(tempLicense);

// If car is not in lane1 or lane2

   if (lane1.isValid == false && lane2.isValid == false) {
      displayValue = 3;
      display(displayValue);
      return;
      }      
// If car is departing from lane1

   if (lane1.isValid == true && lane2.isValid == false) {
      //cout << "Depart from lane1: " << tempLicense << endl;   
      while (lane1.peek().carLicense != tempLicense) {
         car = lane1.peek();
         car.numMoves++;
         //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
         if (!lane2.isFull()) {
            lane2.push(car);
            //cout << "lane2.push() = " << lane2.peek().carLicense << endl;
            }
         else {
            street.push(car);
            //cout << "street.push() = " << street.peek().carLicense << endl;
            }
         lane1.pop();
         counter++;
         }
         
      //cout << "lane1 pop: " << lane1.pop() << endl;
      tempMoves = lane1.peek().numMoves;
      lane1.pop();
      //cout << "lane1 seek: " << lane1.peek().carLicense << endl;
      
      for (int i = 0; i < counter; i++) {
         if (!street.isEmpty()) {
            car = street.peek();
            car.numMoves++;
            //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
            lane1.push(car);
            street.pop();
            }
         else {
            car = lane2.peek();
            car.numMoves++;
            //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
            lane1.push(car);
            lane2.pop();
            }
         }
         
      displayValue = 4;
      display(displayValue);
      return;
      }
      
   // If car is departing from lane2
   
   if (lane1.isValid == false && lane2.isValid == true) {
      
      while (lane2.peek().carLicense != tempLicense) {
         car = lane2.peek();
         car.numMoves++;
         //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
         if (!lane1.isFull()) {
            lane1.push(car);
            }
         else {
            street.push(car);
            }
         lane2.pop();
         counter++;
         }
         
      //cout << "lane1 pop: " << lane1.pop() << endl;
      tempMoves = lane2.peek().numMoves;
      lane2.pop();
      //cout << "lane1 seek: " << lane1.peek().carLicense << endl;
      
      for (int i = 0; i < counter; i++) {
         
         if (!street.isEmpty()) {
            car = street.peek();
            car.numMoves++;
            //tempMoves = car.numMoves;
            //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
            lane2.push(car);
            //cout << "lane2.push() = " << lane2.peek().carLicense << endl;
            street.pop();
            }
         else {
            car = lane1.peek();
            car.numMoves++;
            //tempMoves = car.numMoves;
            //cout << car.carLicense << " numMoves: " << car.numMoves << endl;
            lane2.push(car);
            //cout << "street.push() = " << street.peek().carLicense << endl;
            lane1.pop();
            }
         }

      displayValue = 5;
      display(displayValue);
      }
   }

void Garage::display(int displayValue) {
   
   switch(displayValue) {
      case 0: cout << "The car " << lane1.peek().carLicense << " is arriving into the Lane1" << endl;
      break;
      case 1: cout << "The car " << lane2.peek().carLicense << " is arriving into the Lane2" << endl;
      break;
      case 2: cout << "Garage is full!" << endl;
      break;
      case 3: cout << "Wrong garage. Your car " << tempLicense << " is not here." << endl;
      break;
      case 4: cout << "The car " << tempLicense << " is departing. It was moved " << tempMoves << " times." << endl;
      break;
      case 5: cout << "The car " << tempLicense << " is departing. It was moved " << tempMoves << " times." << endl;
      break;
   }

}