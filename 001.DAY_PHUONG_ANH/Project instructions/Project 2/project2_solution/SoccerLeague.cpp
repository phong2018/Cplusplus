// FILE: SoccerLeague.hpp
// AUTHOR: Stephen Blythe
// DATE: 1/2021
//    Implementation file for SoccerLeague class
#include "SoccerLeague.hpp"

#include <iostream>

using namespace std;

#define DEFAULT_SIZE 5

// This is a private method ... it is used here as
//  "support" for other (public) methods
SoccerTeam*
SoccerLeague::find(const SoccerTeam &m) const
{
  // look at each element to see if it is the one we're looking for ...
  for (int i=0; i<_count; i++)
    if (_collection[i]==m)
      return &_collection[i]; // return address, since we are returning pointer
  return NULL; // not found? return NULL pointer
}

// default constructor 
SoccerLeague::SoccerLeague()
{
  _size=DEFAULT_SIZE;
  _collection = new SoccerTeam[_size];
  _count=0;  // start empty
}

// build collection from open input stream. 
SoccerLeague::SoccerLeague(std::ifstream &ifile)
{
  // strat out at default size, completely empty
  _size=DEFAULT_SIZE;
  _collection=new SoccerTeam[_size];
  _count=0;

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

// duplicate "other" league into ths one. 
SoccerLeague::SoccerLeague(const SoccerLeague & other)
{
  // "this" collection will have same size as "other" 
  _size=other._size;
  _count=other._count;
  _collection=new SoccerTeam[_size];

  // copy each SoccerTeam int this array. 
  for(int i=0; i<_count; i++)
    _collection[i]=other._collection[i];
}

// private method to resize the array. 
void
SoccerLeague::resize(int biggerSize)
{
  // no sense resizing to smaller size. Instead double current size. 
  if (biggerSize<= _size)
    {
      cerr << "Requested size no bigger than current size. Double size instead."
	   << endl;
      biggerSize=2*_size;
    }

  // build up a new array of requested size. 
  SoccerTeam *newArray = new SoccerTeam[biggerSize];

  // copy current SoccerTeams into this new array 
  for (int i=0; i<_size; i++)
    newArray[i]=_collection[i];

  // "this" collection array should now be the new array. 
  _collection=newArray;

  // remember our size. 
  _size=biggerSize;

  // note that the number of filled elements did not change
}

// overloaded + 
const SoccerLeague&
SoccerLeague::operator+(const SoccerLeague &other) const
{
  // return value 
  SoccerLeague *resultPtr = new SoccerLeague();

  // go ahead and add everyhting in LHS into return value. 
  for (int i=0; i< _count; i++)
    *resultPtr += _collection[i]; // note use of overloaded +=

  // next, add everything from RHS into return value
  for (int i=0; i< other._count; i++)
    *resultPtr += other._collection[i]; // note use of overloaded +=

  // return new collection
  return *resultPtr;
}

// overloaed *
const SoccerLeague&
SoccerLeague::operator/(const SoccerLeague &other) const
{
  // return value 
  SoccerLeague *resultPtr = new SoccerLeague();

  // go through LHS collection ...
  for (int i=0; i< _count; i++)
    {
      // if current item from LHS is in the RHS, then add it to intersection
      if (other.find(_collection[i]))
	{
	  *resultPtr += _collection[i];
	  *resultPtr += *other.find(_collection[i]);
	}
    }

  // return new collection. 
  return *resultPtr;
}

// overoaded += to add a single SoccerTeam
//    NOTE: other methods call this one, so important to not call those
//              other methods from within here. 
const SoccerLeague&
SoccerLeague::operator+=(const SoccerTeam &teamToAdd)
{
  // if we cannot find the team we're trying to add, then we should
  //    ad it to LHS (this) ... otherwise we should update W's and L's
  
  SoccerTeam *existingTeam = find(teamToAdd);
  if (existingTeam==NULL)
    {
      // if no more room, grow array
      if (_count==_size)
	{
	  resize(_size*2);
	}

      // add element into partially filled array. 
      _collection[_count++]=teamToAdd;
    }
  else
    {
      existingTeam->wins()+=teamToAdd.wins();
      existingTeam->losses()+=teamToAdd.losses();
    }
  
  // duplicate "this" and return duplicate. 
  SoccerLeague *answerPtr = new SoccerLeague(*this);
  return *answerPtr;
}

// overoaded += to add a collection of SoccerTeams. 
const SoccerLeague&
SoccerLeague::operator+=(const SoccerLeague &other)
{
  // look at each team in the other (RHS) league ...
  for (int i=0; i<other._count; i++)
    operator+=(other._collection[i]); // try to add using += operator (above)

  // duplicate "this" and return duplicate
  SoccerLeague *answerPtr = new SoccerLeague(*this);
  return *answerPtr;
}

// overloaded -= to remove a team (if found in league).
const  SoccerLeague&
SoccerLeague::operator-=(const SoccerTeam &teamToDel)
{
  // return value. 
  SoccerLeague *ans = new SoccerLeague(); 

  // look at each SoccerTeam in LHS ("this") collection ...
  for(int pos=0; pos<_count; pos++)
    {
      // if current SoccerTeam is NOT the one we're trying to remove ... 
      if (teamToDel!=_collection[pos])
	{
	  // ... not trying to reomve this team, so it should be in result
	  *ans+=_collection[pos]; // again, using overlaoded += (see above)
	}
      else // team in original, and needs to be removed. 
	{
	  // move the team at the end into this slot ...
	  _collection[pos] = _collection[_count-1];

	  // we've removed one item, so filled count is one smaller. 
	  _count--;
	}
    }

  // return answer. 
  return *ans;
}

// overloaed operator=  (assignment)
const SoccerLeague&
SoccerLeague::operator=(const SoccerLeague & other)
{
  // we're killing everything in "this" (LHS), so number of filled is 0 to start
  _count=0;

  // take every SoccerTeam in other (RHS) collection
  for (int pos=0; pos < other._count; pos++)
    { 
      // add the SoccerTeam to the LHS (this)
      operator+=(other._collection[pos]);
    }

  // return the set we just modified. 
  return *this;
}

// overloaded -= to remove all items in another collection .
const SoccerLeague&
SoccerLeague::operator-=(const SoccerLeague &other)
{
  // return value
  SoccerLeague *answer = new SoccerLeague();

  // go through each SoccerTeam in RHS ...  
  for (int pos=0; pos<other._count;pos++)
    {
      // remove current SoccerTeam from LHS
      this->operator-=(other._collection[pos]);
    }

  // use overloaded = operator to copy this into return value.
  //    yes - could have just used copy constructor to do such instead. 
  *answer = *this;
  return *answer;
}

// empty the set .. or at least make it appear empty ... 
void
SoccerLeague::clear()
{
  // really easy. if we set _count to 0, all other methods see the
  //    collection as having no SoccerTeams ... 
  _count=0;
}

// print out to specified stream ... 
std::ostream&
SoccerLeague::print(std::ostream &os) const
{
  // look at each filled slot holding a SoccerTeam ...
  for (int i=0; i<_count; i++)
    {
      // print out the SoccerTeam ....
      os << _collection[i] << endl;
    }

  // return updated stream . 
  return os;
}

// overlaoded << for SoccerLeague
std::ostream& operator<<(std::ostream &os, const SoccerLeague &mc)
{
  // easy, sice we have a print method. 
  return mc.print(os);
}

