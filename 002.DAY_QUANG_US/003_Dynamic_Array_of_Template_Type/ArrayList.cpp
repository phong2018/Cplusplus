#include <iostream>
#include <string>

using namespace std;

#include "ArrayList.h"

template<class T>
int ArrayList<T>::getArraySize() const{
        return arraySize;
    }

template<class T>
int ArrayList<T>::getNumOfElements() const {
    return numOfElements;
}

template<class T>
ArrayList<T>::ArrayList() {
   arraySize = 2;
   numOfElements = 0;
   arr = new T[arraySize];
}

template<class T>
ArrayList<T>::ArrayList(int ArraySize) {

    if (ArraySize < 2){
        arraySize = 2;
        numOfElements = 0;
    }

    else {
        arraySize =ArraySize;
        numOfElements = 0;
    }
    arr = new T[arraySize];
}

template<class T>
ArrayList<T>::ArrayList(const ArrayList &r){
    numOfElements = r.numOfElements;
    arraySize = r.arraySize;
    arr = new T[r.arraySize];
    for (int i = 0; i < numOfElements; i++) {
        arr[i] = r.arr[i];
    }
}

template<class T>
T ArrayList<T>::getElementAt(int index) const {
        return arr[index];
}

template<class T>
void ArrayList<T>::addElement(T element){

    if(numOfElements >= arraySize)
    {
        T *newArr = new T[arraySize * 2];

        for(int i = 0; i < arraySize; i++)
        {
            newArr[i] = arr[i];
        }

        delete []arr;
        arr = newArr;
        newArr = NULL;

        arr[numOfElements] = element;
        numOfElements++;
        arraySize *= 2;
    }
    else
    {
        arr[numOfElements] = element;
        numOfElements++;
    }

}

template<class T>
void ArrayList<T>::deleteElement(T element){
    bool isFound = false;

    for(int i = 0; i < numOfElements; i++)
    {

        if(arr[i] == element && i <numOfElements - 1)
        {

            isFound = true;
            arr[i] = arr[i + 1];
            arr[i + 1] = element;
        }
        if (arr[i] == element && i == numOfElements - 1)
        {
            isFound = true;

        }
    }

    if(isFound)
    {
        numOfElements--;

        if(numOfElements <= arraySize / 2)
        {
            T *newArr = new T[arraySize / 2];
            for(int i = 0; i < numOfElements; i++)
            {
                newArr[i] = arr[i];
            }

            delete []arr;
            arr = newArr;
            newArr = NULL;

            arraySize = arraySize / 2;
        }
    }


}

template<class T>
ArrayList<T>::~ArrayList(){
    delete []arr;
}





