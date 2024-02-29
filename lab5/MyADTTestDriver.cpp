/*
 * MyADTTestDriver.cpp
 * 
 * Class Description: test driver for the friendsbook program.
 * 
 * Class Invariant: 
 *
 * Author: Amytis Saghafi (asa414@sfu.ca)
 * Last modified on: Feb. 2024
 */
/*
The FriendsBook application must allow a user to
1. Join the social network (by creating a profile for the user)
2. Search for a particular profile using the username of the profile
3. Modify a user's profile: modify the name and/or the email address and/or the birthday of theuser,
but not the user's username
4. Leave the social network (by removing the user's profile from the network)
5. Print all the current users in the social network in ascending order of username.
*/

#include <iostream> // As we need to print data
#include <iomanip>  // As we need to set the precision of output
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::cin;
using std::endl;

int main (){
    

//cout << "start here" << endl;

    MyADT friendsBook;
//some profiles to add
    Profile p1 ("abcreally", "Xiao Wong","xw123@coldmail.com","August 2 2003");
    Profile p2 ("ihatethis!", "Louis Pace", "louis@nowhere.com", "May 25 2001");
    Profile p3 ("marieLower","Marie Lower", "marie@somewhere.ca", "July 21 1999");
    Profile p4 ("mrvropdgs56", "Arwinder Singh", "meow@telthem.com", "December 17 1998");

//print empty  book
    //friendsBook.print();


   // insert profiles
    friendsBook.insert(p1);
    cout << p1<< " is inserted "<< endl;
    friendsBook.insert(p2);
    friendsBook.insert(p3);
    friendsBook.insert(p4);


    // Print the number of elements
    cout << "Number of elements: " << friendsBook.getElementCount() << endl;


    // Search for a profile
    Profile target("ihatethis!", "Louis Pace", "louis@nowhere.com", "May 25 2001");

    Profile* result = friendsBook.search(target);

    if (result != nullptr) {
        cout << "Found Profile: " << result->getName() << endl;
    } else {
        cout << "Profile Not found!" << endl;
    }


    // Remove a profile

    cout << "removing " << target << endl;
    friendsBook.remove(target);


    // Print all elements
    friendsBook.print();


    // Remove all elements
    cout<<"removing all users now!" << endl;
    friendsBook.removeAll();


    // Print the number of elements
    cout << "Number of elements: " << friendsBook.getElementCount() << endl;


    return 0;
}