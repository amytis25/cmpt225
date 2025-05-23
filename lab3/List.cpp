/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: A data collection List ADT class:
 *                    linked list-based implementation. 
 *                    Its underlying data structure is a 
 *                    singly-headed singly-linked list (SHSL).
 *
 * Creation Date:
 * Author:
 */

#include <string>
#include <iostream>
#include "List.h"

using std::ostream;
using std::cout;
using std::cin;
using std::endl;

// Constructors and Destructors

// Description: Default constructor
List::List(){ }

// Description: Copy constructor creates a new List object as a copy of an existing List object.
List::List(const List& lst){
	elementCount = lst.elementCount;
   //head = lst.head; //shallow copy - you need to fix this!
   
   Node * current = nullptr;
   Node * oldNode = nullptr;
   Node * oldhead = nullptr;
   
   
    if (lst.head == nullptr) {
        return;
    }
    oldhead = lst.head;
    head = new Node (oldhead->data);
    current = head;
    oldNode = oldhead->next;


    while (oldNode != nullptr) {
        current->next = new Node (oldNode->data);
        current = current ->next;
        oldNode = oldNode->next;
    }
    current->next = nullptr;
   }




// Description: Destruct a List object, releasing all heap-allocated memory.
List::~List(){
	// You need to write this!
   Node * current = head;
   Node * toBeRemoved = nullptr;

   while ( current != nullptr ){
      toBeRemoved = current;
      current = current -> next;

      delete [] toBeRemoved;
//      cout << "node removed" << endl; 

   }
	}


/**************************************************************************/
// List Operations
//
// Description: Append an element (newElement) to the list.
// Postcondition: newElement is inserted at the end of the list.
void List::append(int newElement){
	
   Node * newNode = new Node(newElement); //new Node with x
   // We will be able to report when new fails by catching and throwing an exception.

   // Check to see if list is empty
   if (head == nullptr){
      // Make new Node the new head
      head = newNode;
   }else{
      // Move to the end of the list
      Node * current = head;
      while (current->next != nullptr){
         current = current->next;
      }
      current->next = newNode;
   }
   elementCount++;
   return;
}


/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
// Description: Prints the contents of the List from the first to the last element.
void List::printList(){
	Node * current = head;
	
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != nullptr){
		cout << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != nullptr){
			cout << ","; // Print a comma unless at the end of the list
		}
	}
	cout << "}"; // Don't print a newline - it might not be needed.
	return;
}
ostream & operator<<(ostream & os, const List & p){
   Node * current = p.head;
	
	cout << "{"; //Nice format!
	// Traverse the list
	while (current != nullptr){
		os << current -> data; // Print data
		current = current -> next; // Go to next Node
		if (current != nullptr){
			os << ","; // Print a comma unless at the end of the list
		}
	}
	os << "}"; // Don't print a newline - it might not be needed.
	return os;
}
// end of implementation file of List class
