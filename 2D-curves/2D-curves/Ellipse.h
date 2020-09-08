#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
private:
	double a, b;
public:
	Ellipse() { a = 0; b = 0; }
	Ellipse(double a, double b) { this->a = a, this->b = b; }
	TNote * Insert();
};