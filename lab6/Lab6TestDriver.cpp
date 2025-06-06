/*
 * Lab6TestDriver.cpp - Lab 6
 * 
 * Class Description: Test Driver for our Lab 6
 *
 * Modified on: Feb. 2024
 * Author: AL
 */

#include <iostream>
#include <sstream>
#include "Queue.h"
#include "Profile.h"
#include "EmptyDataCollectionException.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;



int main () { 

  // Create an empty Queue
  Queue* aQueue = new Queue();
  string theUserName = "";
  string theName = "";
  string theEmail = "";
  string theBirthday = "";


  cout << "\nTest Driver - Start" << endl << endl;

  cout << endl;
  Profile peekedProfile;
try {
  cout << "Peeking before enqueuing:" << endl;
  peekedProfile = aQueue->peek();
  cout << "Now, let's have a look at the peeked Profile:" << endl;
  cout << peekedProfile << endl;
}
catch (EmptyDataCollectionException& anException) {
  cout << "peek() unsuccessful because " << anException.what() << endl;
  // Place recovery code here!
}
cout << endl;   
  while( not cin.eof() ) {   // while (there is data to be read from cin)   
    getline(cin >> ws, theUserName);	  
    getline(cin >> ws, theName);
    getline(cin >> ws, theEmail);
    getline(cin >> ws, theBirthday);      
    
	// For testing purposes:
	// cout << "\n***Read: " << theUserName << ", " << theName << ", " <<  theEmail << ", " <<  theBirthday << endl; 

    Profile newProfile(theUserName, theName, theEmail, theBirthday);
    if ( !aQueue->enqueue(newProfile) )  return 1;
  }
 
  aQueue->print();

  try {
  cout << "Peeking after enqueuing:" << endl;
  peekedProfile = aQueue->peek();
  cout << "Now, let's have a look at the peeked Profile:" << endl;
  cout << peekedProfile << endl;
}
catch (EmptyDataCollectionException& anException) {
  cout << "peek() unsuccessful because " << anException.what() << endl;
  // Place recovery code here!
}
  
  cout << "Test Driver - End" << endl << endl;
  
  delete aQueue;
  aQueue = nullptr;
  
  return 0;
}
