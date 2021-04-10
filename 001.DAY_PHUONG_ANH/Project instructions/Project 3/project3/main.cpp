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
  cout<<"Test Read file:\n";
  ifstream ifile("ThreeTeams.txt");
  SoccerLeague myLeague(ifile);
  cout << myLeague << endl;

  cout<<"\nTest +=Team:\n";
  SoccerTeam argentina("Maradona Cheated", 0, 1);
  myLeague+=argentina;
  cout<< myLeague << endl;

  cout<<"\nTest Contructure():\n";
  SoccerLeague C1;
  C1+=argentina;
  cout<<C1;

  cout<<"\nTest Copy:\n";
  SoccerLeague myLeaguecopy(myLeague);
  cout << myLeaguecopy << endl;
  //tess +=league


  ifstream ifileA("groupA.txt");
  SoccerLeague A(ifileA);

  ifstream ifileB("groupB.txt");
  SoccerLeague B(ifileB);

   cout<<"\nTest split \:\n";
  cout<<A/B;

  cout<<"\nTest += League:\n";
  A+=B;
  cout<<A;



  cout<<"\nTest -=League:\n";
  A-=B;
  cout<<A;

  cout<<"\nTest Remove Team:\n";
  SoccerTeam rm("Morocco1", 0, 2);
  A.removeTeam(rm);
  cout<<A;

  cout<<"\nTest -=Team:\n";
  SoccerTeam r2("Uruguay", 6, 0);
  A-=r2;
  cout<<A;




  return 0;
}
