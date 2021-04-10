#include <fstream>
#include <iostream>

#include "Roster.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile(argv[1]);

  Roster myRos(ifile);

  cout << "====================" << endl
       << myRos; 

  cout << "====================" << endl
       << (myRos+= "steve");

  cout << "====================" << endl
       << myRos; 

  return 0;
}
