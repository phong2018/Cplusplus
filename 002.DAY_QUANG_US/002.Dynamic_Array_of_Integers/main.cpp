#include <iostream>
#include <string>
using namespace std;

#include "ArrayList.h"
int main()
{
     return 0;
}
/*
26.2 Dynamic Array of Integers
Classes, constructors, and Function overloading

1- Objective

The purpose of this lab is for students to gain a better understanding of object-oriented programming, classes, accessors, method, destructors, and dynamic allocation and Function overloading.

2- Problem

You have to write a class “ArrayList” to store a dynamic array of integers and allow manipulations on that array.

It would have the following private attributes:

int *arr : A pointer that points to the array.

int arraySize : An integer that stores the size of the array. It should be greater or equal to two.

int numOfElements : An integer that tracks how many elements are in the array.

The constructors will be defined as follows:

Default constructor: the default constructor should set the arraySize to 2 and initialize the dynamic array of integers.
    ArrayList();
Constructor : In constructor a valid arraySize (at least 2) should be passed. If any number less than 2 is passed to the constructor, you should set arraySize to 2 by default.
    ArrayList(int arraySize);
For both constructors above, the initial number of elements is set to 0.

Copy Constructor: In the copy constructor, you need to implement Deep Copy, so that all elements of the original ArrayList object are copied in the second object.
    ArrayList( const ArrayList &a)
Overloaded assignment operator (=): the operator will allow to copy an object into another. Remember that the implementation requires a deep copy of the original object.
ArrayList& operator=(const ArrayList& rhs)
The class would also include following public accessor functions and methods:

Accessors:
    int getArraySize() const;

    int getNumOfElements() const;

    int getElementAt(int index) const;
*Hints: The index given to method getElementAt starts from 0. For instance, for array = [1,2,3,4,5], getElementAt(1) should return 2. If the index is invalid, i.e., index is smaller than 0 or larger than numOfElements - 1, the method should return -1.

Add element: this method asks the user to input a number to store into the array, then inserts the number in the array if the number is qualified. To be specific, only non-negative numbers are qualified to be inserted into the array. If a negative number is given as the input, there should be no change in the array and no output. The qualified number should be added at the end of the array. If the array does not have room to add another element, the array should be expanded to 2 times its current size before adding the element.
  void addElement(int num)
Hint: anytime the array size is changed, you should copy the old array elements in a temporary array and de-allocate the old one to prevent memory leaks. Then, resize the original array and fill with elements from temporary copy. Finally, delete temporary copy.

Delete element: this method should ask the user for a number to remove from the array. This function should only delete the first occurrence of the to-be deleted number. If the specified number does not exist inside the array, there should be no change in the array and no output. Anytime an element is deleted from the beginning or middle of the array, all other elements in the array should be shifted over to fill the empty gap. If the number of elements becomes less than or equal to half the size of the array, the array should be shrunk down to half its current size. Refer to the hint above to copy the array into a smaller one without producing memory leaks.
   void deleteElement(int num)
Destructor: finally, a destructor should be included to release all memory that has been allocated for the object.
 ~ArrayList()
Note: In case of any error in input, you don't need to output anything. Either use default values (where it's asked to do so) or ignore that operation/modification for other cases (where there's no default value to set to).

4- Submission guideline

You need to submit three files.ArrayList.cpp, where you will implement the class. ArrayList.h where class declaration will be written and main.cpp.If you encounter an error while submitting, try refreshing your browser to see if your code has been saved in Zybooks (even if it grades a zero for your submission). We won't be able to re-evaluate your code if it's not saved (successfully uploaded) in Zybooks, when you may have a reason to believe that your submission was graded properly. If you figure out that your submission is not saved in Zybooks, please notify your respective TA with a copy of your submission. It doesn't garauntee you a grade, but you would have a proof for submission within deadline.

5- How your code is tested

We will have test benches (small programs), each of which will check a part of your implementation, by creating object(s) of ArrayList class and then call accessor/methods etc to modify the object and match them with expected changes. For example if you start with a ArrayList object of size 2 and add three elements we expect the arraySize should be 4. So if we call getArraySize on that object, the output should be 4.

To help you with testing the correctness of your implementation, five sample test benches are provided below. Expected outputs are provided for each test bench which helps you figure out what is testing in each test bench. You can put following code into a main.cpp and run it to test the functionalities of your class. Submission of this main.cpp, but you must submit a main function (can be empty) for the program to be tested correctly in Zybook.

Sample Main Function

#include "ArrayList.cpp"

int main(){

//***********  addElements Function is Tested  ***********

   ArrayList arrList(1);
   arrList.addElement(1);
   arrList.addElement(2);
   arrList.addElement(3);
   arrList.addElement(4);
   arrList.addElement(5);
   if (arrList.getArraySize() == 8 )
   {
       cout << "Correct Result"<<  endl;
       cout << "array Size after expansion is : 8" << endl<< endl;
   }
   else
   {
       cout << "Your addElement Function is not correct" << endl;
       cout << "Your arraySize after Expansion is : " << arrList.getArraySize() << endl;
       cout << "Expected Output : 8 " <<endl<< endl;
   }
   //*********** Constructor with invalid input  is Tested  ***********
   ArrayList arrList2(0);
   if (arrList2.getArraySize() == 2 )
    {
       cout << "Correct Result" << endl;
       cout << "array Size after given wrong value (less than one) : 1" << endl<< endl;
    }
   else
    {
       cout << "Your constrcutor is not Correct" << endl;
       cout << "The arraySize should be at least One" << endl<<endl;
    }

   //*********** getElementAt Function  is Tested  ***********
   ArrayList arrList4(1);
   arrList4.addElement(1);
   arrList4.addElement(2);
   arrList4.addElement(3);
   int s = arrList4.getElementAt(2);
   int s1 = 3;

   if(s == s1 ){
      cout << "Correct Result" << endl;
      cout << "The element with index 2 is: 3" << endl<< endl;
   }
   else{
      cout << "Result is incorrect " << endl;
      cout << "your function prints:" ;
      cout << s << endl;
      cout << " But, Expected output should be:" << s1 <<endl<<endl;

   }

    //*********** Copy Constructor  is Tested  ***********
   ArrayList arrList5(1);
   arrList5.addElement(10);
   ArrayList arrList6 = arrList5;
   arrList6.addElement(-100);
   arrList6.addElement(1000);
   s1 = arrList5.getElementAt(0);
   int output1 = 10;
   int s2 = arrList6.getElementAt(1);
   int output2 = 1000;
   //if(arrList.getnumOfElements() == 3 && arrList.getarraySize() == 4)
   if (s1==output1 && s2==output2){
        cout << "Correct Result"<< endl;
        cout << "First element of the first array is " << arrList5.getElementAt(0) << endl;
        cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) <<endl<< endl;
    }
   else{
      cout << "Result is incorrect " << endl;
      cout << "First element of the first array is " << arrList5.getElementAt(0) << " and should be: 10" << endl;
      cout << "The second element of the copied array after modification is " << arrList5.getElementAt(1) << " and should be: 1000";


   }

   return 0;


}
*/
