#include "Figures.h"
#include "Circle.h"

CurveSample * Circle::insert()
{
	CurveSample *p = new CurveSample;
	p->area = calculateArea();
	return p;
}

double Circle::calculateArea() {
	return PI * radius * radius;
}