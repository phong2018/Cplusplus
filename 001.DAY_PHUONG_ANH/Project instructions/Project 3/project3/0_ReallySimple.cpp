// A quick test of default Soccer League construction
// This is a very easy test, but it should get you started
// Author: S. Blythe
// Date: 1/2021
#include "SoccerLeague.hpp"
#include "SoccerTeam.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
  // build empty soccer league
  SoccerLeague myLeague;

  cout << "Nothing should appear between the ============= lines. " << endl;
  cout << "=============" << endl
       << myLeague
       << "=============" << endl;
  
  return 0;
}
