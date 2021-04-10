#include <iostream>
#include <string>
#include <vector>
 

struct Course;

struct Student
{
  std::string name;
  std::vector<Course*> courses;
};

struct Course
{
  std::string name;
  std::vector<Student*> students;
};
//==========
void enroll( Student *s, Course *c)
{
  c->students.push_back(s);
  s->courses.push_back(c);
}

void print_student(Student *s)
{
  std::cout<< "Name of Student: " << s->name << std::endl;
  for (int i =0; i< s->courses.size(); i++)
  {
    //std::string course_name;//course_name = s->courses[i]; 
    std::cout<< s->courses[i]->name << std::endl;
  }
}

void print_course(Course *c)
{
  std::cout <<"Name of course: "<< c->name << std::endl;

  for (int i=0; i < c->students.size(); i++)
  {
    std::cout<< c->students[i]->name << std::endl;
  }
}
  
 
int main() 
{  
 int n;
  std::cout<<"NHap N";
  std::cin>>n;
   //Make a list of classes first and then enroll each student into mutiple classes
   
   Course *c1 = new Course;
    c1->name = "ART 101";
    
    Course *c2 = new Course;
    c2->name = "Art 102";
    
    Course *c3 = new Course;
    c3->name = "ENGL 101";
    
    Course *c4 = new Course;
    c4->name = "HIST 117";;
    
    Course *c5 =new Course;
    c5->name = "Math 228";

    Course *c6 =new Course;
    c6->name = "ENGL 104";

  Student *s1 = new Student;
  s1 ->name = "Fred Flintstone";
  enroll(s1,c1);
  enroll(s1,c2);
  enroll(s1,c4);

  Student *s2 = new Student;
  s2 ->name = "Khanh Nham";
  enroll(s2,c2);
  enroll(s2,c3);
  enroll(s2,c4);
  enroll(s2,c5);
  
  Student *s3 = new Student;
  s3->name = "Erik Nguyen";
  enroll(s3,c6);
  enroll(s3,c5);
  enroll(s3,c4);
  
  Student *s4 =new Student;
  s4->name = "Ryan";
  enroll(s4,c6);
  enroll(s4,c2);
  enroll(s4,c1);
  enroll(s4,c3);
  
  Student *s5 =new Student;
  s5->name = "John";
  enroll(s5,c5);
  enroll(s5,c4);
  enroll(s5,c1);

  print_student(s1);
  print_student(s2);
  print_student(s3);
  print_student(s4);
  print_student(s5);

  print_course(c1);
  print_course(c2);
  print_course(c3);
  print_course(c4);
  print_course(c5);
  print_course(c6);
  std::cout<<"==============\n";
  int i=8;
  int j;
  int *dci;
  std::cout<<i<<"\n";
  std::cout<<&i<<"\n";
  dci=&i; 
  std::cout<<*dci<<"\n";


    return 0;
} 