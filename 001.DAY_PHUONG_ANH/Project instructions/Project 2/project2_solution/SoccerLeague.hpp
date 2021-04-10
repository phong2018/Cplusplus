// FILE: SoccerLeague.hpp
// AUTHOR: Stephen Blythe
// DATE: 1/2021
//    Definition file for SoccerLeague class
//     (part of solution for CSC24400 P2)

#ifndef _SOCCER_LEAGUE_HPP_
#define _SOCCER_LEAGUE_HPP_

#include <iostream>
#include <fstream>

#include "SoccerTeam.hpp"

using namespace std;

class SoccerLeague
{
private:
  SoccerTeam *_collection;  // points to current array of SoccerTeams
  int _size;           // number of elements in array, including unfilled
  int _count;          // number of filled elements in the array

  // private method utilized in some of the required public methods. 
  SoccerTeam* find(const SoccerTeam &m) const; // returns team from array (or NULL)
  void resize(int biggerSize);       // rebuild array to be new size
public:

  // constructors
  SoccerLeague();
  SoccerLeague(std::ifstream &ifile);
  SoccerLeague(const SoccerLeague & other);

  // overloaded "set" operators
  const SoccerLeague& operator+(const SoccerLeague &other) const;//union
  const SoccerLeague& operator/(const SoccerLeague &other) const;//intersection

  // overloaded assignment
  const SoccerLeague& operator=(const SoccerLeague &other);

  // overloaded += options to add teams to this league 
  const SoccerLeague& operator+=(const SoccerTeam &teamToAdd);
  const SoccerLeague& operator+=(const SoccerLeague &other);

  // overloaded -= options to remove teams from this league
  const SoccerLeague& operator-=(const SoccerTeam &teamToRemove);
  const SoccerLeague& operator-=(const SoccerLeague &other);

  // empties this collection
  void clear();

  // print method. 
  std::ostream& print(std::ostream &os) const;

  // pverloaded << operator. 
  friend std::ostream& operator<<(std::ostream &os, const SoccerLeague &sl);
};

#endif
