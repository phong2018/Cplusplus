// A quick test of the + operator. 
// This is a very easy test, but it should get you started
// Author: S. Blythe
// Date: 1/2021
#include "SoccerLeague.hpp"
#include "SoccerTeam.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
  cout << "This test assumes that all provided data files are in "
       << "the \"current working directory\" !!!" 
       << endl;

  ifstream ifile;
  ifile.open("groupA.txt");
  SoccerLeague groupA(ifile);
  ifile.close();
  cout << "Group A" << endl
       << groupA
       << "===========================" << endl;
    
  ifile.open("groupB.txt");
  SoccerLeague groupB(ifile);
  ifile.close();
  cout << "Group B" << endl
       << groupB
       << "===========================" << endl;

  ifile.open("playoffs.txt");
  SoccerLeague playoffs(ifile);
  ifile.close();
  cout << "Playoffs" << endl
       << playoffs
       << "===========================" << endl;

  cout << "group A teams in the Playoffs:" << endl
       << groupA/playoffs
       << "===========================" << endl;

  cout << "NOTE: The previous should not have modified A or playoffs" << endl;
  cout << "Group A" << endl
       << groupA
       << "===========================" << endl;
  cout << "Playoffs" << endl
       << playoffs
       << "===========================" << endl;
    
  cout << "group B teams in the Playoffs:" << endl
       << groupB/playoffs
       << "===========================" << endl;

  cout << "Playoff teams in group B:" << endl
       << playoffs/groupB
       << "===========================" << endl;


  cout << "Teams in groupA that are in group A:" << endl
       << groupA/groupA
       << "===========================" << endl;
  cout << "NOTE: The previous should not have modified A" << endl;
  cout << "Group A" << endl
       << groupA
       << "===========================" << endl;
   
  return 0;
}
