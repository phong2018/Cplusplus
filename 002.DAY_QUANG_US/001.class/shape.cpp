#include "shape.h"

Shape::Shape()
{
		width = 0;
		height = 0;
}

float Shape::area()
{
	return 0;
}

void Shape::set_width(float w)
{
	if (w > 0){
		width = w;
	}
	else{
		std::cout << "Invalid value for the width: " << w << std::endl;
	}
}

void Shape::set_height(float h)
{
	if (h > 0){
		height = h;
	}
	else{
		std::cout << "Invalid value for the height: " << h << std::endl;
	}
}

float Shape::get_width()
{
	return width;
}

float Shape::get_height()
{
	return height;
}
