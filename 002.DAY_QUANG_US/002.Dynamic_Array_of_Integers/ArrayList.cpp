#include <iostream>
#include <string>

using namespace std;

#include "ArrayList.h"

int  ArrayList::getArraySize() const{
        return arraySize;
    }

    int ArrayList::getNumOfElements() const {
        return numOfElements;
    }


    ArrayList::ArrayList() {
       arraySize = 2;
       numOfElements = 0;
       arr = new int[arraySize];
    }


    ArrayList::ArrayList(int ArraySize) {

        if (ArraySize < 2){
            //cout << "Error" << endl;
            arraySize = 2;
            numOfElements = 0;
            arr = new int[arraySize];
        }

        else {
            arraySize =ArraySize;
            numOfElements = 0;
            arr = new int[arraySize];

        }
    }


    ArrayList::ArrayList(const ArrayList &r){
        numOfElements = r.numOfElements;
        arraySize = r.arraySize;
        arr = new int[r.arraySize];
        for (int i = 0; i < numOfElements; i++) {
            arr[i] = r.arr[i];
        }
    }


    int ArrayList::getElementAt(int index) const {
        if(index>=numOfElements)
            return -1;
        else
            return arr[index];
    }


    void ArrayList::addElement(int num){
        if(num < 0)
        {
            return;
        }
        if(numOfElements >= arraySize)
        {
            int *newArr = new int[arraySize * 2];

            for(int i = 0; i < arraySize; i++)
            {
                newArr[i] = arr[i];
            }

            delete []arr;
            arr = newArr;
            newArr = NULL;

            arr[numOfElements] = num;
            numOfElements++;
            arraySize *= 2;
        }
        else
        {
            arr[numOfElements] = num;
            numOfElements++;
        }

    }


    void ArrayList::deleteElement(int num){
        bool isFound = false;

        for(int i = 0; i < numOfElements; i++)
        {

            if(arr[i] == num && i <numOfElements - 1)
            {

                isFound = true;
                arr[i] = arr[i + 1];
                arr[i + 1] = num;
            }
            if (arr[i] == num && i == numOfElements - 1)
            {
                isFound = true;

            }
        }

        if(isFound)
        {
            numOfElements--;

            if(numOfElements <= arraySize / 2)
            {
                int *newArr = new int[arraySize / 2];
                for(int i = 0; i < numOfElements; i++)
                {
                    newArr[i] = arr[i];
                }

                delete []arr;
                arr = newArr;
                newArr =NULL;

                arraySize = arraySize / 2;
            }
        }


    }


    ArrayList::~ArrayList(){
        delete []arr;
    }





