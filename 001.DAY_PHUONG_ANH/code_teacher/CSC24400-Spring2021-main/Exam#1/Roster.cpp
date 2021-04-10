#include "Roster.hpp"

using namespace std;

Roster::Roster(ifstream &ifile)
{
  _names = new string[100];
  string name;
  
  ifile >> name;
  while (ifile)
    {
      operator+=(name);
      // *this += name;

      ifile >> name;
    }
}

const Roster&
Roster::operator+=(const string &name)
{
  _names[_count++] = name;
  return *this;
}


ostream& operator<<(ostream &os, const Roster &ros)
{
  for (int index=0; index < ros._count; index++)
    os << ros._names[index] << endl;
  
  return os;
}
