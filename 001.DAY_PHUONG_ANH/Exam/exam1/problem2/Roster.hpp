#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class Roster
{
private:
  std::string *_array;
  int _currSize; //<=100
public:
  // read file
  Roster(ifstream& ifile);
  //---------- +=
  void add(const std::string &toAdd);
  void operator+=(const std::string &toAdd);
  //----------cout
  std::ostream& operator<<(std::ostream &os) const;
  std::ostream& print(std::ostream &toThisStream) const;
  friend std::ostream& operator<<(std::ostream &os,
				  const Roster &pfa);
};
