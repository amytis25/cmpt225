/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *              
 * Author: Amytis Saghafi (asa414@sfu.ca)
 * Date of last modification: Feb. 2024
 */

#include "Dictionary.h"

 // Constructor and destructor:
   Dictionary();                             // Default constructor
   ~Dictionary();                            // Destructor 
   
   // Dictionary operations
      
   // Description: Returns the number of elements currently stored in the Dictionary.
   // Postcondition: This method does not change the Dictionary.
   unsigned int getElementCount() const;
    
   // Description: Puts "newElement" (association of key-value) into the Dictionary.
   // Precondition: "newElement" does not already exist in the Dictionary.
   //               This is to say: no duplication allowed.
   // Exception: Throws the exception "UnableToInsertException" 
   //            when newElement cannot be inserted in the Dictionary.  
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the Dictionary.  
   void put(WordPair & newElement);
 
   // Description: Gets "newElement" (i.e., the associated value of a given key) 
   //              from the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception ElementDoesNotExistException
   //            if the key is not found in the Dictionary.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   // Postcondition: This method does not change the Dictionary.
   WordPair & get(WordPair & targetElement) const;

   // Description: Prints the content of the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   // Postcondition: This method does not change the Dictionary.
   void displayContent(void visit(WordPair &)) const;
   
}; // end Dictionary