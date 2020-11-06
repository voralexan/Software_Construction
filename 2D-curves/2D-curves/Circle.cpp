#include "Figures.h"
#include "Circle.h"

std::unique_ptr<CurveSample> Circle::insert()
{
	auto p = std::make_unique<CurveSample>();
	p->area = calculateArea();
	return p;
}

double Circle::calculateArea() {
	return PI * radius * radius;
}