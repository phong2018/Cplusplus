#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
private:
	float width, height;

public:
	Shape();
	virtual float area();

	void set_width(float w);
	void set_height(float h);

	float get_width();
	float get_height();
};


#endif
