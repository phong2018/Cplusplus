// FILE: SoccerLeague.hpp
// AUTHOR: Stephen Blythe
// DATE: 1/2021
//    Implementation file for SoccerLeague class
#include "SoccerLeague.hpp"

#include <iostream>

using namespace std;
// default constructor
SoccerLeague::SoccerLeague()
{
  _head = NULL;
  _tail = NULL;
}


// build collection from open input stream.
SoccerLeague::SoccerLeague(std::ifstream &ifile)
{
  _head = NULL;
  _tail = NULL;
  // read in one team at a time


  SoccerTeam m;
  ifile >> m;
  while(ifile)
    {
      // a bit sneaky here. use my += operator to add this team.
      operator+=(m);
      // read next team
      ifile >> m;
    }

}

// This is a private method ... it is used here as
//  "support" for other (public) methods
SoccerTeam*
SoccerLeague::find(const SoccerTeam &m) const
{
  // look at each element to see if it is the one we're looking for ...
  SoccerTeam *currPtr;
  currPtr=_head; //&tenbien
  while(currPtr!=NULL)
  {
    if (*currPtr==m)
    return currPtr; // return address, since we are returning pointer
    currPtr = currPtr->next();
  }
  return NULL; // not found? return NULL pointer
}

// duplicate "other" league into ths one.
SoccerLeague::SoccerLeague(const SoccerLeague & other)
{
  _head = NULL;
  _tail = NULL;

  //lấy từng pt của orther bỏ qua league hiện tại
  SoccerTeam *currPtr;

  currPtr=other._head;//lấy head của order

  while(currPtr!=NULL)
  {
    operator+=(*currPtr);
    currPtr = currPtr->next();
  }
}

void
SoccerLeague::insertfront(const SoccerTeam &teamToAdd)
{
  SoccerTeam *newNode = new SoccerTeam(teamToAdd);
  //------
  newNode->next() = _head;
  _head = newNode;

  if (_tail == NULL) // started with an empty list (aka this is the first item)
    _tail = newNode;
}

// overoaded += to add a single SoccerTeam
//    NOTE: other methods call this one, so important to not call those
//              other methods from within here.
const SoccerLeague&
SoccerLeague::operator+=(const SoccerTeam &teamToAdd){

  SoccerTeam *existingTeam = find(teamToAdd);
  if (existingTeam==NULL){
    if (_tail==NULL) //nothing in list right now. (note: means head is null too)
    {
      // inserting at front would get this done as well.
      insertfront(teamToAdd);
    }else{
    // only way we can get here is if _tail was not null.
    SoccerTeam *newNode = new SoccerTeam(teamToAdd);
    //cout<<teamToAdd<<"\n";

    newNode->next() = NULL;
    _tail->next()=newNode;
    _tail=newNode;
    }
  }
  else
  {
    existingTeam->wins()+=teamToAdd.wins();
    existingTeam->losses()+=teamToAdd.losses();
  }

}

// overoaded += to add a collection of SoccerTeams.
const SoccerLeague&
SoccerLeague::operator+=(const SoccerLeague &other)
{
  // look at each team in the other (RHS) league ...
  //lấy từng pt của orther bỏ qua league hiện tại
  SoccerTeam *currPtr;

  currPtr=other._head;//lấy head của order

  while(currPtr!=NULL)
  {
    operator+=(*currPtr);
    currPtr = currPtr->next();
  }

  // duplicate "this" and return duplicate
  SoccerLeague *answerPtr = new SoccerLeague(*this);
  return *answerPtr;
}

//the -= operator should be overloaded with the right hand side being a single SoccerTeam.
void SoccerLeague::removeTeam(const SoccerTeam& toRemove) {
  //tim xem cos ko
  SoccerTeam *existingTeam = find(toRemove);
  if (existingTeam!=NULL){
    if(existingTeam==_head) _head=_head->next();
    else{//ko nam o dau
        SoccerTeam *currPtr;
        currPtr=_head;//lấy head của order
        //tim previous cua toremove
        while(currPtr->next()!=existingTeam)
          currPtr = currPtr->next();
        //cho currPtr tro qua
        currPtr->next()=existingTeam->next();
    }
  }
}
const SoccerLeague&
SoccerLeague::operator-=(const SoccerTeam &teamToRm){
  removeTeam(teamToRm);
}

const SoccerLeague&
SoccerLeague::operator-=(const SoccerLeague &other)
{
  SoccerTeam *currPtr;

  currPtr=other._head;//lấy head của order

  while(currPtr!=NULL)
  {
    removeTeam(*currPtr);

    currPtr = currPtr->next();
  }

}

//got the index wrong so the result doesn't match.
SoccerLeague SoccerLeague::operator/(const SoccerLeague &other) const
{
    SoccerLeague result;
    //------
    SoccerTeam *currPtr;
    currPtr=_head;
    while(currPtr!=NULL)
    {
       SoccerTeam *teamexits=other.find(*currPtr);
       if (teamexits!=NULL) {
          SoccerTeam temp(currPtr->name(), currPtr->wins()+teamexits->wins(),currPtr->losses() + teamexits->losses());
          result+=temp;
       }

      currPtr = currPtr->next();
    }

    return result;
}

// print out to specified stream ...
std::ostream&
SoccerLeague::print(std::ostream &os) const
{
  SoccerTeam *currPtr;
  currPtr=_head; //&tenbien
  while(currPtr!=NULL)
  {
    os << *currPtr << endl;
    currPtr = currPtr->next();
  }
  return os;
}

// overlaoded << for SoccerLeague
std::ostream& operator<<(std::ostream &os, const SoccerLeague &mc)
{
  // easy, sice we have a print method.
  return mc.print(os);

}

