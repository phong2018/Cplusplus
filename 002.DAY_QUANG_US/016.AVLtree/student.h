#include <iostream>
using namespace std;
//---------
class Student{
    public:
    string id;
    string first_name;
    string last_name;
    string email;
    Student();
    Student(string,string,string,string);
    void set(string,string,string,string);
    void get();
    void print();
};
//--------
Student::Student(){
     id="";
     first_name="";
     last_name="";
     email="";
}
Student::Student(string sid,string sfn,string sln,string sm){
     cout<<"co so"<<endl;
     id=sid;
     first_name=sfn;
     last_name=sln;
     email=sm;
}
void Student::set(string sid,string sfn,string sln,string sm){
     id=sid;
     first_name=sfn;
     last_name=sln;
     email=sm;
}
void Student::get(){

}
void Student::print(){
    cout<<id<<"__"<<first_name<<"__"<<last_name<<"__"<<email<<endl;
}
