#include "Figures.h"
#include "Ellipse.h"


std::unique_ptr<CurveSample> Ellipse::insert()
{
	auto p = std::make_unique<CurveSample>();
	p->area = calculateArea();
	return p;
}

double Ellipse::calculateArea() {
	return  PI * height * width;
}