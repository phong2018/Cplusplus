#include "rectangle.h"


Rectangle::Rectangle():Shape()
{

}

float Rectangle::area()
{
	return get_height() * get_width();
}

