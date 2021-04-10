
#include "SoccerLeague.hpp"
#include "SoccerTeam.hpp"
#include <fstream>
#include <string>
#include <Algorithm>
using namespace std;

//a default constructor that takes no arguments. This should simply make the league be capable
//of holding up to 5 teams, but initially holds zero teams.

//_array = new SoccerTeam[5];
/*I put 5 at first, but when I test run the playsoff, there are more than 5 elements, it didn't run, so I have to change
it to 50 to give more room.*/
SoccerLeague::SoccerLeague() {
    _array = new SoccerTeam[50];
    _currSize = 0;
}

/*2.  a constructor that takes a single argument of type iftsream . 
This constructor should read Team data from the input stream, 
adding as many teams as there are in the input stream to the collection. 
Each team in the input stream will be specified on 3 different lines, as follows:*/

SoccerLeague::SoccerLeague(ifstream& ifile) {
    _array = new SoccerTeam[50];
    _currSize = 0;
    string name, win, lose;

    while (getline(ifile, name)) {
        getline(ifile, win);
        getline(ifile, lose);
        if(win.empty()) break;
        SoccerTeam temp(name, stoi(win), stoi(lose));
        _array[_currSize] = temp;
        _currSize++;

    }
}

/*3- a constructor that takes a single argument of type iftsream . 
This constructor should read Team data from the input stream, 
adding as many teams as there are in the input stream to the collection. 
Each team in the input stream will be specified on 3 different lines, as follows
*/

SoccerLeague::SoccerLeague(SoccerLeague& obj) {
     
    _array = new SoccerTeam[50];
    _currSize = obj._currSize;
    for (int i = 0; i < obj._currSize; i++)
        _array[i] = obj._array[i];
}
//----
void SoccerLeague::printLeague() {

    for (int i = 0; i < _currSize; i++)
        cout << _array[i] << "\n";

}

//a method called clear that simply empties out the current league.
ostream& SoccerLeague::print(ostream& os) const
{
    for (int i = 0; i < _currSize; i++)
        os << _array[i] << "\n";
    return os;
}

 
/*the << operator should be overloaded for a SoccerLeague object. 
Remember that this method should return a reference to an object of type ostream*/


ostream& operator<< (ostream& os, const SoccerLeague& obj)
{
    return  obj.print(os);
    
}

void SoccerLeague::add(const SoccerTeam &toadd) {
    _array[_currSize] = toadd;
    _currSize++;
}



void SoccerLeague::operator+=(const SoccerTeam &otherteam) {
    add(otherteam);
}

void SoccerLeague::operator+=(const SoccerLeague &otherleague) {
    for (int i = 0; i < otherleague._currSize; i++) {
        //check notyet
        bool notyet = true;
        for(int j=0;j< _currSize;j++)
            if (otherleague._array[i] == _array[j]) { notyet = false; break; }

        //if notyet==true
        if(notyet) add(otherleague._array[i]);
    }
}
SoccerLeague SoccerLeague::operator+(const SoccerLeague& other) const
{
    SoccerLeague result;//ab=a+b
    result += other;
    //-----to retrieve each team of the current league
    for (int i = 0; i < _currSize; i++) { 
        //check notyet
        bool notyet = true;

        //check if the team is in the result
        for (int j = 0; j < result._currSize; j++)  
            if (result._array[j] == _array[i]) { notyet = false; break; }

        //if notyet==true
        if (notyet) result.add(_array[i]);
    }
    return result;

}

 
//got the index wrong so the result doesn't match.
SoccerLeague SoccerLeague::operator/(const SoccerLeague &other) const
{
    SoccerLeague result;//ab=a/b
    //retrieve each team of the league
    
    for (int i = 0; i < _currSize; i++) { 
        //check to see if the current team in the result yet
        for (int j = 0; j < other._currSize; j++) //kim tra xem team co trong result chua 
        if (other._array[j] == _array[i]) { 
            SoccerTeam temp(_array[i].name(), _array[i].wins()+ other._array[j].wins(), _array[i].losses() + other._array[j].losses());
            result.add(temp);
        }
 
    }
    return result;

}


//the -= operator should be overloaded with the right hand side being a single SoccerTeam.
void SoccerLeague::removeTeam(const SoccerTeam& toRemove) {
    for (int j = 0; j < _currSize; j++) //kim tra xem team co trong result chua 
    if (_array[j] == toRemove) {
        _array[j] = _array[_currSize - 1];
        _currSize--;
        break;
    }

}

void SoccerLeague::operator-=(const SoccerTeam& otherteam) {
    removeTeam(otherteam);
}


//the -= operator should also be overloaded with the right hand side being another SoccerLeague.
void SoccerLeague::operator-=(const SoccerLeague& otherleague) {
    for (int i = 0; i < otherleague._currSize; i++) {
        removeTeam(otherleague._array[i]);
    }
}

//a method called clear that simply empties out the current league.
void SoccerLeague::clear() {
    _currSize = 0;
}