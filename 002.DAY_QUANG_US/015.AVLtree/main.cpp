#include<iostream>
#include <fstream>
#include <string>
#include "AVLtree.h"
#include "studentList.h"



using namespace std;
//--------
ifstream finp;
int length;
StudentList sl(length);

void docf(){
     finp.open("input.inp");
     cin>>sl.length;
     //------ sl.readf();
     sl.list = new Student[sl.length];
     int i;
     string id,fn,ln,em;
     for(i=0;i<sl.length;i++){
       cin>>id>>fn>>ln>>em;
       sl.list[i].set(id,fn,ln,em);
     }
     cin>>sl.label;
     cin>>sl.value;
     //--------
}
int main(){
     docf();
     // cout<<"Đọc vào:"<<endl;
     //sl.print();
     // cout<<"=============="<<endl;
     // cout<<"Sort by ID:"<<endl;
     if(sl.label=="ID") sl.sort();
     if(sl.label=="FIRSTNAME") sl.sortfn();
     if(sl.label=="LASTNAME") sl.sortln();
     if(sl.label=="EMAIL") sl.sortem();
     /*
        cout<<"=============="<<endl;
     cout<<"Sort by First Name:"<<endl;
     sl.sortfn();
     cout<<"=============="<<endl;
     cout<<"Sort by Last Name:"<<endl;
     sl.sortln();
     cout<<"=============="<<endl;
     cout<<"Sort by Email:"<<endl;
     sl.sortem();
     */
     //sl.print();
     finp.close();
     return 0;
}
