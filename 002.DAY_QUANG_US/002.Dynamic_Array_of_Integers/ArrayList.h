//Use this file to write the declaration of your class' attributes and functions.

#ifndef ArrayList_H
#define ArrayList_H

//Your class here
class ArrayList
{
	private:
    int arraySize=0 ;
    int numOfElements=0 ;
    int *arr = NULL;

public:


    ArrayList();
    ArrayList(int ArraySize);
    int getArraySize() const;
    int getNumOfElements() const;
    ArrayList(const ArrayList &r);
    int getElementAt(int index) const;
    void addElement(int num);
    void deleteElement(int num);
    ~ArrayList();
};

#endif
