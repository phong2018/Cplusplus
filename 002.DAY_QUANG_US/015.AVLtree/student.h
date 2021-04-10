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
    bool operator >(const Student& k);
    bool operator ==(const Student& k);
    bool operator <(const Student& k);
    friend ostream &operator<<( ostream &output,  const Student &k ){
         output<<k.id<<" " <<k.first_name<<" " << k.last_name<<" " <<k.email <<endl; // Nhập tốc độ
         return output;
    }
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

bool Student::operator >(const Student& k){
     char su[100]={0},sv[100]={0};
     string si=id;
     string sj=k.id;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)>0) return true;
     else return false;
}

 bool Student::operator ==(const Student& k){
     char su[100]={0},sv[100]={0};

     string si=id;
     string sj=k.id;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //cout<<"LENGT SI:"<<si.length()<<endl;
     //cout<<"LENGT SJ:"<<sj.length()<<endl;
     //cout<<"SI="<<si<<endl;
     //cout<<"SJ="<<sj<<endl;
     //cout<<"SU="<<su<<"==="<<endl;
     //cout<<"SV="<<sv<<"==="<<endl;
     //-----
     if(strcmp(su, sv)==0) return true;
     else return false;
}
 bool Student::operator <(const Student& k){

     char su[100]={0},sv[100]={0};
     string si=id;
     string sj=k.id;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)<0) return true;
     else return false;
}
//=======================================================
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

     char su[100]={0},sv[100]={0};
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)>0) return true;
     else return false;
}

 bool Studentfn::operator ==(const Studentfn& k){

     char su[100]={0},sv[100]={0};
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)==0) return true;
     else return false;
}
 bool Studentfn::operator <(const Studentfn& k){

     char su[100]={0},sv[100]={0};
     string si=first_name;
     string sj=k.first_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)<0) return true;
     else return false;
}
//=======================================================
class Studentln: public Student{
    public:
    bool operator >(const Studentln& k);
    bool operator ==(const Studentln& k);
    bool operator <(const Studentln& k);
    friend ostream &operator<<( ostream &output,  const Studentln &k ){
         output<<k.id<<" " <<k.first_name<<" " << k.last_name<<" " <<k.email <<endl; // Nhập tốc độ
         return output;
    }
};

bool Studentln::operator >(const Studentln & k){

     char su[100]={0},sv[100]={0};
     string si=last_name;
     string sj=k.last_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)>0) return true;
     else return false;
}

 bool Studentln::operator ==(const Studentln& k){

     char su[100]={0},sv[100]={0};
     string si=last_name;
     string sj=k.last_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)==0) return true;
     else return false;
}
 bool Studentln::operator <(const Studentln& k){

     char su[100]={0},sv[100]={0};
     string si=last_name;
     string sj=k.last_name;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)<0) return true;
     else return false;
}
//=======================================================
class Studentem: public Student{
    public:
    bool operator >(const Studentem& k);
    bool operator ==(const Studentem& k);
    bool operator <(const Studentem& k);
    friend ostream &operator<<( ostream &output,  const Studentem &k ){
         output<<k.id<<" " <<k.first_name<<" " << k.last_name<<" " <<k.email <<endl; // Nhập tốc độ
         return output;
    }
};

bool Studentem::operator >(const Studentem & k){

     char su[100]={0},sv[100]={0};
     string si=email;
     string sj=k.email;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)>0) return true;
     else return false;
}

 bool Studentem::operator ==(const Studentem& k){

     char su[100]={0},sv[100]={0};
     string si=email;
     string sj=k.email;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)==0) return true;
     else return false;
}
 bool Studentem::operator <(const Studentem& k){

     char su[100]={0},sv[100]={0};
     string si=email;
     string sj=k.email;
     for(int e=0;e<si.length();e++) su[e]=si[e];
     for(int e=0;e<sj.length();e++) sv[e]=sj[e];
     //-----
     if(strcmp(su, sv)<0) return true;
     else return false;
}


