#ifndef _ROSTER_HPP_
#define _ROSTER_HPP_

#include <fstream>
#include <string>

class Roster
{
private:
  std::string *_names;
  int _count;
public:
  Roster(std::ifstream &ifile);
  const Roster& operator+=(const std::string &name);

  friend std::ostream& operator<<(std::ostream &os, const Roster &ros);
};

#endif
