#include "Roster.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Roster::Roster(ifstream& ifile) {
    _array = new string[50];
    _currSize = 0;
    while(ifile)
    {
      string name;
      ifile >>name;
      //----
      if(name.empty()) break;
      _array[_currSize]=name;
      _currSize++;

    }
}

void
Roster::add(const string &toAdd)
{
  _array[_currSize] = toAdd;
  _currSize++;
}

void
Roster::operator+=(const std::string &toAdd)
{
  add(toAdd);
}

ostream&
Roster::print(ostream &toThisStream) const
{
  toThisStream << "size: "<<_currSize<<"\n";
  for (int index=0; index<_currSize; index++)
    {
      toThisStream << *(_array+index) << endl;
    }

  return toThisStream;
}
std::ostream& operator<<(std::ostream &os, const Roster &pfa)
{
  return pfa.print(os);
}
