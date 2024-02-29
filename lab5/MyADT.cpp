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
 * Author: AL
 * Last modified on: Jan. 2024
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
 
   for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
      elements[index] = nullptr;
      elementCount[index] = 0; 
   }
}  


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
      elements[index] = nullptr;
      elementCount[index] = rhs.elementCount[index];
       
      // Deep copy the elements
      if (rhs.elements[index] != nullptr && rhs.elementCount[index] >  0) {
         // elements[index] = new Profile[capacity[index]];
         elements[index] = new Profile[MyADT::MAX_ELEMENTS];
         for (unsigned int element = 0; element < elementCount[index]; element++) {
            elements[index][element] = rhs.elements[index][element];
         }
      }
   }
}  

// Overloaded assignment operator - Covered in Lab 5
MyADT & MyADT::operator=(const MyADT& rhs) {
   cout << "Overloaded assignment = operator executed!" << endl; // For testing purposes ... 
   // You can also use the above to figure out when this overloaded assignment = operator is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
   
   if (this != &rhs) { // protect against invalid self-assignment
      for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
         elements[index] = nullptr;
         elementCount[index] = rhs.elementCount[index];
         
         // Deep copy the elements
         if (rhs.elements[index] != nullptr && rhs.elementCount[index] >  0) {
            elements[index] = new Profile[MyADT::MAX_ELEMENTS];
            for (unsigned int element = 0; element < elementCount[index]; element++) {
               elements[index][element] = rhs.elements[index][element];
            }
         }
      }
   }

   return *this;
}
    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   // Delete all dynamically allocated memory
   deleteAll();
}  


// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {
   unsigned int total = 0;

   for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) 
      total += elementCount[index]; 
   
   return total;
}


// Description: Inserts an element in the data collection in MyADT.
// Precondition: newElement must not already be in the data collection in MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {
   bool ableToInsert = false;
   bool done = false;
   int index = -1;
    
   // Get index of array in which newElement may be found.
   index = newElement.getSearchKey() - 'a';
             
   // Initially, if array for this letter does not yet exist, get an array
   if ( elements[index] == nullptr && elementCount[index] ==  0) {
      elements[index] = new Profile[MyADT::MAX_ELEMENTS];
      if ( elements[index] != nullptr ) {                       
         // Insert newElement into correct element array based on first letter of name
         elements[index][elementCount[index]] = newElement;
         // Increment elementCount for that element array
         elementCount[index]++;		       
         // Report success
         ableToInsert = true;
      }
      // else done already set to false -  exit
   }
   // If this array already exists, does it have room for newElement?
   else {
      // If not full
      if ( elementCount[index] < MyADT::MAX_ELEMENTS ) {
      // Go through the array
         for (unsigned int each = 0; each < elementCount[index] && !done; each++) {				
            // If newElement is already there, we are done!				
            if ( elements[index][each] == newElement ) {
               done = true;
               // ableToInsert still false;
            }
            else {
               if ( elements[index][each] > newElement ) { // shift and insert			   
                  unsigned int shift = elementCount[index];
                  for (; shift > each; shift--) {
                     // shift elements to the right
                     elements[index][shift] = elements[index][shift-1];	
                  }
                  // insert
                  elements[index][shift] = newElement;
                  // Report success 
                  ableToInsert = true;
                  // break the loop
                  done = true;		
                  // Increment elementCount for that element array
                  elementCount[index]++;			  
               }              
               // else { go to next element -> elements[index][each] 				   
            } 
         } // for loop
         // if ( elements[index][each] < newElement ) { // continue checking	
         // insert at the end of array
         if (!done) {
            elements[index][elementCount[index]] = newElement;		                
            // Increment elementCount for that element array
            elementCount[index]++;		
            // Report success
            ableToInsert = true;				
         }        
      }
      // else - array FULL - ableToInsert already set to false
   } // end of else   
   return ableToInsert;
}  

// Description: Removes an element from the data collection in MyADT. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull, otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {
   bool done = false;
   int index = -1;

   // Get index of array in which toBeRemoved may be found.
   index = toBeRemoved.getSearchKey() - 'a';
        
   // Make sure array for this letter exists
   if ( elements[index] != nullptr && elementCount[index] >  0) {

      for ( unsigned int each = 0; each < elementCount[index] && !done; each++) {
         if ( elements[index][each] == toBeRemoved ) {
            for ( unsigned int shift = each+1; shift < elementCount[index]; shift++ ) {
               // Shift elements left in order to overwrite toBeRemoved
               elements[index][each] = elements[index][shift];
               each = shift;
            }
            done = true;
            // Decrement element count    
            elementCount[index]--;
         }        
      }
   }     
              
   return done;
}  


// Description: Removes all elements from the data collection in MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed).
void MyADT::removeAll() {
   
   // Reset the data collection as it was when it was initially constructed
   deleteAll();      

}  

// Utility method
// Description: Deletes all dynamically allocated memory.
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed).
void MyADT::deleteAll() {    

   // Delete each array of elements associated with a letter ...
   for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
      if ( elements[index] != nullptr ) {
         delete [] elements[index];
         elements[index] = nullptr;
      }
      
      // and set its corresponding element count to 0 ...
      elementCount[index] = 0;
   }
}  


// Description: Searches for target element.
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
   Profile* result = nullptr;
   bool found = false;
   int index = -1;

   // Get index of array in which target may be found.
   index = target.getSearchKey() - 'a';
	
   // Go directly to array of elements with same first letter as target's and ...
   if ( elements[index] != nullptr && elementCount[index] > 0 ) {
      for (unsigned int eachMember = 0; eachMember < elementCount[index] && !found; eachMember++) {
        
         // ... search for target - see Profile class overloaded operator ==
         if ( elements[index][eachMember] == target ) {
            result = &elements[index][eachMember];
            found = true;
         }
      }
   }

   return result; 
} 


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {
   // int totalOfMembers = getElementCount(); 
   // cout << "\nCurrent count of elements: " << totalOfMembers << endl; // For testing purposes

   for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
      if ( elements[index] != nullptr && elementCount[index] > 0 ) {
         for (unsigned int eachMember = 0; eachMember < elementCount[index]; eachMember++) {
            // cout << "elements[" << index << "][" << eachMember << "]: ";  // For testing purposes
            cout << elements[index][eachMember];
         }
      }
   }   

} 

// Description: Prints the content of "this" as follows:
//              <userName>, <name>, <email>, <birthday>
ostream & operator<<(ostream & os, const MyADT & p) {

      for (unsigned int index = 0; index < MyADT::MAX_ALPHA; index++) {
      if ( p.elements[index] != nullptr && p.elementCount[index] > 0 ) {
         for (unsigned int eachMember = 0; eachMember < p.elementCount[index]; eachMember++) {
            // cout << "elements[" << index << "][" << eachMember << "]: ";  // For testing purposes
            os << p.elements[index][eachMember];
         }
      }
   } 

    //os << p.userName << ", " << p.name << ", " << p.email << ", " << p.birthday << endl;
    return os;
}

//  End of implementation file
