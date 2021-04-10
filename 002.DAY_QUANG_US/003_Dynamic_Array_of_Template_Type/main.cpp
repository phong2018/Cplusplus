#include "ArrayList.cpp"

int main(){

//***********  addElements Function is Tested  ***********

   ArrayList<int> arrList(1);
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
   ArrayList<int> arrList2(0);
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
   ArrayList<int> arrList4(1);
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
   ArrayList<double> arrList5(1);
   arrList5.addElement(10);
   ArrayList<double> arrList6 = arrList5;
   arrList6.addElement(2.1);
   arrList6.addElement(4.5);
   double d1 = arrList5.getElementAt(0);
   double output1 = 10;
   double d2 = arrList6.getElementAt(1);
   double output2 = 2.1;
   //if(arrList.getnumOfElements() == 3 && arrList.getarraySize() == 4)
   if (d1==output1 && d2==output2){
        cout << "Correct Result"<< endl;
        cout << "First element of the first array is " << arrList5.getElementAt(0) << endl;
        cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) <<endl<< endl;
    }
   else{
      cout << "Result is incorrect " << endl;
      cout << "First element of the first array is " << arrList5.getElementAt(0) << " and should be: 10" << endl;
      cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) << " and should be: 2.1"<<endl<<endl;


   }

   return 0;


}

/*
26.3 Dynamic Array of Template Type
Classes, and templates

1- Objective

The purpose of this lab is for students to gain a better understanding of template classes.

2- Problem You should write a class "ArrayList" to store a dynamic array of a template type and allow manipulations on that array.

In the class, there should be three private member variables:

int arraySize : An integer that stores the size of the array. It should be greater or equal to two.
int numOfElements : An integer that tracks how many elements are in the array.
T* arr: A pointer that points to the array of template type.
You need to implement the following methods, which are public.

ArrayList(): A default constructor. The default constructor should set the arraySize to 2 and initialize the dynamic array of the templated type.
ArrayList(int ArraySize): In constructor a valid arraySize (at least 2) should be passed. If any number less than 2 is passed to the constructor, you should set arraySize to 2 by default. The constructor should also initialize the dynamic array of the templated type based on the arraySize.
ArrayList( const ArrayList &a): In the copy constructor, you need to implement Deep Copy, so that all elements of the original ArrayList object are copied in the second object.
void addElement(T element): This method asks the user to input an element of the templated type and inserts it into the array. If the array does not have room to add another element, the array should be expanded to 2 times its current size before adding the element.
void deleteElement(T element): This method takes in an element of the templated type. This method should only delete the first occurrence of the to-be deleted number. If the specified number does not exist inside the array, there should be no change in the array and no output. Anytime an element is deleted from the beginning or middle of the array, all other elements in the array should be shifted over to fill the empty gap. If the number of elements becomes less than or equal to half the size of the array, the array should be shrunk down to half its current size.
int getArraySize(): This method returns the arraySize.
int getNumOfElements(): This method returns the numOfElements.
T getElementAt(int index): This method takes in an index and returns arr[index]. You can assume the index is always valid.
~ArrayList(): A destructor should be included to release all memory that has been allocated for the object.
Sample Main Function:

#include "ArrayList.cpp"

int main(){

//***********  addElements Function is Tested  ***********

   ArrayList<int> arrList(1);
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
   ArrayList<int> arrList2(0);
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
   ArrayList<int> arrList4(1);
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
   ArrayList<double> arrList5(1);
   arrList5.addElement(10);
   ArrayList<double> arrList6 = arrList5;
   arrList6.addElement(2.1);
   arrList6.addElement(4.5);
   double d1 = arrList5.getElementAt(0);
   double output1 = 10;
   double d2 = arrList6.getElementAt(1);
   double output2 = 2.1;
   //if(arrList.getnumOfElements() == 3 && arrList.getarraySize() == 4)
   if (d1==output1 && d2==output2){
        cout << "Correct Result"<< endl;
        cout << "First element of the first array is " << arrList5.getElementAt(0) << endl;
        cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) <<endl<< endl;
    }
   else{
      cout << "Result is incorrect " << endl;
      cout << "First element of the first array is " << arrList5.getElementAt(0) << " and should be: 10" << endl;
      cout << "The second element of the copied array after modification is " << arrList6.getElementAt(1) << " and should be: 2.1"<<endl<<endl;


   }

   return 0;


}
*/
