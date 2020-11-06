#pragma once
#include "Curve.h"

class Ellipse : public Curve
{
private:
	double height, width;
public:
	Ellipse() { height = 0; width = 0; }
	Ellipse(double height, double width) { this->height = height, this->width = width; }
	double calculateArea();
	std::unique_ptr<CurveSample> insert();
};