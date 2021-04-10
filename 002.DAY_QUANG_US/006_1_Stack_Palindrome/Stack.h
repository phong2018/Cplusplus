#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;


template <class T>
struct Node{
    T info;
    Node* next;
};
template <class T>
class Stack{
public:
    Node<T> *stackTop;//head
    Stack()
    {
        stackTop = NULL;
    }

    void push(T input)
    {
        Node<T> *temp =  new Node<T>;
        temp->info = input;
        temp->next= NULL;
        if (stackTop == NULL)
        {
            stackTop = temp;
        }
        else {
            temp->next = stackTop;
            stackTop = temp;
        }
    }
    T top()
    {
        return stackTop->info;
    }

    void pop()
    {
        Node<T> *temp;
        temp = stackTop;
        stackTop=stackTop->next;
        delete temp;
    }

    T top_end()
    {
        Node<T> *p;
        p = stackTop;
        while(p->next!=NULL){
            p=p->next;
        }
        return p->info;
    }

    void pop_end()
    {
        Node<T> *p;
        p = stackTop;

        if(p->next==NULL){
            stackTop=NULL;
            delete p;
        }
        else{// X Y Z
            while(p->next->next!=NULL){
                p=p->next;
            }
            Node<T> *pp;
            pp=p->next;
            delete pp;

            p->next=NULL;
        }
    }

    bool isEmpty()
    {
        if(stackTop == NULL){return true;}
        else {return false;}
    }

    ~Stack(){stackTop = NULL;}
};

#endif
