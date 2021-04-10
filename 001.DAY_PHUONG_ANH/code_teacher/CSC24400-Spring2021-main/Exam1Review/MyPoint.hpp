#ifndef _MYPOINT_HPP_
#define _MYPOINT_HPP_

#include <iostream>


class MyPoint
{
private:
	double _xval;
	double _yval;
public:
	MyPoint() : _xval(0), _yval(0) {}
	MyPoint(double x, double y) : _xval(x), _yval(y) {}
	
	double getX() const {return _xval;}
	double& getX() {return _xval;}

	// a+b   ->   a.operator+(b);	
	const MyPoint& operator+(const MyPoint &rhs) const;
	
	//std::ostream& operator<<(std::ostream &os) const;
	friend std::ostream& 
	operator<< (std::ostream &os, const MyPoint &mp);
};






#endif
