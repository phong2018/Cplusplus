//Use this file to write the declaration of your class' attributes and functions.

#ifndef ArrayList_H
#define ArrayList_H

//Your class here
template<class T>
class ArrayList
{
	private:
    int arraySize=0 ;
    int numOfElements=0 ;
    T *arr = NULL;

public:


    ArrayList();
    ArrayList(int ArraySize);
    int getArraySize() const;
    int getNumOfElements() const;
    ArrayList(const ArrayList &r);
    T getElementAt(int index) const;
    void addElement(T element);
    void deleteElement(T element);
    ~ArrayList();
};

#endif
