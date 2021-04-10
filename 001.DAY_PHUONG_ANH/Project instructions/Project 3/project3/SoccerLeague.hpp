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
  //store scocerteam list
  SoccerTeam *_head;
  SoccerTeam *_tail;
    // private method utilized in some of the required public methods.
  SoccerTeam* find(const SoccerTeam &m) const; // returns team from array (or NULL)
public:

  SoccerLeague();


  SoccerLeague(std::ifstream &ifile);
  SoccerLeague(const SoccerLeague & other);//copy

  void removeTeam(const SoccerTeam& toRemove);
  void insertfront(const SoccerTeam &someVal);//insert front

  //add team to league
  const SoccerLeague& operator+=(const SoccerTeam &teamToAdd);//insert last
  const SoccerLeague& operator+=(const SoccerLeague &other);

  //sub team to league
  const SoccerLeague& operator-=(const SoccerTeam &teamToAdd);//insert last
  const SoccerLeague& operator-=(const SoccerLeague &other);
  SoccerLeague operator/(const SoccerLeague &other) const;

  //print league
  std::ostream& print(std::ostream &os) const;
  friend std::ostream& operator<<(std::ostream &os, const SoccerLeague &sl);
};

#endif
