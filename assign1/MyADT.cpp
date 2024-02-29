/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: AL and Amytis Saghafi (asa414@sfu.ca)
 * Last modified on: Feb. 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
 
   /* Put your code here */
      for (unsigned int i = 0; i < MAX_ALPHA; i++) {

      elementCount[i] = 0; //size = 0

      elements[i] = new Profile[MAX_ELEMENTS]; // Array on the heap

   }
   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   /* Put your code here */
      if (rhs.getElementCount() == 0) { // no nothing if copy is empty
      return;
   }
   else {
      //MyADT * newADT = nullptr;
     // newADT= new myADT(*rhs);
      for (unsigned int i = 0; i < MAX_ALPHA; i++) {
         unsigned int elementSum = 0;
         for (unsigned int j = 0; j < MAX_ELEMENTS; j++) {
            if (rhs.elements[i][j].getUserName() != "TBD") {
               elements[i][j] = rhs.elements[i][j];
               elementSum++;
            }
            elementCount[i] = elementSum;
         }
      } 

   }
   
}  

// Overloaded assignment operator - Covered in Lab 4
//MyADT & MyADT::operator=(const MyADT& rhs) {
   // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   /* Put your code here */

//}
 

    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   /* Put your code here */
   removeAll();
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {
   /* Put your code here */
   unsigned int total = 0; 
   for (unsigned int i = 0; i< MAX_ALPHA; i++){
      total = total + elementCount[i];
   }
   return total;

}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
 
   /* Put your code here */
         const unsigned int first = newElement.getSearchKey() - 26; // get first letter

   if (search(newElement) != nullptr) { // check if element exists
      cout << "This user is already in the system!" << endl;
      return false;
   }

   else if (elementCount[first] >= MAX_ELEMENTS) { //check if sub array is full
      cout << "No more space to add users!" << endl;
      return false;
   }

   

   for (unsigned int i = 0; i < elementCount[first]; i++) { // go through each element in sub array until condition is met

      if (i == (elementCount[first] - 1)) { // insert when i = elements i.e. no further elements
         elements[first][i] = newElement; //INSERT
         break;
      }

      if (elements[first][i] > newElement) { // if newElement is in front of array element,

         for (unsigned int j = elementCount[first] - 1; j > i; j--) { // move each element back once starting from the back
            elements[first][j] = elements[first][j - 1];
         }

         elements[first][i] = newElement; // INSERT
         break;
      }
   }
   elementCount[first]++;
   return true;
   }
   


// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */
      const unsigned int first = toBeRemoved.getSearchKey() - 26; // get first letter

   for (unsigned int i = 0; i < MAX_ELEMENTS; i++) { // linear search of sub array
      if (elements[first][i] == toBeRemoved) {
         
         for (unsigned int j = i; j < MAX_ELEMENTS - 1; j++) { // shift all elements
            elements[first][j] = elements[first][j+1];
         }
         elements[first][MAX_ELEMENTS-1] = *new Profile(); // replace with fresh profile
         elementCount[first]--;
         return true;
         break;
      }
      else{
         return false;
         break;} 
   }
return false;

  

} 
   



// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    
    /* Put your code here */
       for (unsigned int i = 0; i < MAX_ALPHA; i++) {
      for (unsigned int j = 0; j < elementCount[i]; j++) {
         elements[i][j] = *new Profile();
      }
      elementCount[i] = 0;
   }

}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    
    /* Put your code here */
       const unsigned int first = target.getSearchKey() - 26; // get first letter

   for (unsigned int i = 0; i < MAX_ELEMENTS; i++) { // linear search of sub array
      if (elements[first][i] == target) {
         return &elements[first][i];
      }
   }

   return nullptr;

}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
  
    /* Put your code here */  
       if (getElementCount() == 0) { //check if array is empty
      cout << "There are no users!" << endl;
      return;
   }

   for (unsigned int i = 0; i < MAX_ALPHA; i++) { // print every element of sub array in order
      for (unsigned int j = 0; j < elementCount[i]; j++) {
         cout << elements[i][j];
      }
   }

} 

//  End of implementation file