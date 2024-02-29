/*
 * sum_array.cpp
 * 
 * Class Description: a program which stores a number of integers (decided by user)
 * and sums it up.
 *       
 * Class Invariant: size of array               
 *
 * Author: Amytis Saghafi, asa414@sfu.ca
 * Last modified: Jan. 2024
 */
/*
1. Prompt the user to enter the total number of values to be summed.
2. Create a dynamically allocated array of this size.
3. Prompt the user to enter each integer value, one at a time, read the value and store it into the array until the array is full.
4. Sum these values and print this sum. The section Implementation Requirements
below willexpand on this step.
5. Delete the dynamically allocated array before terminating the program.
Careful here! Make sure you know the difference between the delete[ ]
operator and the delete operator.
6. Have the main() function return the sum of the values.
*/
#include <iostream>
using namespace std;


int sumArray(int arr[], unsigned int arrSize);
void inputArray(int arr[], unsigned int arrsize);

int main(){
int * arr = nullptr;
unsigned int arraySize = 0;
unsigned int sumOfArray = 0; 
cout << "Enter the number of integers to be summed: ";
cin >> arraySize;
arr = new int [arraySize];
cout << "Enter " << arraySize <<"integers: ";


inputArray( &arr[arraySize] , arraySize);
sumOfArray = sumArray ( &arr[arraySize], arraySize);
cout << "the sum of the integers in the array is " << sumOfArray << "." << endl;

return sumOfArray;


}

void inputArray(int arr[], unsigned int arrsize){
for (unsigned int i= 0; i<arrsize; i++){
    cin >> arr[i];
    }
}

int sumArray(int arr[], unsigned int arrSize){
   unsigned int sum = 0;
   for (unsigned int i= 0; i<arrSize; i++){
    sum = sum + arr[i];
    } 
    return sum; 
}