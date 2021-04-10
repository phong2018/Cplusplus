// A quick test of loading teams from a file
// This is a very easy test, but it should get you started
// Author: S. Blythe
// Date: 1/2021
#include "SoccerLeague.hpp"
#include "SoccerTeam.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
  // open file specified as command line argument
  ifstream ifile(argv[1]);

  // build soccer league from file and print it out. 
  SoccerLeague myLeague(ifile);
  cout << myLeague << endl;

  // add another tema to the league and print out result. 
  SoccerTeam argentina("Maradona Cheated", 0, 1);
  myLeague+=argentina;
  cout << myLeague << endl;

  return 0;
}
