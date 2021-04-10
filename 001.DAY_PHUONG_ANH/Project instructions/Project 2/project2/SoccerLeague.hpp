#ifndef _SOCCER_LEAGUE_HPP_
#define _SOCCER_LEAGUE_HPP_

// FILE: SOccerTeam.hpp
// AUTHOR: Stephen Blythe
// DATE: 1/2021
//    Definition file for SoccerTeam class

#include <string>
#include <iostream>
#include <fstream>
#include "SoccerTeam.hpp"
using namespace std;

class SoccerLeague {

private:
	SoccerTeam* _array; //Array comprises of SoccerTeam
	int _currSize = 0; // Number of SoccerTeam
public:

	// default constructor
	SoccerLeague(); 
	SoccerLeague(ifstream& ifile); 
	SoccerLeague(SoccerLeague& other); 

	//====

	//print normal
	void printLeague();
	//overload <<
	ostream& print(std::ostream& os) const;//print league
	friend std::ostream& operator<< (std::ostream& os, const SoccerLeague& st);


	void add(const SoccerTeam& toadd);

	//to clear method empties out the current league
	void clear();
	//
	void removeTeam(const SoccerTeam& toRemove);
 
	//declare operator +=
	void operator+=(const SoccerTeam &other);

	void operator+=(const SoccerLeague &other);
	//********
	SoccerLeague operator+(const SoccerLeague &other) const;
	///
	SoccerLeague operator/(const SoccerLeague &other) const;
	///
	//declare operator -=
	void operator-=(const SoccerTeam& other);
	void operator-=(const SoccerLeague& other);

};
#endif



