#pragma once
#include "Curve.h"

class Circle : public Curve
{
private:
	double radius;
public:
	Circle() { radius = 0; }
	Circle(double radius) { this->radius = radius; }
	double calculateArea();
	CurveSample * insert();
};