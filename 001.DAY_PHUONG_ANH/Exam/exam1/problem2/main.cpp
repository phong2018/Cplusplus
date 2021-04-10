#include <iostream>
#include <fstream>
#include "Roster.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile("D:/2018/025.DAY-THEM/026.day phuong anh c++/001.DAY_PHUONG_ANH/Exam/exam1/problem2/input.txt");
  Roster ros(ifile); //read name in ifile
  cout<<ros<<"=========\n";
  ros+="Phuong";
  cout<<ros<<"=========\n";
  return 0;
}
