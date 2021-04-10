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
  ifstream ifile("a.txt");//

  // build soccer league from file and print it out.
  SoccerLeague myLeague(ifile);
  ifile.close();
  //cout <<"myLeague:----------\n"<< myLeague ;
  //---------
  SoccerLeague objcopy(myLeague);
  //cout <<"objcopy:----------\n"<<objcopy;

  // add another tema to the league and print out result.
  SoccerTeam argentina("Maradona Cheated", 0, 1);
  myLeague+=argentina;
  //cout <<"myLeague+=(tem):----------\n" <<myLeague ;
  //--------
  SoccerLeague d;
  d+=argentina;
  //cout <<"d+=(team):----------\n" <<d;
  SoccerLeague e;
  e=objcopy;
  //cout <<"e=(luague objcopy):----------\n"<< e;
  e+=d;
  //cout <<"e+=(luague d):----------\n"<< e;
  e+=d;
  //cout <<"e+=(luague-co trung team):----------\n"<< e;
  cout<<"e:\n "<<e;
  cout<<"objcopy:\n "<<objcopy;
  e-=objcopy;
  cout <<"e-=(luague: objcopy):----------\n"<< e;
  e-=argentina;
  cout <<"e-=(team: argentina):----------\n"<< e;
  e=objcopy+d;
  cout <<"e=d+objcopy:----------\n"<< e;

 /*
  cout <<"c=a+b:----------\n" <<c;
  return 0;
 */
}
