#include<iostream>
#include "Stack.h"
#include <string.h>
using namespace std;

int main()
{
Stack <char> S;
char str[100000];
cin>>str;
int l=strlen(str);
for(int i=0; i < l; i++)
{
    S.push(str[i]);
}
int check = 1;
while(!S.isEmpty())
{
    int v1 = S.top(); S.pop();
    if (!S.isEmpty()){
        int v2 = S.top_end(); S.pop_end();

        if(v1!=v2)
            {
                check = 0;
                break;
        }
    }
}

if(check==1){cout << "Yes, it is palindromic."<<endl;}
else {cout << "No, it is not palindromic."<<endl;}

return 0;
}

/*
25.3 Homework 2 - Palindrome
Introduction In this homework you will implement a palindrome judger based on the Stack. The palindrome judger takes in a string and returns whether it is a palindromic string or not. No STL library usage is allowed.

**Stack ** In this homework, you are supposed to implement a template Stack with a linked list. Struct Node is the basic unit in the linked list and it has the following variable:

T info
Node* next
The class Stack, on the other hand has only one member variable:

Node* stackTop
Following methods are needed for class Stack to work properly:

Stack(): The constructor to initialize the stack.
void push(T input): This method takes in a template type input and stores it in the stack by inserting it on top of the stack.
T top(): This method returns the top element in the stack, or informs the user if the stack is empty.
void pop(): This method pops the top element out from the stack (do not return the element). Remember to test if the stack is empty before trying to pop an element.
bool isEmpty(): This method returns whether the stack is empty or not.
~Stack(): stack destructor.
When possible, use const or the dereferencing operator to optimize the functions in your stack class.

Palindrome Judger

In the main.cpp, take in a string made up of letters, symbols and numbers from the standard input. If the string is palindromic, output "Yes, it is palindromic". Otherwise, output "No, it is not palindromic" to the standard output.

All messages must end on a new line.

Test cases will be run not only on the palindrome judger, but also on the Stack class. If you do not implement the palindrome judger on Stack or you do not implement Stack with linked list, no points can be guaranteed even your program passes all test cases.
*/
