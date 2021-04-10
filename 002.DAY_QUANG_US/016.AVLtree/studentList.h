#include "student.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef StudentList_H
#define StudentList_H


class StudentList
{
private:
    int size=0 ;
    int length=0 ;
    Student *list = NULL;

public:
    StudentList();
    StudentList(int listSize);
    int getSize() const;
    int getLength() const;
    StudentList(const StudentList &r);
    Student getStudentAt(int index) const;
    void addStudent(const Student &element); //Students can be added at the end of the array, and sorted later
    int binarySearchID(string ID) const;     //Search for a student using ID and binary search
                                             //Return index or -1 if not found
    int seqSearchFirstName(string fn) const; //Search for a student using first name and sequential search
                                             //Return index or -1 if not found
    int seqSearchLastName(string ln) const;  //Search for a student using last name and sequential search
                                             //Return index or -1 if not found
    int seqSearchEmail(string em) const;     //Search for a student using email and sequential search
                                             //Return index or -1 if not found
    void sort();     //sort students by ID (can use any sorting algorithm - but don't change the function call
    ~StudentList();
};

#endif

StudentList::StudentList(int listSize){
     size=listSize;
}
int StudentList::getSize(){
     return size;
}
void StudentList::addStudent(const Student &element){
     size++;
     list[size].id=element.id;
     list[size].first_name=element.first_name;
     list[size].last_name=element.last_name;
     list[size].email=element.email;
}
void StudentList::sort(){
    int i,j;
    Student t;
    for(i=0;i<length-1;i++)
    for(j=i+1;j<length;j++)
    if(str=="ID" && lessthen(list[j].id,list[i].id))
    {t=list[i];list[i]=list[j];list[j]=t;}

}
