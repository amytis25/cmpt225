/*
 * test.cpp
 *
 * Description: Driver program for testing our List ADT class.
 *              More specifically, for testing linked list copy and destructor.
 *
 * Creation Date:
 * Author:
 */
#include <iostream>
using std::cout; 
using std::endl; 
using namespace std;

#include "List.h"

void listTest();

int main () {

  listTest();
   
  return 0;
}
void listTest(){

   List * ls1 = nullptr;
   ls1 = new List(); 
   /* Test Case */
   cout << "Appending 1,2,3 to the first List object." << endl;
   ls1->append(1);
   ls1->append(2);
   ls1->append(3);
   cout << endl << "Printing the first List object." << endl;
   //ls1->printList();
   cout << *ls1 << endl;
   cout << endl << "Does it contain {1,2,3}?" << endl;
	
   //cout << endl << "Make a shallow copy of the List object." << endl;
   //shallow copy
   //cout << "making a shallow copy"<< endl;
   List * ls2 = nullptr;
   ls2 = ls1;

//cout << "shallow copy made"<< endl;


//cout << endl << "Make a deep copy of the List object." << endl;
//deep copy
//cout << "Making a deep copy"<< endl;
   List * ls3 = nullptr;
   ls3 = new List(*ls1);
//cout << "A deep copy made"<< endl;


   //cout << endl << "Print second List object." << endl;
   //ls2->printList();
  
   //cout << endl << "Does it contain {1,2,3}?" << endl;
	
   cout << endl << "Append 4,5,6 to the first List object." << endl;
   ls1->append(4);
   ls1->append(5);
   ls1->append(6);
   cout << endl << "Print first List object." << endl;
   //ls1->printList();
   cout << *ls1 << endl;
   cout << endl << "Does it contain {1,2,3,4,5,6}?" << endl;
	
   cout << endl << "Print second List object: (Shallow Copy)." << endl;
   //cout << "shallow copy printing" << endl;
   //ls2->printList();
   cout << *ls2 << endl << endl;


   cout << endl << "Print third List object: (Deep Copy)." << endl;
   //cout << "deep copy printing" << endl;
   //ls3->printList();
   cout << *ls3 << endl;
   cout << endl << "If it was shallow copied, it should contain: {1,2,3,4,5,6}.";
   cout << endl << "If it was deep copied, it should contain: {1,2,3}." << endl;	
   cout << endl;
	
   //destructors
   
  ls1 -> ~List();
  //ls2 -> ~List();
  //ls3 -> ~List();

   return;
}
