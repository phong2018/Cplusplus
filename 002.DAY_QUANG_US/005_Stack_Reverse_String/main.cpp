#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;


string reverseString(string input)
{
   Stack<string> s;
   int index = input.find(' ');
   while (index!= -1)
   {
      s.push(input.substr(0, index));
      input = input.substr(index+1,string::npos);
      index = input.find(' ');
   }
   s.push(input.substr(0,string::npos));
   string output;
   while(!s.isEmpty())
   {
      if(output!="")
         output += " ";
      output += s.top();
      s.pop();
   }
   return output;
}
int main()
{
string input;
getline(cin, input);
cout << reverseString(input) << endl;
}
/*
26.6 Reverse String
Introduction

In this lab, you will implement a template stack based on array. With the stack, you are supposed to read a string and reverse the string word by word.

Stack

In this homework, you are supposed to implement the template Stack with a dynamic array. You can assume a default array size equal to 100.

The class Stack has following member variables.

T *list; //pointer to dynamic array
int stackTop;
int maxStackSize; //total size of the array (default value 100)
Following methods are needed for class Stack to work properly:

Stack(): The constructor to initialize the stack. Make this a constructor with a default parameter n = 100.
void push(T input): This method takes in a template type input and stores it in the stack by inserting it at the end of the array. Remember to check for room in stack before trying to push a new element.
T top(): This method returns the top element in the stack, or informs the user if the stack is empty.
void pop(): This method pops the top element out from the stack. Remember to test if the stack is empty before trying to pop an element.
bool isEmpty(): This method returns whether the stack is empty or not.
~Stack(): The destructor that deallocates the dynamic array.
When possible, use const or the dereferencing operator to optimize the functions in your stack class.

Reverse the string: complete the function string reverseString(string input), so that it uses a stack object to reverse the string given words by words. Each word is separated by a space. For instance, when given "Hello World, C++", the result should be "C++ World, Hello".

All messages must end on a new line.

Test cases will be run not only on the reverseString function, but also on the Stack class.
*/
