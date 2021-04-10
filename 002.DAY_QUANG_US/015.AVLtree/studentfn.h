#include <iostream>
#include "student.h"
using namespace std;
//---------
class Studentfn: public Student{
    public:
    bool operator >(const Studentfn& k);
    bool operator ==(const Studentfn& k);
    bool operator <(const Studentfn& k);
    friend ostream &operator<<( ostream &output,  const Studentfn &k ){
         output<<k.id<<" " <<k.first_name<<" " << k.last_name<<" " <<k.email <<endl; // Nhập tốc độ
         return output;
    }
};

bool Studentfn::operator >(const Studentfn & k){
     char su[100],sv[100];
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)>0) return true;
     else return false;
}

 bool Studentfn::operator ==(const Studentfn& k){
     char su[100],sv[100];
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)==0) return true;
     else return false;
}
 bool Studentfn::operator <(const Studentfn& k){
     char su[100],sv[100];
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)<0) return true;
     else return false;
}


