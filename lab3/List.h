/*
 * List.h - Header of the List class
 *
 * Class Description: A data collection List ADT class:
 *                    linked list-based implementation. 
 *                    Its underlying data structure is a 
 *                    singly-headed singly-linked list (SHSL).
 *
 * Creation Date:
 * Author:
 */
 
#ifndef LIST_H
#define LIST_H

#include "Node.h"
using std::ostream;
class List{

private:

	Node * head = nullptr;          // Pointer to the linked list. 
	unsigned int elementCount = 0;  // Number of elements currently stored in the list.

public:

	// Constructors and Destructors

	/* Generally, if a class makes use of dynamic memory allocation,
	 * we should provide at least two constructors: a default constructor and
	 * a copy constructor that creates a deep copy of the given object.
	 */	 
	 
	// Description: Default constructor
	List();


	/* Note that the compiler will generate a copy constructor automatically.
	 * However, this constructor only creates a SHALLOW COPY. This signifies that
	 * it would only copy the content of elementCount (a number) and 
	 * the content of head (a memory address). In this case, this would not create a
	 * complete new List object, as both List objects would be pointing to the same linked list
     * i.e., the head of both List objects would contain the same memory address.
	 * It is therefore necessary to write a constructor that makes a DEEP COPY
	 * if our List class makes use of dynamically allocated memory so that both List objects
	 * are different, each of their head pointing to a different linked list.
	 */

	/* Also note the parameter. C++ functions use pass-by-value by
	 * default. This means that the functions make copies of the given
	 * arguments. This is inefficient (particularly for large objects).
	 * Therefore it is normal to pass a reference, (using '&') to the parameter.
	 */
	// Description: Copy constructor creates a new List object as a copy of an existing List object.
	List(const List& lst); //copy constructor


	/* The destructor is responsible for deleting any memory that was dynamically
	 * allocated to an object. If there is no such memory, no destructor needs to
	 * be created (the compiler automatically creates one for the class). Because this 
	 * List class uses memory dynamically allocated when new elements are
     * inserted into the List (Node object and maybe an object representing the element),
     * it is necessary to write a destructor.
     * Destructors are identified by the '~' preceding the class name.
	 * There can be only one destructor for a class, and it cannot have parameters.
	 */
	 // Description: Destruct a List object, releasing all heap-allocated memory.
	~List();//destructor


	/**************************************************************************/
	// List Operations
	//
	// Description: Append an element (newElement) to the list.
	// Postcondition: newElement is inserted at the end of the list.
	void append(int newElement);


	/*
	 * Note that there is some debate about whether or not this type of
	 * method belongs in a class. The argument (briefly) is that a class
	 * shouldn't be responsible for I/O by "displaying" itself as it cannot
	 * foresee how it is to be displayed (in a TUI or GUI environment).
	 * However, such method eases testing.
	 * For testing purpose, unless required by client in problem statement.
	 * Could also overload operator<<.
	 */
	 // Description: Prints the contents of the List from the first to the 
	 //              last element, along with the content of elementCount.
	 void printList();

	// Description: Prints the content of this list
    friend ostream & operator<<(ostream & os, const List & p);

}; // end of header file of List class
#endif
