#pragma once
#include "Shape.h"
#include <math.h>

class Circle : public Shape
{
private:
	double radius;
public:
	Circle() { radius = 0; }
	Circle(double _r) { radius = _r; }
	TNote * Insert();
};