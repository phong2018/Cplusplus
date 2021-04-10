#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

template<class T>
class Stack
{
   private:
      T *list; //pointer to dynamic array
   int stackTop;
   int maxStackSize; //total size of the array (default value 100)

   public:
      Stack(int = 100);

      void push(const T &input);
      T& top() const;
      void pop();
      bool isEmpty() const;
      ~Stack();
};
#endif

template<class T>
Stack<T>::Stack(int n)
{
   maxStackSize = n;

   if(maxStackSize < 0)

      maxStackSize = 100;

   stackTop = 0;
   list = new T[maxStackSize];

}


template<class T>
void Stack<T>::push(const T &input)
{
   if (stackTop == maxStackSize) {cout << "Stack is full" << endl;}
   else
   {
      list[stackTop++] = input;
   }
}



template<class T>
void Stack<T>::pop()
{
   if (stackTop == 0)
   {
      cout << "Can't pop from empty stack";
   }
   else
   {
      stackTop--;
   }
}

template<class T>
bool Stack<T>::isEmpty() const
{
   return stackTop == 0;
}

template<class T>
T& Stack<T>::top() const
{

         return list[stackTop-1];
}


template<class T>
Stack<T>::~Stack() { delete[] list;}


