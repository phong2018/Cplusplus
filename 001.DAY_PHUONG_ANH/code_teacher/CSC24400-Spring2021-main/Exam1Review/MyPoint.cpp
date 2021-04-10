#include "MyPoint.hpp"


using namespace std;

// cout << MyPoint
// 1st C++ tries:    cout.operator<<(MyPoint)   [fails]
// 2nd attempt:   operator<<(cout, MyPoint)     [see below]
ostream& operator<< (ostream &os, const MyPoint &mp)
{
	os << "(" << mp._xval << " , "
	   << mp._yval << ")";
	return os;
}


// a+b
//  1st C++ tries:   a.operator+(b)      [see below]
const MyPoint& 
MyPoint::operator+(const MyPoint &rhs) const
{
	MyPoint *answer = new MyPoint;
	
	answer->_xval = this->_xval + rhs._xval; 
	answer->_yval = this->_yval + rhs._yval; 
	
	return *answer;
}





