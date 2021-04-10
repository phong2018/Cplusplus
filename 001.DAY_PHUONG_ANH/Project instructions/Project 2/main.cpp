// A quick test of loading teams from a file
// This is a very easy test, but it should get you started
// Author: S. Blythe
// Date: 1/2021
#include "SoccerLeague.hpp"
#include "SoccerTeam.hpp"

#include <fstream>
#include <iostream>

int main(int argc, char* argv[])
{
	// open file specified as command line argument
	//	ifstream ifile(argv[1]);
	ifstream ifile("ThreeTeams.txt");

	// build soccer league from file and print it out.
	SoccerLeague myLeague(ifile);
	cout << myLeague << endl;


	//*a copy constructor that takes in as its only parameter an existing SoccerLeague and 
	//*duplicates the existing SoccerLeague.The parameter should not be allowed to changeand should be passed efficiently.
	
	SoccerLeague objcopy(myLeague);
	cout << objcopy;

	// add another teamto the league and print out result.
	SoccerTeam argentina("Maradona Cheated", 0, 1);
	myLeague+=argentina;  //*** += operator
	cout << myLeague << endl;

	//-----tu viet them  +-/
	SoccerTeam team1("team1", 0, 1);//object ten team1 -> name team1, 0, 1
	SoccerTeam team2("team2", 2, 2);
	SoccerTeam team3("team3", 2, 2);
	SoccerLeague league1;
	SoccerLeague league2;
	SoccerLeague league3;
	league1+= team1;
	league2+= team2;
	league2+= team3;
	cout << "league1:====\n" << league1;
	cout << "league2:====\n" << league2;
	cout << "league3:====\n" << league3;
	league3+= league2;
	cout << "league3+= league2:====\n" << league3;
	league3+= league1;
	cout << "league3+= league1;====\n" << league3;
	league3 += league1;
	cout << "league3+= league1;====\n" << league3;

	//league3 = league1 + league2;
	//league3 -= team1;
	//league3 -= league1; 


	return 0;
}