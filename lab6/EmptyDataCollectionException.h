/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    data collection ADT class is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#ifndef EmptyDataCollectionException_H
#define EmptyDataCollectionException_H

#include <stdexcept>
#include <string>

using std::string;
using std::logic_error;

class EmptyDataCollectionException : public logic_error
{
public:
   EmptyDataCollectionException(const string& message = "");
   
}; // end EmptyDataCollectionException
#endif 
