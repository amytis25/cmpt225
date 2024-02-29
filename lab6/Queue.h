/* 
 * Queue.h
 *
 * Description: Array-based implementation of data collection Queue ADT.
 * Class invariants: FIFO or LILO
 * 
 * Inspired from the code in our textbook (Frank M. Carrano and Tim Henry)
 *
 * Date: Last modified: Feb. 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Profile.h"
#include "EmptyDataCollectionException.h"


class Queue {

private:
   constexpr static int CAPACITY = 5; 
   
   Profile elements[CAPACITY]; // Array of queue items
   int front;                 // Index to front of queue
   int back;                  // Index to back of queue
   unsigned int elementCount; // Number of elements currently in the queue
   
public:
   // Constructor
   Queue();
   
   // Copy constructor and destructor supplied by compiler
        
   // Description: Returns "true" is this queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to the "back" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(Profile& newElement);
   
   // Description: Removes the element at the "front" of this queue and 
   //              returns "true" if successful, otherwise "false".
   // Precondition: This queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns a copy of the element at the "front" of this queue, 
   //              but does not remove it.
   // Precondition: This queue is not empty.
   // Postcondition: This queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this queue is empty.
   // Time Efficiency: O(1)
   Profile peek() const;
  
   // For Testing Purposes
   // Description: Prints the content of "this". 
   void print() const;
      
}; // end Queue
#endif
