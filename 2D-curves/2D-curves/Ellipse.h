#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
private:
	double a, b;
public:
	Ellipse() { a = 0; b = 0; }
	Ellipse(double _a, double _b) { a = _a, b = _b; }
	TNote * Insert();
};