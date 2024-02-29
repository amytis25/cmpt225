/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Amytis Saghafi (asa414@sfu.ca)
 * Date: Feb. 2024
 */

 #include <iostream> 
 #include "Stack.h"

 using std::cout;
 using std::cin;
 using std::endl;


    Stack::Stack (){
      top = nullptr;
    }
    
    // copy constructor
    Stack::Stack (const Stack& old){
     // elementCount = old.elementCount;
       // elements = old.elements;
      
      
      
    }

    //Destructor
    Stack::~Stack (){
      //elementCount = old.elementCount;
      
        while (top != nullptr){
                StackNode * temp ;

      temp = top;
      top = top ->next;
        

        elementCount--;
        delete [] temp;
        }
        
      
    }
    
    //pre-codition:
    //post-condtion:
    //description: Checks to see if stack is empty, returns true if it is empt
    // returns false if stack has content
    bool Stack::isEmpty (){
      
      if (elementCount == 0){
         return true;
      } else {
         return false;
      }
    }


    //pre-codition: -
    //post-condtion: the integer toBeAdded is added to the top of the stack
    //description: Pushes all elements back and puts element at the top
    bool Stack::push (int toBeAdded){
    StackNode * nodeToAdd = nullptr;
    nodeToAdd = new StackNode(toBeAdded);
     if (top == nullptr){
      
      nodeToAdd -> data = toBeAdded;
      top = nodeToAdd;
     } 
    
        
        else {
         StackNode * current = nullptr;
         StackNode * temp = nullptr;
         current = top ;
          while (current!=nullptr){
            temp = current;
            current = current -> next;
            //cout << current;
          }
         nodeToAdd ->  data = toBeAdded;
         temp -> next = nodeToAdd;
         current = nodeToAdd;
     
         //temp -> next = top;
         //top = toBeAdded; 
        }
        //cout << "pushing" <<current -> data;
        elementCount++;
        return true;

      
    }


    //pre-codition: stack is not empty
    //post-condtion: top element is removed and all elements are moved up
    //description: removes the top element of the stack shifting all other elements up
    bool Stack::pop (){
      StackNode * temp = nullptr;
      StackNode * current = nullptr;
      StackNode * before = nullptr;
        current = top ;
      if (isEmpty()== true) {

            cout <<("Cannot pop from an empty stack");
            return false;

        } else {

        while (current!=nullptr){
            //temp = current;
            before = temp;
            temp = current -> next;
            if (temp == nullptr){
              current = nullptr;
              delete [] current;
              break;
            } else {
              current = temp -> next;
              
            }

          }
      
        }
        //cout << "popping "<< temp -> data << endl;
        before -> next = nullptr;
      
      //current = current ->next;
        

        elementCount--;
        
        delete [] temp;
         return true;
    }
    

    //pre-codition: stack is not empty
    //post-condtion: -
    //description: accesses the top element of the stack
    int Stack::peek (){
      StackNode * current = nullptr;
      StackNode * before = nullptr;
      current = top ;
      if (isEmpty()== true) {

            cout<<("Cannot peek at an empty stack");
            return 0; 
        }
        else {
          
          while (current!=nullptr){
            before = current ;
            current = current -> next;

            }
            
             cout << "peek shows " <<before -> data <<endl;;
            return before->data;
          }



        //cout << "peek shows" <<before -> data;
        //return before -> data;
        
    }