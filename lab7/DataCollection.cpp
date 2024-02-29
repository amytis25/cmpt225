/* 
 * DataCollection.cpp
 *
 * Description: Implementation of a SHSL list-based DataCollection ADT class.
 * There are no class invariant!
 *
 * Author: AL
 * Date: Feb. 2024
 */

#include <iostream>
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;
	  

// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){

}

// Description: Copy constructor creates a new DataCollection object as a 
//              copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){

   head = nullptr;

   if (DC.head != nullptr){
      Node *current = DC.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

// Description: Destroys a DataCollection object, releasing heap memory.
DataCollection::~DataCollection(){

   Node * temp = nullptr;
   for ( Node * toBeDeleted = head; toBeDeleted != nullptr; ) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends "newElement" to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){

   // Put your code here!

   return;
}

// Description: Prepends "newElement" to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   
   // Put your code here!

   return;
}

// Description: Prints the content of this DataCollection "thisDC"
//              using this format: {element1, element2, ..., elementn}.
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; 
   while (current != nullptr){
      cout << current -> data; 
      current = current -> next; 
      if (current != nullptr){
         cout << ","; 
      }
   }
   cout << "}";

   return os;

} 
