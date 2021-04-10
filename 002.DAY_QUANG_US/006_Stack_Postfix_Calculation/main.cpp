
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
using namespace std;

bool isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return true;
    else
        return false;
}
int performOperation(int op1, int op2, char op)
{
    int ans;
    switch(op){
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}

int main()
{
    string exp;
    char buffer[15];

    int op1, op2, j, x;

    Stack<int> S;

    getline(cin, exp);

    j = 0;
    for(unsigned int i=0; i<exp.size();i++){
        if(exp[i]>='0' && exp[i]<='9'){
            buffer[j++] = exp[i];
        }
        else if(exp[i]==' '){
            if(j>0){
                buffer[j] = '\0';
                x = atoi(buffer);

                S.push(x);

                j = 0;
            }
        }
        else if(isOperator(exp[i])){
            op1 = S.top(); S.pop();
            op2 = S.top(); S.pop();

            int result = performOperation(op1, op2, exp[i]);
            S.push(result);
        }
    }

    cout << S.top() << endl;

    return 0;
}

/*
26.7 Postfix Calculation
Introduction

In this lab, you will implement a templated stack based on array. With the stack, you are supposed to read a postfix notation, and calculate the result of the postfix notation. No STL library usage is allowed.

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

Computation based on postfix notation

With postfix as input, you are supposed to calculate the result of the postfix notation in the function int compute(string postfixnotation). Each element in postfixnotation is separated by a space.

The calculating algorithm is as below. Maintain an integer Stack. Read in each element of the postfix notation.

If the element is an integer, push it into the integer Stack.
If the element is an operator, pop numbers in the integer stack and compute the result. For instance, a and b is poped out in sequence and the operator is '-', then calculate b-a. Push the result back to the integer stack. You can assume only four operators are involved in the calculation, i.e., '+', '-', '*', '/'.
When the string ends, there should be only one integer in the stack, which is the final result.
Inputs

You can assume only integers are involved and that all notations given are legal.
If division is included, you can safely assume that the result of the division is also an integer.
A brief example input is: "20 18 - 3 *". The result for the input is 6. Regarding the output format: All messages must end on a new line.
*/
