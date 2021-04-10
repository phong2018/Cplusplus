#include "triangle.h"

Triangle::Triangle():Shape()
{

}

float Triangle::area()
{
	return (get_height() * get_width() / 2);
}
