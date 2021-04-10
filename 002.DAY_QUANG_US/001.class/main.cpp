/*
26.1 Classes
In this exercise, you will see how virtual functions can be used to achieve polymorphism. The main function has already been written for you.

First, write a class called Shape with the following public functions:

virtual float area(), which returns by default 0
void set_width(float w), to set the width
void set_height(float h), to set the height
float get_width(), get the setted width
float get_height(), get the setted height
Now, write a class called Triangle that will inherit from the Shape class with the following public functions:

float area(), calculates the area for the Triangle, and returns value
Write another class called Rectangle that will also inherit from the Shape class with the following public functions:

float area(), calculates the area for the Rectangle, and returns value
Notice, we are overriding the float area() function of the base class, which is a virtual function that uses the polymorphism feature of classes.

Finally, write the main function which will generate the output. First, create a pointer type object for the base class, then set the object of the inherited class to the pointer object of the base class.

You see we are accessing to the base class setwidth(), and setheight() using the derived class object. This is the uses of the inheritance.

The generated output should be exactly the same as the provided template.
*/

#include <iostream>
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;


int main()
{
	float width, height;

	cin >> width;
	cin >> height;

	Shape *shape;

	Triangle tri;
	tri.set_height(height);
	tri.set_width(width);

	shape = &tri;
	cout << "area of triangle: " << shape->area() << std::endl;

	Rectangle  rec;
	rec.set_height(height);
	rec.set_width(width);

	shape = &rec;
	cout << "area of rectangle: " << shape->area() << std::endl;

	return 0;
}

