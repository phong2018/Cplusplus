#include <iostream>

#include "MyPoint.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	MyPoint origin, notOrigin(3.14, 2.72);
	
	cout << "origin = " << origin << endl;
	cout << "not origin = " << notOrigin << endl;
	
	
	notOrigin.getX() = -5;
	cout << "notOrigin's x = " << notOrigin.getX() << endl;
	
	origin.getX()=77;
	
	MyPoint mySum;
	mySum = origin + notOrigin;
	
	cout << "sum is " << mySum << endl;
	
	return 0;
}
