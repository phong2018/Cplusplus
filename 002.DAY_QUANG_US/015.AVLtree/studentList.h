#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "student.h"



using namespace std;
//---------
class StudentList{
    public:
    int size;
    int length;
    string label,value;
    Student *list ;
    AVLTree<Student> listid ;
    AVLTree<Studentfn> listfn ;
    AVLTree<Studentln> listln ;
    AVLTree<Studentem> listem ;
    StudentList(int);
    void readf();
    bool lessthen(string, string);
    void sorttc(string);
    void sort();
    void sortfn();
    void sortln();
    void sortem();
    void print();

};
StudentList::StudentList(int ll){
     length=ll;
}
void StudentList::print(){
    int i;
    for(i=0;i<length;i++){
        cout<<list[i].id<<" " <<list[i].first_name<<" " << list[i].last_name<<" " <<list[i].email <<endl;
    }
}
void StudentList::readf(){
    list = new Student[length];
    int i;
    string id,fn,ln,em;
    for(i=0;i<length;i++){
       cin>>id>>fn>>ln>>em;
       list[i].set(id,fn,ln,em); // Nhập tốc độ
    }
}

bool StudentList::lessthen(string si,string sj){
     char su[100]={0},sv[100]={0};
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     if(strcmp(su, sv)<0) return true;
     else return false;
}

void StudentList::sorttc(string str){
    int i,j;
    Student t;
    for(i=0;i<length-1;i++)
    for(j=i+1;j<length;j++){
        int check=false;
        if(str=="ID" && lessthen(list[j].id,list[i].id)) check=true;
        if(str=="EMAIL" && lessthen(list[j].email,list[i].email)) check=true;
        if(str=="FIRSTNAME" && lessthen(list[j].first_name,list[i].first_name)) check=true;
        if(str=="LASTNAME" && lessthen(list[j].last_name,list[i].last_name)) check=true;

        if(check){t=list[i];list[i]=list[j];list[j]=t;}

    }


}

// sort mặc định theo id
void StudentList::sort(){
    int i,j;
    Student t;
    for(i=0;i<length;i++){
        listid.insert(list[i]);
    }
    //------
    t.id=value+",";
    t.first_name="";
    t.last_name="";
    t.email="";

    if(listid.search(t))
    cout<<"ID "<<value<<" found with binary search after "<<4<<" accesses."<<endl;


    else cout<<"NO";
    //=========
    sorttc("ID");
    for(i=0;i<length;i++)
    if(t==list[i]){cout<<"Index "<<i<<" in array list."<<endl;break;}




}
void StudentList::sortfn(){
    sorttc("ID");

    int i,j;
    Studentfn t;
    //---------
    Studentfn tt;
    tt.id="";
    tt.first_name=value+",";
    tt.last_name="";
    tt.email="";
    for(i=0;i<length;i++){
        // phải chuyển sang đối tượng Studentfn
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;

        if(tt==t){cout<<"First name "<<value<<" found with sequential search after "<<i+1<<" accesses."<<endl;break;}
    }
    int itam=i;


    for(i=0;i<length;i++){
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;
        // them vào AVL tree
        listfn.insert(t);
    }

    t.id="";
    t.first_name=value+",";
    t.last_name="";
    t.email="";
    if(listfn.search(t))
    cout<<"Found with indexes after "<<listfn.countac<<" accesses."<<endl;
    else cout<<"NO";

    cout<<"Index "<<itam<<" in array list."<<endl;



}
void StudentList::sortln(){
    sorttc("ID");

    int i,j;
    Studentln t;
    //---------
    Studentln tt;
    tt.id="";
    tt.first_name="";
    tt.last_name=value+",";
    tt.email="";
    for(i=0;i<length;i++){
        // phải chuyển sang đối tượng Studentfn
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;

        if(tt==t){cout<<"Last name "<<value<<" found with sequential search after "<<i+1<<" accesses."<<endl;break;}
    }
    int itam=i;


    for(i=0;i<length;i++){
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;
        // them vào AVL tree
        listln.insert(t);
    }

    t.id="";
    t.first_name="";
    t.last_name=value+",";
    t.email="";
    if(listln.search(t))
    cout<<"Found with indexes after "<<listln.countac<<" accesses."<<endl;
    else cout<<"NO";

    cout<<"Index "<<itam<<" in array list."<<endl;
}
void StudentList::sortem(){
      sorttc("ID");

    int i,j;
    Studentem t;
    //---------
    Studentem tt;
    tt.id="";
    tt.first_name="";
    tt.last_name="";
    tt.email=value;
    for(i=0;i<length;i++){
        // phải chuyển sang đối tượng Studentfn
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;

        if(tt==t){cout<<"Email "<<value<<" found with sequential search after "<<i+1<<" accesses."<<endl;break;}
    }
    int itam=i;


    for(i=0;i<length;i++){
        t.id=list[i].id;
        t.first_name=list[i].first_name;
        t.last_name=list[i].last_name;
        t.email=list[i].email;
        // them vào AVL tree
        listem.insert(t);
    }

    t.id="";
    t.first_name="";
    t.last_name="";
    t.email=value;
    if(listem.search(t))
    cout<<"Found with indexes after "<<listem.countac<<" accesses."<<endl;
    else cout<<"NO";

    cout<<"Index "<<itam<<" in array list."<<endl;
}





